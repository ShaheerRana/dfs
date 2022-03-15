################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../gecko_sdk_4.0.0/platform/Device/SiliconLabs/EFR32FG14P/Source/system_efr32fg14p.c 

OBJS += \
./gecko_sdk_4.0.0/platform/Device/SiliconLabs/EFR32FG14P/Source/system_efr32fg14p.o 

C_DEPS += \
./gecko_sdk_4.0.0/platform/Device/SiliconLabs/EFR32FG14P/Source/system_efr32fg14p.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.0.0/platform/Device/SiliconLabs/EFR32FG14P/Source/system_efr32fg14p.o: ../gecko_sdk_4.0.0/platform/Device/SiliconLabs/EFR32FG14P/Source/system_efr32fg14p.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFR32FG14P233F256GM48=1' '-DSL_BOARD_NAME="BRD4259A"' '-DSL_BOARD_REV="A01"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/shabana/dfs/empty/config" -I"/Users/shabana/dfs/empty/autogen" -I"/Users/shabana/dfs/empty" -I"/Users/shabana/dfs/empty/gecko_sdk_4.0.0/platform/Device/SiliconLabs/EFR32FG14P/Include" -I"/Users/shabana/dfs/empty/gecko_sdk_4.0.0/hardware/board/inc" -I"/Users/shabana/dfs/empty/gecko_sdk_4.0.0/platform/CMSIS/Include" -I"/Users/shabana/dfs/empty/gecko_sdk_4.0.0/platform/service/device_init/inc" -I"/Users/shabana/dfs/empty/gecko_sdk_4.0.0/platform/emlib/inc" -I"/Users/shabana/dfs/empty/gecko_sdk_4.0.0/platform/common/inc" -I"/Users/shabana/dfs/empty/gecko_sdk_4.0.0/hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"/Users/shabana/dfs/empty/gecko_sdk_4.0.0/platform/common/toolchain/inc" -I"/Users/shabana/dfs/empty/gecko_sdk_4.0.0/platform/service/system/inc" -I"/Users/shabana/dfs/empty/gecko_sdk_4.0.0/platform/service/udelay/inc" -Os -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.0.0/platform/Device/SiliconLabs/EFR32FG14P/Source/system_efr32fg14p.d" -MT"gecko_sdk_4.0.0/platform/Device/SiliconLabs/EFR32FG14P/Source/system_efr32fg14p.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


