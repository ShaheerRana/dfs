################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Co-op\ Shaheeer\ R/SimplicityStudio/SDKs/gecko_sdk/platform/Device/SiliconLabs/EFR32FG14P/Source/system_efr32fg14p.c 

S_UPPER_SRCS += \
C:/Users/Co-op\ Shaheeer\ R/SimplicityStudio/SDKs/gecko_sdk/platform/Device/SiliconLabs/EFR32FG14P/Source/GCC/startup_efr32fg14p.S 

OBJS += \
./CMSIS/EFR32FG14P/startup_efr32fg14p.o \
./CMSIS/EFR32FG14P/system_efr32fg14p.o 

C_DEPS += \
./CMSIS/EFR32FG14P/system_efr32fg14p.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/EFR32FG14P/startup_efr32fg14p.o: C:/Users/Co-op\ Shaheeer\ R/SimplicityStudio/SDKs/gecko_sdk/platform/Device/SiliconLabs/EFR32FG14P/Source/GCC/startup_efr32fg14p.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Assembler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32FG14P/Include" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/drivers" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/bsp" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" '-DEFR32FG14P233F256GM48=1' -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -x assembler-with-cpp -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

CMSIS/EFR32FG14P/system_efr32fg14p.o: C:/Users/Co-op\ Shaheeer\ R/SimplicityStudio/SDKs/gecko_sdk/platform/Device/SiliconLabs/EFR32FG14P/Source/system_efr32fg14p.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32FG14P233F256GM48=1' -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32FG14P/Include" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/drivers" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/bsp" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:\SiliconLabs\SimplicityStudio\v5\developer\toolchains\gnu_arm\10.2_2020q4\/arm-none-eabi/include" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"CMSIS/EFR32FG14P/system_efr32fg14p.d" -MT"CMSIS/EFR32FG14P/system_efr32fg14p.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


