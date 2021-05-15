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
zad1-6.lss \

FLASH_IMAGE += \
zad1-6.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: zad1-6.elf secondary-outputs

# Tool invocations
zad1-6.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,zad1-6.map -L"C:\Users\Andrej\Desktop\eclipse-workspace\usart\Release" -mmcu=atmega328p -o "zad1-6.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

zad1-6.lss: zad1-6.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S zad1-6.elf  >"zad1-6.lss"
	@echo 'Finished building: $@'
	@echo ' '

zad1-6.hex: zad1-6.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex zad1-6.elf  "zad1-6.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: zad1-6.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p zad1-6.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: zad1-6.elf
	@echo 'Invoking: AVRDude'
	C:\eclipse-cpp-2020-12-R-win32-x86_64\bin\avrdude -pm328p -carduino -PCOM6 -Uflash:w:zad1-6.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) zad1-6.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
