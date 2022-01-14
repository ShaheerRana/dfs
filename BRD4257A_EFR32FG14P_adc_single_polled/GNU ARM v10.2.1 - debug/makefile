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
all: BRD4257A_EFR32FG14P_adc_single_polled.axf

# Tool invocations
BRD4257A_EFR32FG14P_adc_single_polled.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "BRD4257A_EFR32FG14P_adc_single_polled.ld" -Xlinker --gc-sections -Xlinker -Map="BRD4257A_EFR32FG14P_adc_single_polled.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o BRD4257A_EFR32FG14P_adc_single_polled.axf "./CMSIS/EFR32FG14P/startup_efr32fg14p.o" "./CMSIS/EFR32FG14P/system_efr32fg14p.o" "./emlib/em_adc.o" "./emlib/em_cmu.o" "./emlib/em_core.o" "./emlib/em_gpio.o" "./emlib/em_usart.o" "./src/main_gg11_xg14.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: BRD4257A_EFR32FG14P_adc_single_polled.hex'
	arm-none-eabi-objcopy -O ihex "BRD4257A_EFR32FG14P_adc_single_polled.axf" "BRD4257A_EFR32FG14P_adc_single_polled.hex"
	@echo ' '

	@echo 'Building bin file: BRD4257A_EFR32FG14P_adc_single_polled.bin'
	arm-none-eabi-objcopy -O binary "BRD4257A_EFR32FG14P_adc_single_polled.axf" "BRD4257A_EFR32FG14P_adc_single_polled.bin"
	@echo ' '

	@echo 'Building s37 file: BRD4257A_EFR32FG14P_adc_single_polled.s37'
	arm-none-eabi-objcopy -O srec "BRD4257A_EFR32FG14P_adc_single_polled.axf" "BRD4257A_EFR32FG14P_adc_single_polled.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "BRD4257A_EFR32FG14P_adc_single_polled.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) BRD4257A_EFR32FG14P_adc_single_polled.axf
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
