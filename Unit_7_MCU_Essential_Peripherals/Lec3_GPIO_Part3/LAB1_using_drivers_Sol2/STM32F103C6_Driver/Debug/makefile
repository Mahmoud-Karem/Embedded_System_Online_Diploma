################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include MCAL/GPIO/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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
EXECUTABLES += \
STM32F103C6_Driver.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM32F103C6_Driver.list \

OBJCOPY_HEX += \
STM32F103C6_Driver.hex \

OBJCOPY_BIN += \
STM32F103C6_Driver.bin \


# All Target
all: STM32F103C6_Driver.elf secondary-outputs

# Tool invocations
STM32F103C6_Driver.elf: $(OBJS) $(USER_OBJS) D:\Learn_In_Depth\Embedded_System_Online_Diploma\Unit_7_MCU_Essential_Peripherals\Lec3_GPIO_Part3\LAB1_using_drivers_Sol2\STM32F103C6_Driver\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "STM32F103C6_Driver.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\Learn_In_Depth\Embedded_System_Online_Diploma\Unit_7_MCU_Essential_Peripherals\Lec3_GPIO_Part3\LAB1_using_drivers_Sol2\STM32F103C6_Driver\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="STM32F103C6_Driver.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM32F103C6_Driver.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM32F103C6_Driver.list"
	@echo 'Finished building: $@'
	@echo ' '

STM32F103C6_Driver.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "STM32F103C6_Driver.hex"
	@echo 'Finished building: $@'
	@echo ' '

STM32F103C6_Driver.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "STM32F103C6_Driver.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
