/*
	Problem HAMM: "Counting Point Mutations"

	Lucho-D
	25 may. 2022-15:32:00
*/

#include "libRosalind.h"

void HAMM(void){
	char *s="GAGCCTACTAACGGGAT";
	char *t="CATCGTAATGACGGCCT";
	int hammingDistance=hamming_distance(s, t);
	printf("\n\nProblem HAMM: \n\n");
	printf("%d",hammingDistance);
	return;
}
