/**************************************************************************//**
 * @main_radio14.c
 * @brief This project configures opamp 0 as a non-inverting amplifier whose
 * gain is given by the following equation: Vout = Vin * (1 + R2/R1).
 * By default, this project selects the R2/R1 resistor
 * ladder ratio to be R2 = R1. This results in Vout = Vin * 2. This project also
 * configures the ADC to receive input on the same pin the opamp is outputting
 * to so that the user can enter debug mode to check the ADC conversion of the
 * opamp output.
 * @version 0.0.1
 ******************************************************************************
 * @section License
 * <b>Copyright 2018 Silicon Labs, Inc. http://www.silabs.com</b>
 *******************************************************************************
 *
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 *
 ******************************************************************************/

#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_opamp.h"
#include "em_adc.h"
#include "em_gpio.h"
#include "em_usart.h"
#include "em_prs.h"
#include "em_ldma.h"
#include "em_letimer.h"

// Note: change this to one of the OPAMP_ResSel_TypeDef type defines to select
//       the R2/R1 resistor ladder ratio. By default this is R2 = R1. This
//       results in Vout = Vin * 2
#define RESISTOR_SELECT opaResSelR2eqR1


#define ADC_BUFFER_SIZE 8

// Change this to set how many samples get sent at once
#define ADC_DVL         2

// Init to max ADC clock for Series 1 with AUXHFRCO
#define ADC_FREQ        4000000

// Desired letimer interrupt frequency (in Hz)
#define letimerDesired  16000

#define LDMA_CHANNEL    0
#define PRS_CHANNEL     0

// Note: These aren't necessary and are only provided so that they can be viewed
// in the debugger. Additionally they are declared as volatile so that they
// won't be optimized out by the compiler
static volatile uint32_t sample;
static volatile uint32_t millivolts;

static volatile bool txFlag = 0;

// Buffer for ADC single and scan conversion
uint32_t adcBuffer[ADC_BUFFER_SIZE];
uint32_t adcBuffer2[ADC_BUFFER_SIZE];
uint32_t *active_buffer = NULL;
uint32_t topValue;
LDMA_TransferCfg_t trans;
LDMA_Descriptor_t descr;
LDMA_Descriptor_t description [2];


volatile int temp;

/**************************************************************************//**
 * @brief LDMA Handler
 *****************************************************************************/
void LDMA_IRQHandler(void)
{
  // Clear interrupt flag
  LDMA_IntClear((1 << LDMA_CHANNEL) << _LDMA_IFC_DONE_SHIFT);
  txFlag = 1;
}

/**************************************************************************//**
 * @brief LETIMER initialization
 *****************************************************************************/
void initLetimer(void)
{
  // Start LFRCO and wait until it is stable
  CMU_OscillatorEnable(cmuOsc_LFRCO, true, true);

  // Enable clock to the interface of the low energy modules
  CMU_ClockEnable(cmuClock_HFLE, true);

  // Route the LFRCO clock to LFA (TIMER0)
  CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFRCO);

  // Enable clock for LETIMER0
  CMU_ClockEnable(cmuClock_LETIMER0, true);

  LETIMER_Init_TypeDef letimerInit = LETIMER_INIT_DEFAULT;

  // Reload COMP0 on underflow, pulse output, and run in repeat mode
  letimerInit.comp0Top  = true;
  letimerInit.ufoa0     = letimerUFOAPulse;
  letimerInit.repMode   = letimerRepeatFree;

  // Initialize LETIMER
  LETIMER_Init(LETIMER0, &letimerInit);

  // Need REP0 != 0 to pulse on underflow
  LETIMER_RepeatSet(LETIMER0, 0, 1);

  // calculate the topValue
   topValue = CMU_ClockFreqGet(cmuClock_LETIMER0) / letimerDesired;

  // Compare on wake-up interval count
  LETIMER_CompareSet(LETIMER0, 0, topValue);

  // Use LETIMER0 as async PRS to trigger ADC in EM2
  CMU_ClockEnable(cmuClock_PRS, true);

  PRS_SourceAsyncSignalSet(PRS_CHANNEL, PRS_CH_CTRL_SOURCESEL_LETIMER0,
      PRS_CH_CTRL_SIGSEL_LETIMER0CH0);
}

/**************************************************************************//**
 * @brief LDMA initialization
 *****************************************************************************/
void initLdma(void)
{

  // Enable CMU clock
  CMU_ClockEnable(cmuClock_LDMA, true);

  // Basic LDMA configuration
  LDMA_Init_t ldmaInit = LDMA_INIT_DEFAULT;

  LDMA_Init(&ldmaInit);

  // Transfers trigger off ADC single conversion complete
  trans = (LDMA_TransferCfg_t)LDMA_TRANSFER_CFG_PERIPHERAL(ldmaPeripheralSignal_ADC0_SINGLE);

  description [0]= (LDMA_Descriptor_t)LDMA_DESCRIPTOR_LINKREL_P2M_WORD(
      &(ADC0->SINGLEDATA),  // source
      adcBuffer,            // destination
      ADC_BUFFER_SIZE,      // data transfer size
      1);                   // link relative offset (links to self)

  description[0].xfer.blockSize =ADC_DVL-1;    // transfers ADC_DVL number of units per arbitration cycle
  description[0].xfer.ignoreSrec = true;       // ignores single requests to save energy


  description [1]= (LDMA_Descriptor_t)LDMA_DESCRIPTOR_LINKREL_P2M_WORD(
      &(ADC0->SINGLEDATA),  // source
      adcBuffer2,            // destination
      ADC_BUFFER_SIZE,      // data transfer size
      -1);                   // link relative offset (links to self)

  description[1].xfer.blockSize =ADC_DVL-1;    // transfers ADC_DVL number of units per arbitration cycle
  description[1].xfer.ignoreSrec = true;       // ignores single requests to save energy

  active_buffer = (int*)(LDMA_BASE + 0x094);
  // Initialize transfer
  LDMA_StartTransfer(LDMA_CHANNEL, &trans, &description);

  // Clear pending and enable interrupts for LDMA
  NVIC_ClearPendingIRQ(LDMA_IRQn);
  NVIC_EnableIRQ(LDMA_IRQn);



  /*
  // Enable CMU clock
  CMU_ClockEnable(cmuClock_LDMA, true);

  // Basic LDMA configuration
  LDMA_Init_t ldmaInit = LDMA_INIT_DEFAULT;

  LDMA_Init(&ldmaInit);

  // Transfers trigger off ADC single conversion complete
  trans = (LDMA_TransferCfg_t)LDMA_TRANSFER_CFG_PERIPHERAL(ldmaPeripheralSignal_ADC0_SINGLE);

  descr = (LDMA_Descriptor_t)LDMA_DESCRIPTOR_LINKREL_P2M_WORD(
      &(ADC0->SINGLEDATA),  // source
      adcBuffer,            // destination
      ADC_BUFFER_SIZE,      // data transfer size
      0);                   // link relative offset (links to self)

  descr.xfer.blockSize =ADC_DVL-1;    // transfers ADC_DVL number of units per arbitration cycle
  descr.xfer.ignoreSrec = true;       // ignores single requests to save energy

  // Initialize transfer
  LDMA_StartTransfer(LDMA_CHANNEL, &trans, &descr);

  // Clear pending and enable interrupts for LDMA
  NVIC_ClearPendingIRQ(LDMA_IRQn);
  NVIC_EnableIRQ(LDMA_IRQn);*/
}




/**************************************************************************//**
 * @brief
 *    Initialize ADC
 *****************************************************************************/
void initAdc(void)
{
  // Enable ADC clock
  /*CMU_ClockEnable(cmuClock_ADC0, true);

  // Initialize the ADC
  ADC_Init_TypeDef init = ADC_INIT_DEFAULT;
  init.timebase = ADC_TimebaseCalc(0);           // Make sure timebase is at least 1 microsecond
  init.prescale = ADC_PrescaleCalc(16000000, 0); // Init to max ADC clock for Series 1
  ADC_Init(ADC0, &init);

  // Set the ADC to use single ended mode
  ADC_InitSingle_TypeDef initSingle = ADC_INITSINGLE_DEFAULT;
  initSingle.diff       = 0;                   // Single ended
  initSingle.reference  = adcRef2V5;           // Internal 2.5V reference
  initSingle.resolution = adcRes12Bit;         // 12-bit resolution
  initSingle.acqTime    = adcAcqTime4;  // set acquisition time to meet minimum requirement
  initSingle.posSel     = adcPosSelAPORT1YCH7; // Choose input to ADC to be on P
  ADC_InitSingle(ADC0, &initSingle);*/


  ADC_Init_TypeDef init = ADC_INIT_DEFAULT;
  ADC_InitSingle_TypeDef initSingle = ADC_INITSINGLE_DEFAULT;

  // Enable ADC clock
  CMU_ClockEnable(cmuClock_HFPER, true);
  CMU_ClockEnable(cmuClock_ADC0, true);

  // Select AUXHFRCO for ADC ASYNC mode so it can run in EM2
  CMU->ADCCTRL = CMU_ADCCTRL_ADC0CLKSEL_AUXHFRCO;

  // Set AUXHFRCO frequency and use it to setup the ADC
  CMU_AUXHFRCOFreqSet(cmuAUXHFRCOFreq_4M0Hz);
  init.timebase = ADC_TimebaseCalc(CMU_AUXHFRCOBandGet());
  init.prescale = ADC_PrescaleCalc(ADC_FREQ, CMU_AUXHFRCOBandGet());

  // Let the ADC enable its clock in EM2 when necessary
  init.em2ClockConfig = adcEm2ClockOnDemand;
  // DMA is available in EM2 for processing SINGLEFIFO DVL request
  initSingle.singleDmaEm2Wu = 1;

  // Add external ADC input. See README for corresponding EXP header pin.
  initSingle.posSel = adcPosSelAPORT4XCH11;

  // Basic ADC single configuration
  initSingle.diff = false;              // single-ended
  initSingle.reference  = adcRef2V5;    // 2.5V reference
  initSingle.resolution = adcRes12Bit;  // 12-bit resolution
  initSingle.acqTime    = adcAcqTime4;  // set acquisition time to meet minimum requirements

  // Enable PRS trigger and select channel 0
  initSingle.prsEnable = true;
  initSingle.prsSel = (ADC_PRSSEL_TypeDef) PRS_CHANNEL;

  // Initialize ADC
  ADC_Init(ADC0, &init);
  ADC_InitSingle(ADC0, &initSingle);

  // Set single data valid level (DVL)
  ADC0->SINGLECTRLX = (ADC0->SINGLECTRLX & ~_ADC_SINGLECTRLX_DVL_MASK) | (((ADC_DVL - 1) << _ADC_SINGLECTRLX_DVL_SHIFT) & _ADC_SINGLECTRLX_DVL_MASK);

  // Clear the Single FIFO
  ADC0->SINGLEFIFOCLEAR = ADC_SINGLEFIFOCLEAR_SINGLEFIFOCLEAR;

}


void initUSART (void)
{

  USART_InitAsync_TypeDef init = USART_INITASYNC_DEFAULT;
  CMU_ClockEnable(cmuClock_USART1, true);
  CMU_ClockEnable(cmuClock_GPIO, true);
  //init.databits = usartDatabits16;

  GPIO_PinModeSet(gpioPortC, 6, gpioModePushPull, 1);
  USART_InitAsync(USART1, &init);
  USART1->ROUTELOC0 = USART_ROUTELOC0_RXLOC_LOC11 | USART_ROUTELOC0_TXLOC_LOC11;
  USART1->ROUTEPEN |= USART_ROUTEPEN_TXPEN | USART_ROUTEPEN_RXPEN;
}

/**************************************************************************//**
 * @brief
 *    Initialize OPAMP
 *****************************************************************************/
void initOpamp(void)
{
  // Enable the VDAC clock for accessing the opamp registers
  CMU_ClockEnable(cmuClock_VDAC0, true); // Enable VDAC clock

  // Configure OPA0
  OPAMP_Init_TypeDef init = OPA_INIT_NON_INVERTING;
  init.resInMux = opaResInMuxVss;       // Set the input to the resistor ladder to VSS
  init.resSel   = opaResSelR2eq0_33R1;      // Choose the resistor ladder ratio
  init.posSel   = opaPosSelAPORT4XCH11;  // Choose opamp positive input to come from P
  init.outMode  = opaOutModeAPORT1YCH7; // Route opamp output to P
  // Enable OPA0
  OPAMP_Enable(VDAC0, OPA0, &init);
  /*
  // Configure OPA0
  OPAMP_Init_TypeDef init0 = OPA_INIT_CASCADED_INVERTING_OPA0;
  init0.resSel   = opaResSelR2eq0_33R1;      // Choose the resistor ladder ratio
  init0.posSel   = opaPosSelAPORT4XCH11;  // Choose opamp positive input to come from PC8
  init0.outMode = opaOutModeAPORT1YCH1; // Route opamp output to PA1
  init0.resInMux = opaResInMuxNegPad;    // Route negative pad to resistor ladder

  // Configure OPA1
  OPAMP_Init_TypeDef init1 = OPA_INIT_CASCADED_INVERTING_OPA1;
  init1.resSel  = opaResSelR2eq0_33R1;      // Choose the resistor ladder ratio
  init1.posSel  = opaPosSelOpaIn;  // Choose opamp positive input to come from PC9
  init1.resInMux = opaResInMuxNegPad;    // Route negative pad to resistor ladder
  init1.outMode = opaOutModeAPORT1YCH7; // Route opamp output to PA1
  /*
  OPAMP_Init_TypeDef init0 = OPA_INIT_CASCADED_NON_INVERTING_OPA0;
  init0.resSel   = opaResSelR2eq0_33R1;      // Choose the resistor ladder ratio
  init0.resInMux = opaResInMuxVss;       // Set the input to the resistor ladder to VSS
  init0.posSel   = opaPosSelAPORT1XCH6;  // Choose opamp positive input to come from PC6

  // Configure OPA1
  OPAMP_Init_TypeDef init1 = OPA_INIT_CASCADED_NON_INVERTING_OPA1;
  init1.resSel   = opaResSelR2eq0_33R1;      // Choose the resistor ladder ratio
  init1.resInMux = opaResInMuxVss;       // Set the input to the resistor ladder to VSS
  init1.posSel   = opaPosSelOpaIn;       // Choose opamp positive input to come from OPA0
  init1.outMode  = opaOutModeAPORT1YCH7; // Route opamp output to PC7


  // Enable OPA0 and OPA1
  OPAMP_Enable(VDAC0, OPA0, &init0);
  OPAMP_Enable(VDAC0, OPA1, &init1);*/
}

/**************************************************************************//**
 * @brief
 *    Main function
 *
 * @details
 *    No signals are explicitly selected for the negative and positive inputs
 *    of the opamp because the default OPA_INIT_NON_INVERTING_OPA0 macro
 *    already takes care of routing the resistor ladder tap to the negative
 *    input and since there is only one available choice for the positive
 *    input it also takes care of that already.
 *
 * @note
 *    opamp configuration (either by setting RESINMUX to VSS or by setting
 *    The input to the resistor ladder must be set to ground for a non-inverting
 *    RESINMUX to NEGPAD and then connecting the negative pad (in this case
 *    OPAMP_N0) to ground.
 *****************************************************************************/
int main(void)
{
  // Chip errata
  CHIP_Init();

  // Initialize the ADC and OPAMP
  initAdc();
  //initOpamp();
  initUSART();
  // Setup DMA to move ADC results to user memory
  initLdma();
  // Set up LETIMER to trigger ADC via PRS in 500ms intervals
  initLetimer();

  while (1)
    {
      /*
    // Start the ADC conversion
    ADC_Start(ADC0, adcStartSingle);

    // Wait for conversion to complete
    while(!(ADC0->STATUS & _ADC_STATUS_SINGLEDV_MASK));

    // Get ADC result
    sample = ADC_DataSingleGet(ADC0);

    // Calculate input voltage in mV
    // mV = (sample * 2.5Vref * 1000) / (2^12 bit resolution)
    millivolts = (sample * 2500) / 4096;
    USART_Tx(USART1, millivolts);
    USART_Tx(USART1, '\n');
  */
      if (txFlag)
      {
          int r = adcBuffer [1] & 0xff;
          int g = (adcBuffer [1] >> 8) & 0xff;

          USART_Tx(USART1, g);
          USART_Tx(USART1, r);

          txFlag = 0;
      }
  }
}

