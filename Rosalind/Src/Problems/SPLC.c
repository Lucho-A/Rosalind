/*
	Problem SPLC: "RNA Splicing"

	Lucho-D
	28 may. 2022-13:45:10
 */

#include "libRosalind.h"
#define DNA_LEN 1001

void SPLC(void){
	FILE *f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\SPLC\\rosalind_splc.txt","r");
	if(f==NULL){
		perror("WTFFFF??? hhahah");
		exit(EXIT_FAILURE);
	}
	char DNA[DNA_LEN ]={'\0'},aux[DNA_LEN]={'\0'}, introns[DNA_LEN][MAX_LEN]={{'\0'}};
	int cont=0, indDNA=0, indIntrons=0;
	while(fgets(aux,DNA_LEN,f)){
		if(aux[0]=='>'){
			cont++;
			continue;
		}
		if(cont==1){
			for(int i=0;i<strlen(aux)-1;i++,indDNA++) DNA[indDNA]=aux[i];
		}else{
			for(int i=0;i<strlen(aux)-1;i++) introns[indIntrons][i]=aux[i];
			indIntrons++;
		}
	}
	fclose(f);
	char mRNA[DNA_LEN]={'\0'};
	DNA_to_mRNA(DNA,introns,mRNA);
	char *protein=(char *) malloc(strlen(mRNA)/3 * sizeof(char));
	for(int i=0;i<strlen(mRNA)/3;i++) protein[i]='\0';
	mRNA_to_protein(mRNA,protein);
	printf("\n\nProblem SPLC.c: \n\n");
	printf("%s",protein);
	return;
}
