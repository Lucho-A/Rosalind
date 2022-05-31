/*
	Problem ORF: "Transcription May Begin Anywhere"

	Lucho-D
	29 may. 2022-00:25:54
 */

#include "libRosalind.h"

void ORF(void){
	FILE *f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\ORF\\rosalind_orf.txt","r");
	if(f==NULL){
		perror("File error\n");
		exit(EXIT_FAILURE);
	}
	char DNA[2][MAX_LEN]={{'\0'}}, aux[MAX_LEN]={'\0'}, orfs[MAX_ROWS][MAX_LEN]={{'\0'}};
	int cont=0;
	while(fgets(aux,MAX_LEN,f)){
		if(aux[0]=='>') continue;
		for(int i=0;i<strlen(aux)-1;i++,cont++) DNA[0][cont]=aux[i];
	}
	reverse_DNA(DNA);
	generate_ORF(DNA, orfs);
	printf("\n\nProblem ORF: \n");
	for(int i=0;strcmp(orfs[i],"")!=0;i++){
		char protein[MAX_LEN]="";
		mRNA_to_protein(orfs[i], protein);
		printf("\n%s",protein);
	}
	return;
}
