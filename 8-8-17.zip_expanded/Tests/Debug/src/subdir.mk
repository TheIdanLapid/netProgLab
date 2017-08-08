################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/TCPSocketTest.cpp \
../src/UDPSocketTest.cpp \
../src/main.cpp 

OBJS += \
./src/TCPSocketTest.o \
./src/UDPSocketTest.o \
./src/main.o 

CPP_DEPS += \
./src/TCPSocketTest.d \
./src/UDPSocketTest.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/TCPSocketTest.o: ../src/TCPSocketTest.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/user/Desktop/workspaceLab3/SocketUtils" -I"/home/user/Desktop/workspaceLab3/SocketUtils/src" -include"/home/user/Desktop/workspaceLab3/SocketUtils/src/UDPSocket.h" -include"/home/user/Desktop/workspaceLab3/SocketUtils/src/MThread.h" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/TCPSocketTest.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/UDPSocketTest.o: ../src/UDPSocketTest.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/user/Desktop/workspaceLab3/SocketUtils" -I"/home/user/Desktop/workspaceLab3/SocketUtils/src" -I"/home/user/Desktop/workspaceLab3/Tests/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/UDPSocketTest.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/main.o: ../src/main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/user/Desktop/workspaceLab3/SocketUtils" -I"/home/user/Desktop/workspaceLab3/SocketUtils/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/main.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


