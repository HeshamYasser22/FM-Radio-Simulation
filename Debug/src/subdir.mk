################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HR2RDAC_Program.c \
../src/HSTP_Configurations.c \
../src/HSTP_Program.c \
../src/HTFT_Program.c \
../src/MEXTI_Configurations.c \
../src/MEXTI_Program.c \
../src/MGPIO_Program.c \
../src/MNVIC_Program.c \
../src/MRCC_Program.c \
../src/MSPI_Program.c \
../src/MSTK_Program.c \
../src/initialize-hardware.c \
../src/main.c \
../src/stm32f4xx_hal_msp.c \
../src/write.c 

C_DEPS += \
./src/HR2RDAC_Program.d \
./src/HSTP_Configurations.d \
./src/HSTP_Program.d \
./src/HTFT_Program.d \
./src/MEXTI_Configurations.d \
./src/MEXTI_Program.d \
./src/MGPIO_Program.d \
./src/MNVIC_Program.d \
./src/MRCC_Program.d \
./src/MSPI_Program.d \
./src/MSTK_Program.d \
./src/initialize-hardware.d \
./src/main.d \
./src/stm32f4xx_hal_msp.d \
./src/write.d 

OBJS += \
./src/HR2RDAC_Program.o \
./src/HSTP_Configurations.o \
./src/HSTP_Program.o \
./src/HTFT_Program.o \
./src/MEXTI_Configurations.o \
./src/MEXTI_Program.o \
./src/MGPIO_Program.o \
./src/MNVIC_Program.o \
./src/MRCC_Program.o \
./src/MSPI_Program.o \
./src/MSTK_Program.o \
./src/initialize-hardware.o \
./src/main.o \
./src/stm32f4xx_hal_msp.o \
./src/write.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/stm32f4xx_hal_msp.o: ../src/stm32f4xx_hal_msp.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -Wno-padded -Wno-missing-prototypes -Wno-missing-declarations -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


