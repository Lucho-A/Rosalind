/*
	Rosalind Project
	math.c
	4 may. 2019-14:01:43
	L
 */

#include "libRosalind.h"

double fibonacci(lu n){
	double *fibos=malloc(sizeof(double)*n);
	fibos[1]=1;
	fibos[2]=1;
	for(int i=3;i<n;i++) fibos[i]=fibos[i-1]+fibos[i-2];
	return fibos[n];
}
