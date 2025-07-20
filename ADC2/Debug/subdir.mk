################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_main.c \
../ADC_program.c \
../DIO_program.c \
../TMR_program.c \
../program.c 

OBJS += \
./ADC_main.o \
./ADC_program.o \
./DIO_program.o \
./TMR_program.o \
./program.o 

C_DEPS += \
./ADC_main.d \
./ADC_program.d \
./DIO_program.d \
./TMR_program.d \
./program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


