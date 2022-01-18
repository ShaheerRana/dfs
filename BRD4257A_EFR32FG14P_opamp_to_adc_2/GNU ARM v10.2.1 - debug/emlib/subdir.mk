################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Co-op\ Shaheeer\ R/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_adc.c \
C:/Users/Co-op\ Shaheeer\ R/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_cmu.c \
C:/Users/Co-op\ Shaheeer\ R/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_core.c \
C:/Users/Co-op\ Shaheeer\ R/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_emu.c \
C:/Users/Co-op\ Shaheeer\ R/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_opamp.c \
C:/Users/Co-op\ Shaheeer\ R/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_system.c 

OBJS += \
./emlib/em_adc.o \
./emlib/em_cmu.o \
./emlib/em_core.o \
./emlib/em_emu.o \
./emlib/em_opamp.o \
./emlib/em_system.o 

C_DEPS += \
./emlib/em_adc.d \
./emlib/em_cmu.d \
./emlib/em_core.d \
./emlib/em_emu.d \
./emlib/em_opamp.d \
./emlib/em_system.d 


# Each subdirectory must supply rules for building sources it contributes
emlib/em_adc.o: C:/Users/Co-op\ Shaheeer\ R/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_adc.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32FG14P233F256GM48=1' -I"C:/Users/Co-op Shaheeer R/hardware/kit/EFR32FG14_BRD4257A/config" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/EFR32FG14_BRD4257A/config" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/bsp" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/drivers" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32FG14P/Include" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"emlib/em_adc.d" -MT"emlib/em_adc.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_cmu.o: C:/Users/Co-op\ Shaheeer\ R/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_cmu.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32FG14P233F256GM48=1' -I"C:/Users/Co-op Shaheeer R/hardware/kit/EFR32FG14_BRD4257A/config" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/EFR32FG14_BRD4257A/config" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/bsp" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/drivers" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32FG14P/Include" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"emlib/em_cmu.d" -MT"emlib/em_cmu.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_core.o: C:/Users/Co-op\ Shaheeer\ R/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_core.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32FG14P233F256GM48=1' -I"C:/Users/Co-op Shaheeer R/hardware/kit/EFR32FG14_BRD4257A/config" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/EFR32FG14_BRD4257A/config" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/bsp" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/drivers" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32FG14P/Include" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"emlib/em_core.d" -MT"emlib/em_core.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_emu.o: C:/Users/Co-op\ Shaheeer\ R/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_emu.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32FG14P233F256GM48=1' -I"C:/Users/Co-op Shaheeer R/hardware/kit/EFR32FG14_BRD4257A/config" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/EFR32FG14_BRD4257A/config" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/bsp" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/drivers" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32FG14P/Include" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"emlib/em_emu.d" -MT"emlib/em_emu.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_opamp.o: C:/Users/Co-op\ Shaheeer\ R/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_opamp.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32FG14P233F256GM48=1' -I"C:/Users/Co-op Shaheeer R/hardware/kit/EFR32FG14_BRD4257A/config" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/EFR32FG14_BRD4257A/config" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/bsp" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/drivers" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32FG14P/Include" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"emlib/em_opamp.d" -MT"emlib/em_opamp.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_system.o: C:/Users/Co-op\ Shaheeer\ R/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_system.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32FG14P233F256GM48=1' -I"C:/Users/Co-op Shaheeer R/hardware/kit/EFR32FG14_BRD4257A/config" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/EFR32FG14_BRD4257A/config" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/bsp" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/drivers" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32FG14P/Include" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"emlib/em_system.d" -MT"emlib/em_system.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


