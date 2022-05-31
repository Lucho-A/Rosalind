/*
	Rosalind Project
	SUBS.c
	4 may. 2019-13:31:17
	L
*/

#include "../Headers/libRosalind.h"

void SUBS(void){
	char *s="CCGCGGACCGCGGATCCGCGGACTGCCGCGGAATGCCGCGGACCGCGGAAGATGTGCCCGCGGACACCCGCGGACCATACTTCCGCGGAAGGCCGCGGACCGCCGCGGACCGCGGACCGCGGACCGCACCCGCGGACACCGCGGATCCGCGGACACCGCGGATTCCGCGGAGGACCGCGGATTCCGCGGAGTTTCCGCACCGCGGACCCGCGGACGCCGCGGAACCCGCGGACCCGCGGACTCTTACTACATAGCCGCGGACCGCGGACATACCGCGGACAGCGGTTCCGCGGACCGCGGACCGCGGAACCGCGGAGGCCGCGGACTCCGCGGAGACCCCCGCGGATTTCCGCGGATTCCGCGGACCGCGGACACGCAGACCGCGGAAGTCTCCGCGGAATCCGCGGATGCCGCGGACCGCGGACCGCGGAACCGCGGAGCTCCGCGGAGTAGCCCGCGGACGCCGCGGACCGCGGAACCCGCGGATCCCGCGGAACCCCCGCGGACTCCGCGGATCCGCGGACCTCGCCGCGGACAACCGCGGATCCGCGGACTGCCGCGGACCGCGGAGCCGCGGACCCGCGGACTGTGCTCACGCCGCGGACCGCGGAGCTTGGCCCGCGGATGGCCGCGGATATCCGCGGAGCACCTACTTCCGCGGACCCTTTCCGCGGACTCCGCGGAGGGCCGCGGAACCGCGGATTCCGCGGACCTTCCGCGGATGCATCCCGCGGACCGCGGAGCCGCGGATCCGCGGAAGGACCCGCGGAGTTCCGCGGACCCCGCGGAACACCGCGGACCGCGGATATCATGCGAACTCCGCGGACAGACCGCGGAGAGCCGCGGAAGATCCGCGGAGCAAGCCCGCGGACCGCGGACCTACCGCGGACCGCGGAACCGCGGACCGCGGATGGCCGCGGACCGCGGAGCCCGCGGAAAGCCCTACTGATGCCGCGGATCCCGCGGA";
	char *t="CCGCGGACC";
	int *result=(int *) malloc(strlen(s)*sizeof(int));
	for(int i=0;i<strlen(s);i++) result[i]=-1;
	find_motif(s,t,result);
	printf("\n\nProblem SUBS: \n\n");
	for(int i=0;result[i]!=-1;i++) printf("%d ",result[i]);
	return;
}
