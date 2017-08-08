################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CLIHandler.cpp \
../src/TCPMSNClientCLI.cpp 

OBJS += \
./src/CLIHandler.o \
./src/TCPMSNClientCLI.o 

CPP_DEPS += \
./src/CLIHandler.d \
./src/TCPMSNClientCLI.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/eontorch/networkingProgrammingLabProject/30-7-17-works until send message.zip_expanded/TCPMSNClient/src" -I"/home/eontorch/networkingProgrammingLabProject/30-7-17-works until send message.zip_expanded/SocketUtils/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


