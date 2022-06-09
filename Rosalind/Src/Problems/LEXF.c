/*
	Problem LEXF: "Enumerating k-mers Lexicographically"

	Lucho-D
	8 jun. 2022-21:10:59
 */

#include "libRosalind.h"
#define LEN 10

void lexicographic_r_permutations(char *orderedSymbols, int r, FILE *f){
	int n=strlen(orderedSymbols);
	int *idx=(int*)malloc(r*sizeof(int));
	for(int i=0;i<r;i++) idx[i]=0;
	while(TRUE){
		for(int c=0;c<r;c++) fprintf(f,"%c",orderedSymbols[idx[c]]);
		fprintf(f,"\n");
		idx[r-1]++;
		for(int i=r-1;i>=0;i--){
			if(idx[0]==n) return;
			if(idx[i]==n){
				idx[i]=0;
				idx[i-1]++;
			}
		}
	}
}

void LEXF(void){
	printf("\n\nProblem LEXF:");
	FILE *f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\LEXF\\rosalind_lexf.txt","r");
	if(f==NULL){
		perror("File error\n");
		exit(EXIT_FAILURE);
	}
	char symbols[LEN]={'\0'},auxS[LEN*2]={'\0'};
	int idx=0,r=0;
	fgets(auxS,LEN*2,f);
	for(int i=0;i<strlen(auxS)-1;i++){
		if(auxS[i]!=' '){
			symbols[idx]=auxS[i];
			idx++;
		}
	}
	fgets(auxS,LEN,f);
	fclose(f);
	r=auxS[0]-'0';
	f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\LEXF\\LEXF_result.txt","w");
	if(f==NULL){
		perror("File error\n");
		exit(EXIT_FAILURE);
	}
	lexicographic_r_permutations(symbols, r, f);
	fclose(f);
	return;
}
