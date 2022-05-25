/*
	Problem XXX: ""

	Lucho-D
	25 may. 2022-15:32:00
*/

#include "libRosalind.h"
#define N 

void HAMM(void){
	time_t tInit=clock();
	char *s1="GAGCCTACTAACGGGAT";
	char *s2="CATCGTAATGACGGCCT";
	int hammingDistance=0;
	for(int i=0;i<strlen(s1);i++){
		if(s1[i]!=s2[i]) hammingDistance++;
	}
	time_t tEnd=clock();
	printf("\n\nProblem HAMM: \n\n");
	printf("%d",hammingDistance);
	printf("\n\nElapsed Time: %.6f\n\n", (double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
