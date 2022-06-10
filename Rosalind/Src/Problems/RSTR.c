/*
	Problem RSTR: "Matching Random Motifs"

	Lucho-D
	7 jun. 2022-15:54:52
 */

#include "libRosalind.h"
#define N 95922
#define LEN 10
#define GC_PERC 0.595997

void RSTR(void){
	printf("\n\nProblem RSTR: \n\n");
	char DNA[LEN]="ACCCCAGG";
	int lenS=strlen(DNA);
	double p=1.0;
	for(int i=0;i<lenS;i++) p*=(DNA[i]=='A'||DNA[i]=='T')?((1-GC_PERC)/2):(GC_PERC/2);
	printf("\nResult: %.3f",1-pow(1-p,N));
	return;
}
