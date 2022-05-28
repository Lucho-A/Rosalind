/*
	Problem HAMM: "Counting Point Mutations"

	Lucho-D
	25 may. 2022-15:32:00
*/

#include "libRosalind.h"

void HAMM(void){
	time_t tInit=clock();
	char *s="GAGCCTACTAACGGGAT";
	char *t="CATCGTAATGACGGCCT";
	int hammingDistance=hamming_distance(s, t);
	time_t tEnd=clock();
	printf("\n\nProblem HAMM: \n\n");
	printf("%d",hammingDistance);
	printf("\n\nElapsed Time: %.6f\n\n", (double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
