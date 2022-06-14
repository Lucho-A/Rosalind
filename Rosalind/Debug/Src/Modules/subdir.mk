################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Modules/libRosalindModule.c 

C_DEPS += \
./Src/Modules/libRosalindModule.d 

OBJS += \
./Src/Modules/libRosalindModule.o 


# Each subdirectory must supply rules for building sources it contributes
Src/Modules/%.o: ../Src/Modules/%.c Src/Modules/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"C:\Users\Lucho-D\git\Rosalind\Rosalind\Src\Headers" -O0 -g3 -Wall -c -fmessage-length=0 -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Src-2f-Modules

clean-Src-2f-Modules:
	-$(RM) ./Src/Modules/libRosalindModule.d ./Src/Modules/libRosalindModule.o

.PHONY: clean-Src-2f-Modules

