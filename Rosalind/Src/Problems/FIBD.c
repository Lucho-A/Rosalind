/*
	Problem FIBD: "Mortal Fibonacci Rabbits"

	Lucho-D
	30 may. 2022-15:04:01
*/

#include "libRosalind.h"
#define MONTHS_TO_EVAL 88
#define RABBITS_PAIRS_PER_GEN 1
#define EXPECTATIOM_RABBITS_LIFE 16

void FIBD(void){
	char *totalRabbits=NULL;
	fibonacci(MONTHS_TO_EVAL, RABBITS_PAIRS_PER_GEN, EXPECTATIOM_RABBITS_LIFE, &totalRabbits);
	printf("\n\nProblem FIBD: \n\n");
	printf("%s\n\n", totalRabbits); 	//1083713730914271201 88-16: OK
	return;
}
