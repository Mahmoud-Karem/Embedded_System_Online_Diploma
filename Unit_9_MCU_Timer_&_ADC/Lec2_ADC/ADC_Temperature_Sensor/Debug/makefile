################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ADC_Temperature_Sensor.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: ADC_Temperature_Sensor.elf secondary-outputs

# Tool invocations
ADC_Temperature_Sensor.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ADC_Temperature_Sensor.map -mmcu=atmega32 -o "ADC_Temperature_Sensor.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ADC_Temperature_Sensor.lss: ADC_Temperature_Sensor.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ADC_Temperature_Sensor.elf  >"ADC_Temperature_Sensor.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ADC_Temperature_Sensor.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ADC_Temperature_Sensor.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ADC_Temperature_Sensor.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
