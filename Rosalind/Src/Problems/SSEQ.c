/*
	Problem SSEQ: "Finding a Spliced Motif"

	Lucho-D
	30 may. 2022-13:02:19
 */

#include "libRosalind.h"

void SSEQ(void){
	char DNA[MAX_LEN]={'\0'}, ssDNA[MAX_LEN]={'\0'}, aux[MAX_LEN]={'\0'};
	FILE *f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\SSEQ\\rosalind_sseq.txt","r");
	if(f==NULL){
		perror("File error\n");
		exit(EXIT_FAILURE);
	}
	int contR=-1, contC=0;
	while(fgets(aux,MAX_LEN,f)){
		if(aux[0]=='>'){
			contR++;
			contC=0;
			continue;
		}
		if(contR==0){
			for(int i=0;i<strlen(aux)-1;i++,contC++) DNA[contC]=aux[i];
		}else{
			for(int i=0;i<strlen(aux)-1;i++,contC++) ssDNA[contC]=aux[i];
		}
	}
	fclose(f);
	int *firstPositionFound=(int *)malloc(strlen(ssDNA)*sizeof(int));
	find_first_subsequence(DNA, ssDNA, firstPositionFound);
	f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\SSEQ\\rosalind_sseq_RESULT.txt","w");
	for(int i=0;i<strlen(ssDNA);i++) fprintf(f,"%d ", firstPositionFound[i]);
	fclose(f);
	printf("\n\nProblem SSEQ: OK.\n\n");
	return;
}
