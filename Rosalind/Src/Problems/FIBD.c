/*
	Problem FIBD: "Mortal Fibonacci Rabbits"

	Lucho-D
	30 may. 2022-15:04:01
*/

#include "../Headers/libRosalind.h"
#define MONTHS_TO_EVAL 9
#define EXPECTATIOM_RABBITS_LIFE 3
#define RABBITS_PAIRS_PER_GEN 1

void FIBD(void){
	long int totalRabbits=fibonacci(MONTHS_TO_EVAL, RABBITS_PAIRS_PER_GEN, EXPECTATIOM_RABBITS_LIFE);
	printf("\n\nProblem FIBD: \n\n");
	printf("%ld", totalRabbits);
	return;
}
