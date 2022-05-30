/*
	Problem REVP: "Locating Restriction Sites"

	Lucho-D
	29 may. 2022-20:31:12
 */

#include "libRosalind.h"

void REVP(void){
	time_t tInit=clock();
	char DNA[2][MAX_LEN]={{'\0'}}, aux[MAX_LEN]={'\0'};
	FILE *f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\REVP\\rosalind_revp.txt","r");
	if(f==NULL){
		perror("File error\n");
		exit(EXIT_FAILURE);
	}
	int cont=0;
	while(fgets(aux,MAX_LEN,f)){
		if(aux[0]=='>') continue;
		for(int i=0;i<strlen(aux)-1;i++,cont++) DNA[0][cont]=aux[i];
	}
	fclose(f);
	f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\REVP\\rosalind_revp_RESP.txt","w");
	reverse_DNA(DNA);
	int reversePalindromePositions[MAX_ROWS][2]={{0}};
	find_DNA_reverse_palindromes(DNA, reversePalindromePositions);
	for(int i=0;reversePalindromePositions[i][0]!=0;i++) fprintf(f,"%d %d\n",reversePalindromePositions[i][0],reversePalindromePositions[i][1]);
	fclose(f);
	time_t tEnd=clock();
	printf("\n\nProblem REVP: Elapsed Time: %.3f\n\n", (double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
