################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HC-SR04.c \
../gpio.c \
../icu.c \
../lcd.c \
../mini_project4.c 

OBJS += \
./HC-SR04.o \
./gpio.o \
./icu.o \
./lcd.o \
./mini_project4.o 

C_DEPS += \
./HC-SR04.d \
./gpio.d \
./icu.d \
./lcd.d \
./mini_project4.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

