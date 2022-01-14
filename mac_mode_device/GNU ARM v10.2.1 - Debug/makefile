################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include gecko_sdk_4.0.0/util/third_party/printf/src/subdir.mk
-include gecko_sdk_4.0.0/util/third_party/printf/subdir.mk
-include gecko_sdk_4.0.0/util/third_party/crypto/sl_component/sl_psa_driver/src/subdir.mk
-include gecko_sdk_4.0.0/util/third_party/crypto/sl_component/sl_mbedtls_support/src/subdir.mk
-include gecko_sdk_4.0.0/util/third_party/crypto/mbedtls/library/subdir.mk
-include gecko_sdk_4.0.0/util/silicon_labs/silabs_core/memory_manager/subdir.mk
-include gecko_sdk_4.0.0/protocol/flex/stack/config/subdir.mk
-include gecko_sdk_4.0.0/protocol/flex/poll/subdir.mk
-include gecko_sdk_4.0.0/protocol/flex/app-framework-common/subdir.mk
-include gecko_sdk_4.0.0/platform/service/udelay/src/subdir.mk
-include gecko_sdk_4.0.0/platform/service/token_manager/src/subdir.mk
-include gecko_sdk_4.0.0/platform/service/system/src/subdir.mk
-include gecko_sdk_4.0.0/platform/service/sleeptimer/src/subdir.mk
-include gecko_sdk_4.0.0/platform/service/power_manager/src/subdir.mk
-include gecko_sdk_4.0.0/platform/service/mpu/src/subdir.mk
-include gecko_sdk_4.0.0/platform/service/legacy_hal/src/subdir.mk
-include gecko_sdk_4.0.0/platform/service/iostream/src/subdir.mk
-include gecko_sdk_4.0.0/platform/service/device_init/src/subdir.mk
-include gecko_sdk_4.0.0/platform/service/cli/src/subdir.mk
-include gecko_sdk_4.0.0/platform/radio/rail_lib/plugin/pa-conversions/subdir.mk
-include gecko_sdk_4.0.0/platform/emlib/src/subdir.mk
-include gecko_sdk_4.0.0/platform/emdrv/nvm3/src/subdir.mk
-include gecko_sdk_4.0.0/platform/common/toolchain/src/subdir.mk
-include gecko_sdk_4.0.0/platform/common/src/subdir.mk
-include gecko_sdk_4.0.0/platform/Device/SiliconLabs/EFR32FG14P/Source/GCC/subdir.mk
-include gecko_sdk_4.0.0/platform/Device/SiliconLabs/EFR32FG14P/Source/subdir.mk
-include gecko_sdk_4.0.0/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/subdir.mk
-include gecko_sdk_4.0.0/hardware/board/src/subdir.mk
-include gecko_sdk_4.0.0/app/common/util/app_log/subdir.mk
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
all: mac_mode_device.axf

# Tool invocations
mac_mode_device.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\mac_mode_device/autogen/linkerfile.ld" -Xlinker --gc-sections -Xlinker -Map="mac_mode_device.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o mac_mode_device.axf -Wl,--start-group "./app_cli.o" "./app_init.o" "./app_process.o" "./main.o" "./autogen/app_framework_event_table.o" "./autogen/callback_dispatcher.o" "./autogen/rail_config.o" "./autogen/sl_board_default_init.o" "./autogen/sl_cli_command_table.o" "./autogen/sl_cli_instances.o" "./autogen/sl_device_init_clocks.o" "./autogen/sl_event_handler.o" "./autogen/sl_iostream_handles.o" "./autogen/sl_iostream_init_usart_instances.o" "./autogen/sl_power_manager_handler.o" "./autogen/sli_cli_hooks.o" "./gecko_sdk_4.0.0/app/common/util/app_log/app_log.o" "./gecko_sdk_4.0.0/hardware/board/src/sl_board_control_gpio.o" "./gecko_sdk_4.0.0/hardware/board/src/sl_board_init.o" "./gecko_sdk_4.0.0/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/sl_mx25_flash_shutdown.o" "./gecko_sdk_4.0.0/platform/Device/SiliconLabs/EFR32FG14P/Source/GCC/startup_efr32fg14p.o" "./gecko_sdk_4.0.0/platform/Device/SiliconLabs/EFR32FG14P/Source/system_efr32fg14p.o" "./gecko_sdk_4.0.0/platform/common/src/sl_slist.o" "./gecko_sdk_4.0.0/platform/common/src/sl_string.o" "./gecko_sdk_4.0.0/platform/common/toolchain/src/sl_memory.o" "./gecko_sdk_4.0.0/platform/emdrv/nvm3/src/nvm3_default_common_linker.o" "./gecko_sdk_4.0.0/platform/emdrv/nvm3/src/nvm3_hal_flash.o" "./gecko_sdk_4.0.0/platform/emdrv/nvm3/src/nvm3_lock.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_assert.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_cmu.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_core.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_crypto.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_emu.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_gpio.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_msc.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_prs.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_rmu.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_rtcc.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_system.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_usart.o" "./gecko_sdk_4.0.0/platform/emlib/src/em_wdog.o" "./gecko_sdk_4.0.0/platform/radio/rail_lib/plugin/pa-conversions/pa_conversions_efr32.o" "./gecko_sdk_4.0.0/platform/radio/rail_lib/plugin/pa-conversions/pa_curves_efr32.o" "./gecko_sdk_4.0.0/platform/service/cli/src/sl_cli.o" "./gecko_sdk_4.0.0/platform/service/cli/src/sl_cli_arguments.o" "./gecko_sdk_4.0.0/platform/service/cli/src/sl_cli_command.o" "./gecko_sdk_4.0.0/platform/service/cli/src/sl_cli_input.o" "./gecko_sdk_4.0.0/platform/service/cli/src/sl_cli_io.o" "./gecko_sdk_4.0.0/platform/service/cli/src/sl_cli_tokenize.o" "./gecko_sdk_4.0.0/platform/service/device_init/src/sl_device_init_dcdc_s1.o" "./gecko_sdk_4.0.0/platform/service/device_init/src/sl_device_init_emu_s1.o" "./gecko_sdk_4.0.0/platform/service/device_init/src/sl_device_init_hfxo_s1.o" "./gecko_sdk_4.0.0/platform/service/device_init/src/sl_device_init_lfxo_s1.o" "./gecko_sdk_4.0.0/platform/service/device_init/src/sl_device_init_nvic.o" "./gecko_sdk_4.0.0/platform/service/iostream/src/sl_iostream.o" "./gecko_sdk_4.0.0/platform/service/iostream/src/sl_iostream_retarget_stdio.o" "./gecko_sdk_4.0.0/platform/service/iostream/src/sl_iostream_stdlib_config.o" "./gecko_sdk_4.0.0/platform/service/iostream/src/sl_iostream_uart.o" "./gecko_sdk_4.0.0/platform/service/iostream/src/sl_iostream_usart.o" "./gecko_sdk_4.0.0/platform/service/legacy_hal/src/base-replacement.o" "./gecko_sdk_4.0.0/platform/service/legacy_hal/src/crc.o" "./gecko_sdk_4.0.0/platform/service/legacy_hal/src/diagnostic.o" "./gecko_sdk_4.0.0/platform/service/legacy_hal/src/ember-phy.o" "./gecko_sdk_4.0.0/platform/service/legacy_hal/src/faults.o" "./gecko_sdk_4.0.0/platform/service/legacy_hal/src/random.o" "./gecko_sdk_4.0.0/platform/service/legacy_hal/src/token_legacy.o" "./gecko_sdk_4.0.0/platform/service/mpu/src/sl_mpu.o" "./gecko_sdk_4.0.0/platform/service/power_manager/src/sl_power_manager.o" "./gecko_sdk_4.0.0/platform/service/power_manager/src/sl_power_manager_debug.o" "./gecko_sdk_4.0.0/platform/service/power_manager/src/sl_power_manager_hal_s0_s1.o" "./gecko_sdk_4.0.0/platform/service/sleeptimer/src/sl_sleeptimer.o" "./gecko_sdk_4.0.0/platform/service/sleeptimer/src/sl_sleeptimer_hal_prortc.o" "./gecko_sdk_4.0.0/platform/service/sleeptimer/src/sl_sleeptimer_hal_rtcc.o" "./gecko_sdk_4.0.0/platform/service/system/src/sl_system_init.o" "./gecko_sdk_4.0.0/platform/service/system/src/sl_system_process_action.o" "./gecko_sdk_4.0.0/platform/service/token_manager/src/sl_token_def.o" "./gecko_sdk_4.0.0/platform/service/token_manager/src/sl_token_manager.o" "./gecko_sdk_4.0.0/platform/service/token_manager/src/sl_token_manufacturing.o" "./gecko_sdk_4.0.0/platform/service/udelay/src/sl_udelay.o" "./gecko_sdk_4.0.0/platform/service/udelay/src/sl_udelay_armv6m_gcc.o" "./gecko_sdk_4.0.0/protocol/flex/app-framework-common/app_framework_common.o" "./gecko_sdk_4.0.0/protocol/flex/app-framework-common/app_framework_common_cb.o" "./gecko_sdk_4.0.0/protocol/flex/app-framework-common/app_framework_sleep.o" "./gecko_sdk_4.0.0/protocol/flex/app-framework-common/app_framework_stack_cb.o" "./gecko_sdk_4.0.0/protocol/flex/poll/poll.o" "./gecko_sdk_4.0.0/protocol/flex/stack/config/ember-configuration.o" "./gecko_sdk_4.0.0/protocol/flex/stack/config/stack-callback-stubs.o" "./gecko_sdk_4.0.0/protocol/flex/stack/config/stack-stubs.o" "./gecko_sdk_4.0.0/util/silicon_labs/silabs_core/memory_manager/sl_malloc.o" "./gecko_sdk_4.0.0/util/third_party/crypto/mbedtls/library/aes.o" "./gecko_sdk_4.0.0/util/third_party/crypto/mbedtls/library/ccm.o" "./gecko_sdk_4.0.0/util/third_party/crypto/mbedtls/library/cipher.o" "./gecko_sdk_4.0.0/util/third_party/crypto/mbedtls/library/cipher_wrap.o" "./gecko_sdk_4.0.0/util/third_party/crypto/mbedtls/library/platform.o" "./gecko_sdk_4.0.0/util/third_party/crypto/mbedtls/library/platform_util.o" "./gecko_sdk_4.0.0/util/third_party/crypto/mbedtls/library/psa_crypto_client.o" "./gecko_sdk_4.0.0/util/third_party/crypto/mbedtls/library/threading.o" "./gecko_sdk_4.0.0/util/third_party/crypto/sl_component/sl_mbedtls_support/src/crypto_aes.o" "./gecko_sdk_4.0.0/util/third_party/crypto/sl_component/sl_mbedtls_support/src/mbedtls_ccm.o" "./gecko_sdk_4.0.0/util/third_party/crypto/sl_component/sl_mbedtls_support/src/sl_mbedtls.o" "./gecko_sdk_4.0.0/util/third_party/crypto/sl_component/sl_psa_driver/src/crypto_management.o" "./gecko_sdk_4.0.0/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_crypto_transparent_driver_aead.o" "./gecko_sdk_4.0.0/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_crypto_transparent_driver_cipher.o" "./gecko_sdk_4.0.0/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_crypto_transparent_driver_hash.o" "./gecko_sdk_4.0.0/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_crypto_transparent_driver_mac.o" "./gecko_sdk_4.0.0/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_psa_driver_common.o" "./gecko_sdk_4.0.0/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_psa_driver_init.o" "./gecko_sdk_4.0.0/util/third_party/printf/printf.o" "./gecko_sdk_4.0.0/util/third_party/printf/src/iostream_printf.o" "C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\mac_mode_device\gecko_sdk_4.0.0\protocol\flex\libs\libconnect-aes-security-library-efr32xg1x-gcc.a" "C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\mac_mode_device\gecko_sdk_4.0.0\protocol\flex\libs\libconnect-packet-queue-library-efr32xg1x-gcc.a" "C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\mac_mode_device\gecko_sdk_4.0.0\protocol\flex\libs\libconnect-parent-support-library-efr32xg1x-gcc.a" "C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\mac_mode_device\gecko_sdk_4.0.0\protocol\flex\libs\libconnect-stack-common-library-efr32xg1x-gcc.a" "C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\mac_mode_device\gecko_sdk_4.0.0\protocol\flex\libs\libconnect-stack-counters-library-efr32xg1x-gcc.a" "C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\mac_mode_device\gecko_sdk_4.0.0\platform\emdrv\nvm3\lib\libnvm3_CM4_gcc.a" "C:\Users\Co-op Shaheeer R\SimplicityStudio\v5_workspace\mac_mode_device\gecko_sdk_4.0.0\platform\radio\rail_lib\autogen\librail_release\librail_efr32xg14_gcc_release.a" -lgcc -lc -lm -lnosys -Wl,--end-group -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: mac_mode_device.hex'
	arm-none-eabi-objcopy -O ihex "mac_mode_device.axf" "mac_mode_device.hex"
	@echo ' '

	@echo 'Building bin file: mac_mode_device.bin'
	arm-none-eabi-objcopy -O binary "mac_mode_device.axf" "mac_mode_device.bin"
	@echo ' '

	@echo 'Building s37 file: mac_mode_device.s37'
	arm-none-eabi-objcopy -O srec "mac_mode_device.axf" "mac_mode_device.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "mac_mode_device.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) mac_mode_device.axf
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
