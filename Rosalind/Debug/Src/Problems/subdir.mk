################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Problems/CONS.c \
../Src/Problems/DNA.c \
../Src/Problems/EVAL.c \
../Src/Problems/FIB.c \
../Src/Problems/FIBD.c \
../Src/Problems/FIBO.c \
../Src/Problems/GC.c \
../Src/Problems/GRPH.c \
../Src/Problems/HAMM.c \
../Src/Problems/IEV.c \
../Src/Problems/INI.c \
../Src/Problems/IPRB.c \
../Src/Problems/KMER.c \
../Src/Problems/KMP.c \
../Src/Problems/LCSM.c \
../Src/Problems/LEXF.c \
../Src/Problems/LEXV.c \
../Src/Problems/LGIS.c \
../Src/Problems/LIA.c \
../Src/Problems/MPRT.c \
../Src/Problems/MRNA.c \
../Src/Problems/ORF.c \
../Src/Problems/PERM.c \
../Src/Problems/PROB.c \
../Src/Problems/PROT.c \
../Src/Problems/PRTM.c \
../Src/Problems/REVC.c \
../Src/Problems/REVP.c \
../Src/Problems/RNA.c \
../Src/Problems/RSTR.c \
../Src/Problems/SPEC.c \
../Src/Problems/SPLC.c \
../Src/Problems/SSEQ.c \
../Src/Problems/SUBS.c \
../Src/Problems/TRAN.c 

C_DEPS += \
./Src/Problems/CONS.d \
./Src/Problems/DNA.d \
./Src/Problems/EVAL.d \
./Src/Problems/FIB.d \
./Src/Problems/FIBD.d \
./Src/Problems/FIBO.d \
./Src/Problems/GC.d \
./Src/Problems/GRPH.d \
./Src/Problems/HAMM.d \
./Src/Problems/IEV.d \
./Src/Problems/INI.d \
./Src/Problems/IPRB.d \
./Src/Problems/KMER.d \
./Src/Problems/KMP.d \
./Src/Problems/LCSM.d \
./Src/Problems/LEXF.d \
./Src/Problems/LEXV.d \
./Src/Problems/LGIS.d \
./Src/Problems/LIA.d \
./Src/Problems/MPRT.d \
./Src/Problems/MRNA.d \
./Src/Problems/ORF.d \
./Src/Problems/PERM.d \
./Src/Problems/PROB.d \
./Src/Problems/PROT.d \
./Src/Problems/PRTM.d \
./Src/Problems/REVC.d \
./Src/Problems/REVP.d \
./Src/Problems/RNA.d \
./Src/Problems/RSTR.d \
./Src/Problems/SPEC.d \
./Src/Problems/SPLC.d \
./Src/Problems/SSEQ.d \
./Src/Problems/SUBS.d \
./Src/Problems/TRAN.d 

OBJS += \
./Src/Problems/CONS.o \
./Src/Problems/DNA.o \
./Src/Problems/EVAL.o \
./Src/Problems/FIB.o \
./Src/Problems/FIBD.o \
./Src/Problems/FIBO.o \
./Src/Problems/GC.o \
./Src/Problems/GRPH.o \
./Src/Problems/HAMM.o \
./Src/Problems/IEV.o \
./Src/Problems/INI.o \
./Src/Problems/IPRB.o \
./Src/Problems/KMER.o \
./Src/Problems/KMP.o \
./Src/Problems/LCSM.o \
./Src/Problems/LEXF.o \
./Src/Problems/LEXV.o \
./Src/Problems/LGIS.o \
./Src/Problems/LIA.o \
./Src/Problems/MPRT.o \
./Src/Problems/MRNA.o \
./Src/Problems/ORF.o \
./Src/Problems/PERM.o \
./Src/Problems/PROB.o \
./Src/Problems/PROT.o \
./Src/Problems/PRTM.o \
./Src/Problems/REVC.o \
./Src/Problems/REVP.o \
./Src/Problems/RNA.o \
./Src/Problems/RSTR.o \
./Src/Problems/SPEC.o \
./Src/Problems/SPLC.o \
./Src/Problems/SSEQ.o \
./Src/Problems/SUBS.o \
./Src/Problems/TRAN.o 


# Each subdirectory must supply rules for building sources it contributes
Src/Problems/%.o: ../Src/Problems/%.c Src/Problems/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/lucho/git/Rosalind/Rosalind/Src/Headers" -O0 -g3 -Wall -c -fmessage-length=0 -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Src-2f-Problems

clean-Src-2f-Problems:
	-$(RM) ./Src/Problems/CONS.d ./Src/Problems/CONS.o ./Src/Problems/DNA.d ./Src/Problems/DNA.o ./Src/Problems/EVAL.d ./Src/Problems/EVAL.o ./Src/Problems/FIB.d ./Src/Problems/FIB.o ./Src/Problems/FIBD.d ./Src/Problems/FIBD.o ./Src/Problems/FIBO.d ./Src/Problems/FIBO.o ./Src/Problems/GC.d ./Src/Problems/GC.o ./Src/Problems/GRPH.d ./Src/Problems/GRPH.o ./Src/Problems/HAMM.d ./Src/Problems/HAMM.o ./Src/Problems/IEV.d ./Src/Problems/IEV.o ./Src/Problems/INI.d ./Src/Problems/INI.o ./Src/Problems/IPRB.d ./Src/Problems/IPRB.o ./Src/Problems/KMER.d ./Src/Problems/KMER.o ./Src/Problems/KMP.d ./Src/Problems/KMP.o ./Src/Problems/LCSM.d ./Src/Problems/LCSM.o ./Src/Problems/LEXF.d ./Src/Problems/LEXF.o ./Src/Problems/LEXV.d ./Src/Problems/LEXV.o ./Src/Problems/LGIS.d ./Src/Problems/LGIS.o ./Src/Problems/LIA.d ./Src/Problems/LIA.o ./Src/Problems/MPRT.d ./Src/Problems/MPRT.o ./Src/Problems/MRNA.d ./Src/Problems/MRNA.o ./Src/Problems/ORF.d ./Src/Problems/ORF.o ./Src/Problems/PERM.d ./Src/Problems/PERM.o ./Src/Problems/PROB.d ./Src/Problems/PROB.o ./Src/Problems/PROT.d ./Src/Problems/PROT.o ./Src/Problems/PRTM.d ./Src/Problems/PRTM.o ./Src/Problems/REVC.d ./Src/Problems/REVC.o ./Src/Problems/REVP.d ./Src/Problems/REVP.o ./Src/Problems/RNA.d ./Src/Problems/RNA.o ./Src/Problems/RSTR.d ./Src/Problems/RSTR.o ./Src/Problems/SPEC.d ./Src/Problems/SPEC.o ./Src/Problems/SPLC.d ./Src/Problems/SPLC.o ./Src/Problems/SSEQ.d ./Src/Problems/SSEQ.o ./Src/Problems/SUBS.d ./Src/Problems/SUBS.o ./Src/Problems/TRAN.d ./Src/Problems/TRAN.o

.PHONY: clean-Src-2f-Problems

