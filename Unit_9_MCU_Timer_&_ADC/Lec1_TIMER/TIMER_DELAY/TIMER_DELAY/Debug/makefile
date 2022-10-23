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
TIMER_DELAY.lss \

FLASH_IMAGE += \
TIMER_DELAY.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: TIMER_DELAY.elf secondary-outputs

# Tool invocations
TIMER_DELAY.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TIMER_DELAY.map -mmcu=atmega32 -o "TIMER_DELAY.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TIMER_DELAY.lss: TIMER_DELAY.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TIMER_DELAY.elf  >"TIMER_DELAY.lss"
	@echo 'Finished building: $@'
	@echo ' '

TIMER_DELAY.hex: TIMER_DELAY.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex TIMER_DELAY.elf  "TIMER_DELAY.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TIMER_DELAY.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 TIMER_DELAY.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TIMER_DELAY.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
