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
light_sensor.lss \

FLASH_IMAGE += \
light_sensor.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: light_sensor.elf secondary-outputs

# Tool invocations
light_sensor.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,light_sensor.map -mmcu=atmega32 -o "light_sensor.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

light_sensor.lss: light_sensor.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S light_sensor.elf  >"light_sensor.lss"
	@echo 'Finished building: $@'
	@echo ' '

light_sensor.hex: light_sensor.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex light_sensor.elf  "light_sensor.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: light_sensor.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 light_sensor.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) light_sensor.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
