################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include CMSIS/EFR32FG14P/subdir.mk
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
all: SLSTK3301A_EFM32TG11B_adc_single_prs_gpio_dma.axf

dependents:
	-cd C:/Users/Co-op\ Shaheeer\ R/SimplicityStudio/v5_workspace/SLSTK3301A_EFM32TG11B_adc_single_prs_gpio_dma/GNU\ ARM\ v10.2.1\ -\ release && $(MAKE) clean all

# Tool invocations
SLSTK3301A_EFM32TG11B_adc_single_prs_gpio_dma.axf: $(OBJS) $(USER_OBJS) C:/Users/Co-op\ Shaheeer\ R/SimplicityStudio/v5_workspace/SLSTK3301A_EFM32TG11B_adc_single_prs_gpio_dma/GNU\ ARM\ v10.2.1\ -\ release/SLSTK3301A_EFM32TG11B_adc_single_prs_gpio_dma.axf
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "SLSTK3301A_EFM32TG11B_adc_single_prs_gpio_dma.ld" -Xlinker --gc-sections -Xlinker -Map="SLSTK3301A_EFM32TG11B_adc_single_prs_gpio_dma.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o SLSTK3301A_EFM32TG11B_adc_single_prs_gpio_dma.axf "./CMSIS/EFR32FG14P/startup_efr32fg14p.o" "./CMSIS/EFR32FG14P/system_efr32fg14p.o" "./emlib/em_adc.o" "./emlib/em_cmu.o" "./emlib/em_core.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_ldma.o" "./emlib/em_letimer.o" "./emlib/em_prs.o" "./emlib/em_system.o" "./src/main_tg11.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: SLSTK3301A_EFM32TG11B_adc_single_prs_gpio_dma.hex'
	arm-none-eabi-objcopy -O ihex "SLSTK3301A_EFM32TG11B_adc_single_prs_gpio_dma.axf" "SLSTK3301A_EFM32TG11B_adc_single_prs_gpio_dma.hex"
	@echo ' '

	@echo 'Building bin file: SLSTK3301A_EFM32TG11B_adc_single_prs_gpio_dma.bin'
	arm-none-eabi-objcopy -O binary "SLSTK3301A_EFM32TG11B_adc_single_prs_gpio_dma.axf" "SLSTK3301A_EFM32TG11B_adc_single_prs_gpio_dma.bin"
	@echo ' '

	@echo 'Building s37 file: SLSTK3301A_EFM32TG11B_adc_single_prs_gpio_dma.s37'
	arm-none-eabi-objcopy -O srec "SLSTK3301A_EFM32TG11B_adc_single_prs_gpio_dma.axf" "SLSTK3301A_EFM32TG11B_adc_single_prs_gpio_dma.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "SLSTK3301A_EFM32TG11B_adc_single_prs_gpio_dma.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) SLSTK3301A_EFM32TG11B_adc_single_prs_gpio_dma.axf
	-@echo ' '

.PHONY: all clean dependents
C:/Users/Co-op\ Shaheeer\ R/SimplicityStudio/v5_workspace/SLSTK3301A_EFM32TG11B_adc_single_prs_gpio_dma/GNU\ ARM\ v10.2.1\ -\ release/SLSTK3301A_EFM32TG11B_adc_single_prs_gpio_dma.axf:

-include ../makefile.targets
