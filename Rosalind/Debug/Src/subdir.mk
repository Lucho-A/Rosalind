################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Rosalind.c 

C_DEPS += \
./Src/Rosalind.d 

OBJS += \
./Src/Rosalind.o 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/lucho/git/Rosalind/Rosalind/Src/Headers" -O0 -g3 -Wall -c -fmessage-length=0 -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Src

clean-Src:
	-$(RM) ./Src/Rosalind.d ./Src/Rosalind.o

.PHONY: clean-Src

