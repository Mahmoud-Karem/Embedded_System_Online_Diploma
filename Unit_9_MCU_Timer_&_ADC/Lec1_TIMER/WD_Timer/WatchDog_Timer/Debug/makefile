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
WatchDog_Timer.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: WatchDog_Timer.elf secondary-outputs

# Tool invocations
WatchDog_Timer.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,WatchDog_Timer.map -mmcu=atmega32 -o "WatchDog_Timer.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

WatchDog_Timer.lss: WatchDog_Timer.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S WatchDog_Timer.elf  >"WatchDog_Timer.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: WatchDog_Timer.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 WatchDog_Timer.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) WatchDog_Timer.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
