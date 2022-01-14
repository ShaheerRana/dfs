################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Co-op\ Shaheeer\ R/peripheral_examples/series1/adc/adc_single_prs_gpio_dma/src/main_tg11.c 

OBJS += \
./src/main_tg11.o 

C_DEPS += \
./src/main_tg11.d 


# Each subdirectory must supply rules for building sources it contributes
src/main_tg11.o: C:/Users/Co-op\ Shaheeer\ R/peripheral_examples/series1/adc/adc_single_prs_gpio_dma/src/main_tg11.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32FG14P233F256GM48=1' -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32FG14P/Include" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/drivers" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/bsp" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:\SiliconLabs\SimplicityStudio\v5\developer\toolchains\gnu_arm\10.2_2020q4\/arm-none-eabi/include" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"src/main_tg11.d" -MT"src/main_tg11.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


