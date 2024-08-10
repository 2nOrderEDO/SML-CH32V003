################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/ch32v00x_it.c \
../User/system_ch32v00x.c 

CPP_SRCS += \
../User/main.cpp 

OBJS += \
./User/ch32v00x_it.o \
./User/main.o \
./User/system_ch32v00x.o 

C_DEPS += \
./User/ch32v00x_it.d \
./User/system_ch32v00x.d 

CPP_DEPS += \
./User/main.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv-none-embed-gcc -march=rv32ec -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"/home/enrique/mrs_community-workspace/CH32V003F4U6/Debug" -I"/home/enrique/mrs_community-workspace/CH32V003F4U6/Core" -I"/home/enrique/mrs_community-workspace/CH32V003F4U6/User" -I"/home/enrique/mrs_community-workspace/CH32V003F4U6/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

User/%.o: ../User/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C++ Compiler'
	riscv-none-embed-g++ -march=rv32ec -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"/home/enrique/mrs_community-workspace/CH32V003F4U6/Debug" -I"/home/enrique/mrs_community-workspace/CH32V003F4U6/Core" -I"/home/enrique/mrs_community-workspace/CH32V003F4U6/User" -I"/home/enrique/mrs_community-workspace/CH32V003F4U6/Peripheral/inc" -std=gnu++2a -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


