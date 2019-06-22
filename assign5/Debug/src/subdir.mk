################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/assign5.cpp \
../src/btree.cpp \
../src/linked.cpp \
../src/queue.cpp 

OBJS += \
./src/assign5.o \
./src/btree.o \
./src/linked.o \
./src/queue.o 

CPP_DEPS += \
./src/assign5.d \
./src/btree.d \
./src/linked.d \
./src/queue.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


