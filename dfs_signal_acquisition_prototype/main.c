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

//must be even for DMA to divide in half
#define ADC_BUFFER_SIZE 128

// Change this to set how many samples get sent at once
#define ADC_DVL         2

// Init to max ADC clock for Series 1 with AUXHFRCO
#define ADC_FREQ        4000000

// Desired letimer interrupt frequency (in Hz)
#define letimerDesired  32000

#define LDMA_CHANNEL    0
#define PRS_CHANNEL     0

// Note: These aren't necessary and are only provided so that they can be viewed
// in the debugger. Additionally they are declared as volatile so that they
// won't be optimized out by the compiler
volatile int temp = 0, temp1 = 0;

//Pointer to the source destination that the application layer code writes from
volatile uint32_t * volatile txDestination = 0;

// Buffer for ADC single and scan conversion
volatile uint32_t adcBuffer[ADC_BUFFER_SIZE];

//DMA initialization structures
LDMA_TransferCfg_t trans;
LDMA_Descriptor_t descr;
LDMA_Descriptor_t description [2];

//Will be set as the halfway point of adcBuffer
volatile uint32_t *buffer_address = NULL;
//The buffer the DMA is actively writing too
volatile uint32_t *active_buffer = NULL;


/**************************************************************************//**
 * @brief LDMA Handler
 *****************************************************************************/
void LDMA_IRQHandler(void)
{
  // Clear interrupt flag
  LDMA_IntClear((1 << LDMA_CHANNEL) << _LDMA_IFC_DONE_SHIFT);
  //Check if the application layer code is done with transmitting
  //If not, don't change txDestination
  if (txDestination)
    {
      temp++;
      return;
    }
  //Check if the buffer the DMA is actively writing too is the starting point or half way point
  //Give the application layer code the idle half (not active_buffer)
  uint32_t a = *active_buffer;
  uint32_t b = (int)(void*)buffer_address;
  if (a < b)
    {
    txDestination = (void*)buffer_address;
    //temp1++;
    }
  else
    {
    //In C, array indexes increment by 4 not 1, so the difference must be multiplied by 4
    txDestination = ((void*)buffer_address -(int)(ADC_BUFFER_SIZE / 2) * 4);
    //temp++;
    }
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
  uint32_t topValue = CMU_ClockFreqGet(cmuClock_LETIMER0) / letimerDesired;

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
  // Set buffer_address to the half way point of adcBuffer to setup ping pong DMA
  buffer_address = &(adcBuffer[ADC_BUFFER_SIZE / 2]);

  LDMA_Init(&ldmaInit);

  // Transfers trigger off ADC single conversion complete
  trans = (LDMA_TransferCfg_t)LDMA_TRANSFER_CFG_PERIPHERAL(ldmaPeripheralSignal_ADC0_SINGLE);

  description [0]= (LDMA_Descriptor_t)LDMA_DESCRIPTOR_LINKREL_P2M_WORD(
      &(ADC0->SINGLEDATA),  // source is from ADC sample
      adcBuffer,            // destination is the shared buffer between application layer and DMA
      ADC_BUFFER_SIZE / 2,      // data transfer size is half the buffer size
      1);                   // link relative offset (links to next half)

  description[0].xfer.blockSize =ADC_DVL-1;    // transfers ADC_DVL number of units per arbitration cycle
  description[0].xfer.ignoreSrec = true;       // ignores single requests to save energy


  description [1]= (LDMA_Descriptor_t)LDMA_DESCRIPTOR_LINKREL_P2M_WORD(
      &(ADC0->SINGLEDATA),  // source is from ADC sample
      buffer_address,            // destination is the shared buffer between application layer and DMA
      ADC_BUFFER_SIZE / 2,      // data transfer size is half the buffer size
      -1);                   // link relative offset (links to previous half)

  description[1].xfer.blockSize =ADC_DVL-1;    // transfers ADC_DVL number of units per arbitration cycle
  description[1].xfer.ignoreSrec = true;       // ignores single requests to save energy

  //There are 2 pointer warnings here but it works
  //Set active_buffer address to the active buffer register, 0x094 offset is from the datasheet
  active_buffer = (int*)(LDMA_BASE + 0x094);
  // Initialize transfer
  LDMA_StartTransfer(LDMA_CHANNEL, &trans, &description);

  // Clear pending and enable interrupts for LDMA
  NVIC_ClearPendingIRQ(LDMA_IRQn);
  NVIC_EnableIRQ(LDMA_IRQn);
}




/**************************************************************************//**
 * @brief
 *    Initialize ADC
 *****************************************************************************/
void initAdc(void)
{
  // Default initialization structure
  ADC_Init_TypeDef init = ADC_INIT_DEFAULT;
  ADC_InitSingle_TypeDef initSingle = ADC_INITSINGLE_DEFAULT;

  //Not sure if keeping the ADC warm, worth testing to see if it speeds up sampling time
  //init.warmUpMode = adcWarmupKeepADCWarm;

  // Enable ADC clock
  CMU_ClockEnable(cmuClock_HFPER, true);
  CMU_ClockEnable(cmuClock_ADC0, true);

  // Select AUXHFRCO for ADC ASYNC mode so it can run in EM2
  CMU->ADCCTRL = CMU_ADCCTRL_ADC0CLKSEL_AUXHFRCO;

  // Set AUXHFRCO frequency and use it to setup the ADC
  //Need to understand why the ADC fails past 7MHz, could be because of EM2 power constraints?
  CMU_AUXHFRCOFreqSet(cmuAUXHFRCOFreq_7M0Hz);
  init.timebase = ADC_TimebaseCalc(CMU_AUXHFRCOBandGet());
  init.prescale = ADC_PrescaleCalc(ADC_FREQ, CMU_AUXHFRCOBandGet());

  // Let the ADC enable its clock in EM2 when necessary
  init.em2ClockConfig = adcEm2ClockOnDemand;
  // DMA is available in EM2 for processing SINGLEFIFO DVL request
  initSingle.singleDmaEm2Wu = 1;

  // Add external ADC input. See README for corresponding EXP header pin.
  initSingle.posSel = adcPosSelAPORT1YCH7;
  //Differential vs single doesn't seem to do anything since VSS is ground
  initSingle.negSel = adcPosSelVSS;


  // Basic ADC single configuration
  initSingle.diff = true;              // single-ended
  //Adjust to be lower based on the max input signal after op-amp gains
  initSingle.reference  = adcRef2V5;    // 2.5V reference
  initSingle.resolution = adcRes12Bit;  // 12-bit resolution
  //Faster acquisition times are necessary to meet sampling frequency requirements, especially when OVS is active
  initSingle.acqTime    = adcAcqTime1;  // set acquisition time to meet minimum requirements
  //init.ovsRateSel = adcOvsRateSel16;

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

/**************************************************************************//**
 * @brief
 *    Initialize UART
 *****************************************************************************/
void initUSART (void)
{
  //Default UART structure
  USART_InitAsync_TypeDef init = USART_INITASYNC_DEFAULT;
  //UART clock config
  CMU_ClockEnable(cmuClock_USART1, true);
  CMU_ClockEnable(cmuClock_GPIO, true);
  //Rate at which bits are transmitted. Receiving end must match
  init.baudrate = 400000;
  //Pin C6 is Pin 4 (SPI_MOSI) on the expansion header for the eval board
  GPIO_PinModeSet(gpioPortC, 6, gpioModePushPull, 1);
  USART_InitAsync(USART1, &init);
  USART1->ROUTELOC0 = USART_ROUTELOC0_RXLOC_LOC11 | USART_ROUTELOC0_TXLOC_LOC11;
  USART1->ROUTEPEN |= USART_ROUTEPEN_TXPEN | USART_ROUTEPEN_RXPEN;
  //uint32_t uart_idle = USART1->STATUS & USART_STATUS_TXIDLE;

}

/**************************************************************************//**
 * @brief
 *    Initialize OPAMP
 *****************************************************************************/
void initOpamp(void)
{
  /** Single Non-Inverting Op-Amp */

  // Enable the VDAC clock for accessing the opamp registers
  CMU_ClockEnable(cmuClock_VDAC0, true); // Enable VDAC clock
  // Configure OPA0
  OPAMP_Init_TypeDef init = OPA_INIT_NON_INVERTING;
  init.resInMux = opaResInMuxVss;       // Set the input to the resistor ladder to VSS
  init.resSel   = opaResSelR2eq0_33R1;      // Choose the resistor ladder ratio
  init.posSel   = opaPosSelAPORT4XCH11;  // Choose opamp positive input to come from P
  init.outMode  = opaOutModeAPORT1YCH7; // Route opamp output to P
  // Enable OPA0
  OPAMP_Enable(VDAC0, OPA0, &init);  /*
 */

  /** Cascaded Inverting Op-Amps */
  /*
  // Configure OPA0
  OPAMP_Init_TypeDef init0 = OPA_INIT_CASCADED_INVERTING_OPA0;
  init0.resSel   = opaResSelR2eq0_33R1;      // Choose the resistor ladder ratio
  init0.posSel   = opaPosSelAPORT4XCH11;  // Choose opamp positive input to come from PC8
//init0.outMode = opaOutModeAPORT1YCH1; // Route opamp output to PA1
  init0.resInMux = opaResInMuxNegPad;    // Route negative pad to resistor ladder

  // Configure OPA1
  OPAMP_Init_TypeDef init1 = OPA_INIT_CASCADED_INVERTING_OPA1;
  init1.resSel  = opaResSelR2eq0_33R1;      // Choose the resistor ladder ratio
  init1.posSel  = opaPosSelOpaIn;  // Choose opamp positive input to come from PC9
  init1.resInMux = opaResInMuxNegPad;    // Route negative pad to resistor ladder
  init1.outMode = opaOutModeAPORT1YCH7; // Route opamp output to PA1
  */

  /** Cascaded Non-Inverting Op-Amps */
  /*
  OPAMP_Init_TypeDef init0 = OPA_INIT_CASCADED_NON_INVERTING_OPA0;
  init0.resSel   = opaResSelR2eqR1;      // Choose the resistor ladder ratio
  init0.resInMux = opaResInMuxNegPad;       // Set the input to the resistor ladder to VSS
  init0.posSel   = opaPosSelAPORT4XCH11;
  //init0.outMode = opaOutModeAll;

  // Configure OPA1
  OPAMP_Init_TypeDef init1 = OPA_INIT_CASCADED_NON_INVERTING_OPA1;
  init1.resSel   = opaResSelR2eqR1;      // Choose the resistor ladder ratio
  init1.resInMux = opaResInMuxVss;       // Set the input to the resistor ladder to VSS
  init1.posSel   = opaPosSelOpaIn;       // Choose opamp positive input to come from OPA0
  init1.outMode  = opaOutModeAPORT1YCH7;
  */

  /** Cascaded Op-Amps */
  /*
  // Enable OPA0 and OPA1
  OPAMP_Enable(VDAC0, OPA0, &init0);
  OPAMP_Enable(VDAC0, OPA1, &init1);
  */

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
  initOpamp();
  // Initialize the UART to transmit ddata
  initUSART();
  // Setup DMA to move ADC results to user memory
  initLdma();
  // Set up LETIMER to trigger ADC via PRS at specified frequency
  initLetimer();


  while (1)
    {
      if (txDestination)
      {
          for (int i = 0; i < ADC_BUFFER_SIZE / 2; i++)
            {
              USART_TxDouble (USART1, txDestination[i]);
            }
          txDestination = 0;
      }
  }
}

