################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CLIHandler.cpp \
../src/TCPMSNServerTest.cpp \
../src/TCPSocketTest.cpp \
../src/UDPSocketTest.cpp \
../src/main.cpp 

OBJS += \
./src/CLIHandler.o \
./src/TCPMSNServerTest.o \
./src/TCPSocketTest.o \
./src/UDPSocketTest.o \
./src/main.o 

CPP_DEPS += \
./src/CLIHandler.d \
./src/TCPMSNServerTest.d \
./src/TCPSocketTest.d \
./src/UDPSocketTest.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/eontorch/networkingProgrammingLabProject/30-7-17-works until send message.zip_expanded/SocketUtils/src" -I"/home/eontorch/networkingProgrammingLabProject/30-7-17-works until send message.zip_expanded/TCPMSNClient/src" -I"/home/eontorch/networkingProgrammingLabProject/30-7-17-works until send message.zip_expanded/TCPMSNServer/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


