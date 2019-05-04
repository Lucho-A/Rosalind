/*
	Rosalind Project
	math.c
	4 may. 2019-14:01:43
	L
 */

#include "libRosalind.h"

double fibonacci(lu n, lu incr){
	double *fibos=malloc(sizeof(double)*n);
	int i=0;
	*(fibos)=0;
	*(fibos+1)=1;
	*(fibos+2)=1;
	double result=0;
	for(i=3;i<=n;i++) fibos[i]=(fibos[i-2]+fibos[i-1]);
	for(int j=2;j<n;j++){
		result+=fibos[j]*incr;
	}
	result++;
	printf("%f\n", result);
	return result;
}
