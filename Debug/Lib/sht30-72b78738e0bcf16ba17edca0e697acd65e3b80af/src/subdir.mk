################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/sht30-72b78738e0bcf16ba17edca0e697acd65e3b80af/src/driver_sht30.c 

OBJS += \
./Lib/sht30-72b78738e0bcf16ba17edca0e697acd65e3b80af/src/driver_sht30.o 

C_DEPS += \
./Lib/sht30-72b78738e0bcf16ba17edca0e697acd65e3b80af/src/driver_sht30.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/sht30-72b78738e0bcf16ba17edca0e697acd65e3b80af/src/%.o Lib/sht30-72b78738e0bcf16ba17edca0e697acd65e3b80af/src/%.su Lib/sht30-72b78738e0bcf16ba17edca0e697acd65e3b80af/src/%.cyclo: ../Lib/sht30-72b78738e0bcf16ba17edca0e697acd65e3b80af/src/%.c Lib/sht30-72b78738e0bcf16ba17edca0e697acd65e3b80af/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Douglas/Desktop/SHT_30 Nucleo/Lib" -I"C:/Users/Douglas/Desktop/SHT_30 Nucleo/Lib/application" -I"C:/Users/Douglas/Desktop/SHT_30 Nucleo/Lib/board" -I"C:/Users/Douglas/Desktop/SHT_30 Nucleo/Lib/sht30-72b78738e0bcf16ba17edca0e697acd65e3b80af/interface" -I"C:/Users/Douglas/Desktop/SHT_30 Nucleo/Lib/sht30-72b78738e0bcf16ba17edca0e697acd65e3b80af/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Lib-2f-sht30-2d-72b78738e0bcf16ba17edca0e697acd65e3b80af-2f-src

clean-Lib-2f-sht30-2d-72b78738e0bcf16ba17edca0e697acd65e3b80af-2f-src:
	-$(RM) ./Lib/sht30-72b78738e0bcf16ba17edca0e697acd65e3b80af/src/driver_sht30.cyclo ./Lib/sht30-72b78738e0bcf16ba17edca0e697acd65e3b80af/src/driver_sht30.d ./Lib/sht30-72b78738e0bcf16ba17edca0e697acd65e3b80af/src/driver_sht30.o ./Lib/sht30-72b78738e0bcf16ba17edca0e697acd65e3b80af/src/driver_sht30.su

.PHONY: clean-Lib-2f-sht30-2d-72b78738e0bcf16ba17edca0e697acd65e3b80af-2f-src

