################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Co-op\ Shaheeer\ R/SimplicityStudio/SDKs/gecko_sdk/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/sl_mx25_flash_shutdown.c 

OBJS += \
./gecko_sdk_4.0.0/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/sl_mx25_flash_shutdown.o 

C_DEPS += \
./gecko_sdk_4.0.0/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/sl_mx25_flash_shutdown.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.0.0/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/sl_mx25_flash_shutdown.o: C:/Users/Co-op\ Shaheeer\ R/SimplicityStudio/SDKs/gecko_sdk/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/sl_mx25_flash_shutdown.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFR32FG14P233F256GM48=1' '-DSL_BOARD_NAME="BRD4259A"' '-DSL_BOARD_REV="A01"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\simple_button_baremetal\config" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\simple_button_baremetal\autogen" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\simple_button_baremetal" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32FG14P/Include" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/driver/button/inc" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/host/inc" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/gpiointerrupt/inc" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/driver/leddrv/inc" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/Co-op Shaheeer R/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.0.0/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/sl_mx25_flash_shutdown.d" -MT"gecko_sdk_4.0.0/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/sl_mx25_flash_shutdown.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


