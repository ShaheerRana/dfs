################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../autogen/sl_board_default_init.c \
../autogen/sl_device_init_clocks.c \
../autogen/sl_event_handler.c 

OBJS += \
./autogen/sl_board_default_init.o \
./autogen/sl_device_init_clocks.o \
./autogen/sl_event_handler.o 

C_DEPS += \
./autogen/sl_board_default_init.d \
./autogen/sl_device_init_clocks.d \
./autogen/sl_event_handler.d 


# Each subdirectory must supply rules for building sources it contributes
autogen/sl_board_default_init.o: ../autogen/sl_board_default_init.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFR32FG14P233F256GM48=1' '-DSL_BOARD_NAME="BRD4259A"' '-DSL_BOARD_REV="A01"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\config" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\autogen" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\Device\SiliconLabs\EFR32FG14P\Include" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\hardware\board\inc" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\CMSIS\Include" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\service\device_init\inc" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\emlib\inc" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\common\inc" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\hardware\driver\mx25_flash_shutdown\inc\sl_mx25_flash_shutdown_usart" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\common\toolchain\inc" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\service\system\inc" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\service\udelay\inc" -Os -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_board_default_init.d" -MT"autogen/sl_board_default_init.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_device_init_clocks.o: ../autogen/sl_device_init_clocks.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFR32FG14P233F256GM48=1' '-DSL_BOARD_NAME="BRD4259A"' '-DSL_BOARD_REV="A01"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\config" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\autogen" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\Device\SiliconLabs\EFR32FG14P\Include" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\hardware\board\inc" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\CMSIS\Include" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\service\device_init\inc" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\emlib\inc" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\common\inc" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\hardware\driver\mx25_flash_shutdown\inc\sl_mx25_flash_shutdown_usart" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\common\toolchain\inc" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\service\system\inc" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\service\udelay\inc" -Os -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_device_init_clocks.d" -MT"autogen/sl_device_init_clocks.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_event_handler.o: ../autogen/sl_event_handler.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFR32FG14P233F256GM48=1' '-DSL_BOARD_NAME="BRD4259A"' '-DSL_BOARD_REV="A01"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\config" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\autogen" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\Device\SiliconLabs\EFR32FG14P\Include" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\hardware\board\inc" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\CMSIS\Include" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\service\device_init\inc" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\emlib\inc" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\common\inc" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\hardware\driver\mx25_flash_shutdown\inc\sl_mx25_flash_shutdown_usart" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\common\toolchain\inc" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\service\system\inc" -I"C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\empty\gecko_sdk_4.0.0\platform\service\udelay\inc" -Os -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_event_handler.d" -MT"autogen/sl_event_handler.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


