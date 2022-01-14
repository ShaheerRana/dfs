################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include gecko_sdk_4.0.0/platform/service/udelay/src/subdir.mk
-include gecko_sdk_4.0.0/platform/service/system/src/subdir.mk
-include gecko_sdk_4.0.0/platform/service/sleeptimer/src/subdir.mk
-include gecko_sdk_4.0.0/platform/service/power_manager/src/subdir.mk
-include gecko_sdk_4.0.0/platform/service/device_init/src/subdir.mk
-include gecko_sdk_4.0.0/platform/emlib/src/subdir.mk
-include gecko_sdk_4.0.0/platform/emdrv/gpiointerrupt/src/subdir.mk
-include gecko_sdk_4.0.0/platform/driver/leddrv/src/subdir.mk
-include gecko_sdk_4.0.0/platform/driver/button/src/subdir.mk
-include gecko_sdk_4.0.0/platform/common/toolchain/src/subdir.mk
-include gecko_sdk_4.0.0/platform/common/src/subdir.mk
-include gecko_sdk_4.0.0/platform/Device/SiliconLabs/EFR32FG14P/Source/GCC/subdir.mk
-include gecko_sdk_4.0.0/platform/Device/SiliconLabs/EFR32FG14P/Source/subdir.mk
-include gecko_sdk_4.0.0/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/subdir.mk
-include gecko_sdk_4.0.0/hardware/board/src/subdir.mk
-include autogen/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: simple_button_baremetal.axf

# Tool invocations
simple_button_baremetal.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\simple_button_baremetal/autogen/linkerfile.ld" -Xlinker --gc-sections -Xlinker -Map="simple_button_baremetal.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o simple_button_baremetal.axf -Wl,--start-group "./app.o" "./main.o" "./simple_button_baremetal.o" "./autogen/sl_board_default_init.o" "./autogen/sl_device_init_clocks.o" "./autogen/sl_event_handler.o" "./autogen/sl_power_manager_handler.o" "./autogen/sl_simple_button_instances.o" "./autogen/sl_simple_led_instances.o" "./gecko_sdk_4.0.0/hardware/board/src/sl_board_control_gpio.o" "./gecko_sdk_4.0.0/hardware/board/src/sl_board_init.o" "./gecko_sdk_4.0.0/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/sl_mx25_flash_shutdown.o" "./gecko_sdk_4.0.0/platform/Device/SiliconLabs/EFR32FG14P/Source/GCC/startup_efr32fg14p.o" "./gecko_sdk_4.0.0/platform/Device/SiliconLabs/EFR32FG14P/Source/system_efr32fg14p.o" "./gecko_sdk_4.0.0/platform/common/src/sl_slist.o" "./gecko_sdk_4.0.0/platform/common/toolchain/src/sl_memory.o" "./gecko_sdk_4.0.0/platform/driver/button/src/sl_button.o" "./gecko_sdk_4.0.0/platform/driver/button/src/sl_simple_button.o" "./gecko_sdk_4.0.0/platform/driver/leddrv/src/sl_led.o" "./gecko_sdk_4.0.0/platform/driver/leddrv/src/sl_simple_led.o" "./gecko_sdk_4.0.0/platform/emdrv/gpiointerrupt/src/gpiointerrupt.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_assert.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_cmu.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_core.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_emu.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_gpio.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_rtcc.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_system.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_usart.o" "./gecko_sdk_4.0.0/platform/service/device_init/src/sl_device_init_dcdc_s1.o" "./gecko_sdk_4.0.0/platform/service/device_init/src/sl_device_init_emu_s1.o" "./gecko_sdk_4.0.0/platform/service/device_init/src/sl_device_init_hfxo_s1.o" "./gecko_sdk_4.0.0/platform/service/device_init/src/sl_device_init_lfxo_s1.o" "./gecko_sdk_4.0.0/platform/service/device_init/src/sl_device_init_nvic.o" "./gecko_sdk_4.0.0/platform/service/power_manager/src/sl_power_manager.o" "./gecko_sdk_4.0.0/platform/service/power_manager/src/sl_power_manager_debug.o" "./gecko_sdk_4.0.0/platform/service/power_manager/src/sl_power_manager_hal_s0_s1.o" "./gecko_sdk_4.0.0/platform/service/sleeptimer/src/sl_sleeptimer.o" "./gecko_sdk_4.0.0/platform/service/sleeptimer/src/sl_sleeptimer_hal_prortc.o" "./gecko_sdk_4.0.0/platform/service/sleeptimer/src/sl_sleeptimer_hal_rtcc.o" "./gecko_sdk_4.0.0/platform/service/system/src/sl_system_init.o" "./gecko_sdk_4.0.0/platform/service/system/src/sl_system_process_action.o" "./gecko_sdk_4.0.0/platform/service/udelay/src/sl_udelay.o" "./gecko_sdk_4.0.0/platform/service/udelay/src/sl_udelay_armv6m_gcc.o" -lgcc -lc -lm -lnosys -Wl,--end-group -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: simple_button_baremetal.hex'
	arm-none-eabi-objcopy -O ihex "simple_button_baremetal.axf" "simple_button_baremetal.hex"
	@echo ' '

	@echo 'Building bin file: simple_button_baremetal.bin'
	arm-none-eabi-objcopy -O binary "simple_button_baremetal.axf" "simple_button_baremetal.bin"
	@echo ' '

	@echo 'Building s37 file: simple_button_baremetal.s37'
	arm-none-eabi-objcopy -O srec "simple_button_baremetal.axf" "simple_button_baremetal.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "simple_button_baremetal.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) simple_button_baremetal.axf
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
