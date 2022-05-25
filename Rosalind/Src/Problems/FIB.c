/*
	Rosalind Project
	FIB.c
	4 may. 2019-19:41:25
	L
*/

#include "libRosalind.h"

void FIB(void){
	time_t tInit=clock();
	double resp=fibonacci(33,2);
    time_t tEnd=clock();
    printf("Problem FIB - Result: %.0f. Elapsed Time: %.6f\n", resp,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
