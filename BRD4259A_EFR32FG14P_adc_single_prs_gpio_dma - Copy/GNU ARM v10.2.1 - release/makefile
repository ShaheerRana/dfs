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
all: BRD4259A_EFR32FG14P_adc_single_prs_gpio_dma\ -\ Copy.axf

# Tool invocations
BRD4259A_EFR32FG14P_adc_single_prs_gpio_dma\ -\ Copy.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "BRD4259A_EFR32FG14P_adc_single_prs_gpio_dma - Copy.ld" -Xlinker --gc-sections -Xlinker -Map="BRD4259A_EFR32FG14P_adc_single_prs_gpio_dma - Copy.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o "BRD4259A_EFR32FG14P_adc_single_prs_gpio_dma - Copy.axf" "./CMSIS/EFR32FG14P/startup_efr32fg14p.o" "./CMSIS/EFR32FG14P/system_efr32fg14p.o" "./emlib/em_adc.o" "./emlib/em_cmu.o" "./emlib/em_core.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_ldma.o" "./emlib/em_letimer.o" "./emlib/em_prs.o" "./emlib/em_system.o" "./src/main_gg11_xg14.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: BRD4259A_EFR32FG14P_adc_single_prs_gpio_dma - Copy.hex'
	arm-none-eabi-objcopy -O ihex "BRD4259A_EFR32FG14P_adc_single_prs_gpio_dma - Copy.axf" "BRD4259A_EFR32FG14P_adc_single_prs_gpio_dma - Copy.hex"
	@echo ' '

	@echo 'Building bin file: BRD4259A_EFR32FG14P_adc_single_prs_gpio_dma - Copy.bin'
	arm-none-eabi-objcopy -O binary "BRD4259A_EFR32FG14P_adc_single_prs_gpio_dma - Copy.axf" "BRD4259A_EFR32FG14P_adc_single_prs_gpio_dma - Copy.bin"
	@echo ' '

	@echo 'Building s37 file: BRD4259A_EFR32FG14P_adc_single_prs_gpio_dma - Copy.s37'
	arm-none-eabi-objcopy -O srec "BRD4259A_EFR32FG14P_adc_single_prs_gpio_dma - Copy.axf" "BRD4259A_EFR32FG14P_adc_single_prs_gpio_dma - Copy.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "BRD4259A_EFR32FG14P_adc_single_prs_gpio_dma - Copy.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) "BRD4259A_EFR32FG14P_adc_single_prs_gpio_dma - Copy.axf"
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
