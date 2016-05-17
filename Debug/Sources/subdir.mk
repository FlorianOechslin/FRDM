################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Application.c \
../Sources/Debounce.c \
../Sources/Event.c \
../Sources/Events.c \
../Sources/KeyDebounce.c \
../Sources/Keys.c \
../Sources/LED.c \
../Sources/LineFollow.c \
../Sources/MCP4728.c \
../Sources/NVM_Config.c \
../Sources/Pid.c \
../Sources/Platform.c \
../Sources/QuadCalib.c \
../Sources/RNet_App.c \
../Sources/RTOS.c \
../Sources/Remote.c \
../Sources/Sem.c \
../Sources/Shell.c \
../Sources/ShellQueue.c \
../Sources/Timer.c \
../Sources/Trigger.c \
../Sources/main.c 

OBJS += \
./Sources/Application.o \
./Sources/Debounce.o \
./Sources/Event.o \
./Sources/Events.o \
./Sources/KeyDebounce.o \
./Sources/Keys.o \
./Sources/LED.o \
./Sources/LineFollow.o \
./Sources/MCP4728.o \
./Sources/NVM_Config.o \
./Sources/Pid.o \
./Sources/Platform.o \
./Sources/QuadCalib.o \
./Sources/RNet_App.o \
./Sources/RTOS.o \
./Sources/Remote.o \
./Sources/Sem.o \
./Sources/Shell.o \
./Sources/ShellQueue.o \
./Sources/Timer.o \
./Sources/Trigger.o \
./Sources/main.o 

C_DEPS += \
./Sources/Application.d \
./Sources/Debounce.d \
./Sources/Event.d \
./Sources/Events.d \
./Sources/KeyDebounce.d \
./Sources/Keys.d \
./Sources/LED.d \
./Sources/LineFollow.d \
./Sources/MCP4728.d \
./Sources/NVM_Config.d \
./Sources/Pid.d \
./Sources/Platform.d \
./Sources/QuadCalib.d \
./Sources/RNet_App.d \
./Sources/RTOS.d \
./Sources/Remote.d \
./Sources/Sem.d \
./Sources/Shell.d \
./Sources/ShellQueue.d \
./Sources/Timer.d \
./Sources/Trigger.d \
./Sources/main.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/Users/Florian/Desktop/Studium/6.Semester/INTRO/KDS/FRDM/Static_Code/PDD" -I"/Users/Florian/Desktop/Studium/6.Semester/INTRO/KDS/FRDM/Static_Code/IO_Map" -I"/Users/Florian/Desktop/Studium/6.Semester/INTRO/KDS/FRDM/Sources" -I"/Users/Florian/Desktop/Studium/6.Semester/INTRO/KDS/FRDM/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


