################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include gecko_sdk_4.0.0/platform/service/udelay/src/subdir.mk
-include gecko_sdk_4.0.0/platform/service/system/src/subdir.mk
-include gecko_sdk_4.0.0/platform/service/device_init/src/subdir.mk
-include gecko_sdk_4.0.0/platform/emlib/src/subdir.mk
-include gecko_sdk_4.0.0/platform/common/toolchain/src/subdir.mk
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
all: dfs_radio_prototype.axf

# Tool invocations
dfs_radio_prototype.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "C:\Users\Co-op Shaheeer R\SimplicityStudio\dfs\dfs_radio_prototype/autogen/linkerfile.ld" -Xlinker --gc-sections -Xlinker -Map="dfs_radio_prototype.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o dfs_radio_prototype.axf -Wl,--start-group "./app.o" "./main.o" "./autogen/sl_board_default_init.o" "./autogen/sl_device_init_clocks.o" "./autogen/sl_event_handler.o" "./gecko_sdk_4.0.0/hardware/board/src/sl_board_control_gpio.o" "./gecko_sdk_4.0.0/hardware/board/src/sl_board_init.o" "./gecko_sdk_4.0.0/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/sl_mx25_flash_shutdown.o" "./gecko_sdk_4.0.0/platform/Device/SiliconLabs/EFR32FG14P/Source/GCC/startup_efr32fg14p.o" "./gecko_sdk_4.0.0/platform/Device/SiliconLabs/EFR32FG14P/Source/system_efr32fg14p.o" "./gecko_sdk_4.0.0/platform/common/toolchain/src/sl_memory.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_adc.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_assert.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_cmu.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_core.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_emu.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_gpio.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_ldma.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_letimer.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_opamp.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_prs.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_system.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_usart.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_vdac.o" "./gecko_sdk_4.0.0/platform/service/device_init/src/sl_device_init_dcdc_s1.o" "./gecko_sdk_4.0.0/platform/service/device_init/src/sl_device_init_emu_s1.o" "./gecko_sdk_4.0.0/platform/service/device_init/src/sl_device_init_hfxo_s1.o" "./gecko_sdk_4.0.0/platform/service/device_init/src/sl_device_init_lfxo_s1.o" "./gecko_sdk_4.0.0/platform/service/device_init/src/sl_device_init_nvic.o" "./gecko_sdk_4.0.0/platform/service/system/src/sl_system_init.o" "./gecko_sdk_4.0.0/platform/service/system/src/sl_system_process_action.o" "./gecko_sdk_4.0.0/platform/service/udelay/src/sl_udelay.o" "./gecko_sdk_4.0.0/platform/service/udelay/src/sl_udelay_armv6m_gcc.o" -lgcc -lc -lm -lnosys -Wl,--end-group -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: dfs_radio_prototype.hex'
	arm-none-eabi-objcopy -O ihex "dfs_radio_prototype.axf" "dfs_radio_prototype.hex"
	@echo ' '

	@echo 'Building bin file: dfs_radio_prototype.bin'
	arm-none-eabi-objcopy -O binary "dfs_radio_prototype.axf" "dfs_radio_prototype.bin"
	@echo ' '

	@echo 'Building s37 file: dfs_radio_prototype.s37'
	arm-none-eabi-objcopy -O srec "dfs_radio_prototype.axf" "dfs_radio_prototype.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "dfs_radio_prototype.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) dfs_radio_prototype.axf
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
