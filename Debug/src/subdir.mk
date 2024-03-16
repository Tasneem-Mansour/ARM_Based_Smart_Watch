################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HIR_program.c \
../src/HKPD_program.c \
../src/HR2RDAC_program.c \
../src/HSTP_program.c \
../src/HTFT_program.c \
../src/MEXTI_program.c \
../src/MGPIO_program.c \
../src/MNVIC_program.c \
../src/MRCC_program.c \
../src/MRTC_program.c \
../src/MSPI_program.c \
../src/MSYSTICK_program.c \
../src/_initialize_hardware.c \
../src/_write.c \
../src/main.c \
../src/stm32f4xx_hal_msp.c 

OBJS += \
./src/HIR_program.o \
./src/HKPD_program.o \
./src/HR2RDAC_program.o \
./src/HSTP_program.o \
./src/HTFT_program.o \
./src/MEXTI_program.o \
./src/MGPIO_program.o \
./src/MNVIC_program.o \
./src/MRCC_program.o \
./src/MRTC_program.o \
./src/MSPI_program.o \
./src/MSYSTICK_program.o \
./src/_initialize_hardware.o \
./src/_write.o \
./src/main.o \
./src/stm32f4xx_hal_msp.o 

C_DEPS += \
./src/HIR_program.d \
./src/HKPD_program.d \
./src/HR2RDAC_program.d \
./src/HSTP_program.d \
./src/HTFT_program.d \
./src/MEXTI_program.d \
./src/MGPIO_program.d \
./src/MNVIC_program.d \
./src/MRCC_program.d \
./src/MRTC_program.d \
./src/MSPI_program.d \
./src/MSYSTICK_program.d \
./src/_initialize_hardware.d \
./src/_write.d \
./src/main.d \
./src/stm32f4xx_hal_msp.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=16000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/stm32f4xx_hal_msp.o: ../src/stm32f4xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=16000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -Wno-missing-prototypes -Wno-missing-declarations -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/stm32f4xx_hal_msp.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


