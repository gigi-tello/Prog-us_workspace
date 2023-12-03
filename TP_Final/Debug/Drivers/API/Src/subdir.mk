################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/Src/API_adc.c \
../Drivers/API/Src/API_debounce.c \
../Drivers/API/Src/API_delay.c \
../Drivers/API/Src/API_lcd_keypad.c \
../Drivers/API/Src/API_uart.c \
../Drivers/API/Src/stm32f4xx_nucleo_144.c 

OBJS += \
./Drivers/API/Src/API_adc.o \
./Drivers/API/Src/API_debounce.o \
./Drivers/API/Src/API_delay.o \
./Drivers/API/Src/API_lcd_keypad.o \
./Drivers/API/Src/API_uart.o \
./Drivers/API/Src/stm32f4xx_nucleo_144.o 

C_DEPS += \
./Drivers/API/Src/API_adc.d \
./Drivers/API/Src/API_debounce.d \
./Drivers/API/Src/API_delay.d \
./Drivers/API/Src/API_lcd_keypad.d \
./Drivers/API/Src/API_uart.d \
./Drivers/API/Src/stm32f4xx_nucleo_144.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/Src/%.o Drivers/API/Src/%.su Drivers/API/Src/%.cyclo: ../Drivers/API/Src/%.c Drivers/API/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F439xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/gigi/Facu/CESE/Programacion de micros/Prog-us_workspace/TP_Final/Drivers/API/Inc" -I"/home/gigi/Facu/CESE/Programacion de micros/Prog-us_workspace/TP_Final/Drivers/API/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-API-2f-Src

clean-Drivers-2f-API-2f-Src:
	-$(RM) ./Drivers/API/Src/API_adc.cyclo ./Drivers/API/Src/API_adc.d ./Drivers/API/Src/API_adc.o ./Drivers/API/Src/API_adc.su ./Drivers/API/Src/API_debounce.cyclo ./Drivers/API/Src/API_debounce.d ./Drivers/API/Src/API_debounce.o ./Drivers/API/Src/API_debounce.su ./Drivers/API/Src/API_delay.cyclo ./Drivers/API/Src/API_delay.d ./Drivers/API/Src/API_delay.o ./Drivers/API/Src/API_delay.su ./Drivers/API/Src/API_lcd_keypad.cyclo ./Drivers/API/Src/API_lcd_keypad.d ./Drivers/API/Src/API_lcd_keypad.o ./Drivers/API/Src/API_lcd_keypad.su ./Drivers/API/Src/API_uart.cyclo ./Drivers/API/Src/API_uart.d ./Drivers/API/Src/API_uart.o ./Drivers/API/Src/API_uart.su ./Drivers/API/Src/stm32f4xx_nucleo_144.cyclo ./Drivers/API/Src/stm32f4xx_nucleo_144.d ./Drivers/API/Src/stm32f4xx_nucleo_144.o ./Drivers/API/Src/stm32f4xx_nucleo_144.su

.PHONY: clean-Drivers-2f-API-2f-Src

