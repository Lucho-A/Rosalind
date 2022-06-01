/*
	Rosalind Project
	FIB.c
	4 may. 2019-19:41:25
	L
*/

#include "libRosalind.h"

void FIB(void){
	char *result=NULL;
	fibonacci(33,2,0,&result);
    printf("Problem FIB:\n\n");
    printf("%s\n\n", result); //2863311531
	return;
}
