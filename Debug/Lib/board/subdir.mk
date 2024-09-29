################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/board/board_stm32l476rg.c 

OBJS += \
./Lib/board/board_stm32l476rg.o 

C_DEPS += \
./Lib/board/board_stm32l476rg.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/board/%.o Lib/board/%.su Lib/board/%.cyclo: ../Lib/board/%.c Lib/board/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Douglas/Desktop/SHT_30 Nucleo/Lib" -I"C:/Users/Douglas/Desktop/SHT_30 Nucleo/Lib/application" -I"C:/Users/Douglas/Desktop/SHT_30 Nucleo/Lib/board" -I"C:/Users/Douglas/Desktop/SHT_30 Nucleo/Lib/sht30-72b78738e0bcf16ba17edca0e697acd65e3b80af/interface" -I"C:/Users/Douglas/Desktop/SHT_30 Nucleo/Lib/sht30-72b78738e0bcf16ba17edca0e697acd65e3b80af/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Lib-2f-board

clean-Lib-2f-board:
	-$(RM) ./Lib/board/board_stm32l476rg.cyclo ./Lib/board/board_stm32l476rg.d ./Lib/board/board_stm32l476rg.o ./Lib/board/board_stm32l476rg.su

.PHONY: clean-Lib-2f-board

