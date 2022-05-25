/*
	Rosalind Project
	math.c
	4 may. 2019-14:01:43
	L
 */

#include "libRosalind.h"

double fibonacci(lu n, lu incr){
	double fibos[3]={0,1,1};
	for(int i=3;i<=n;i++){
		fibos[0]=fibos[1]*incr+fibos[2];
		fibos[1]=fibos[2];
		fibos[2]=fibos[0];
	}
	return fibos[0];
}

