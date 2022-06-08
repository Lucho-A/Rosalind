/*
	Problem IEV: "Calculating Expected Offspring"

	Lucho-D
	8 jun. 2022-14:37:29
 */

#include "libRosalind.h"
#define	N_COUPLES 6
#define	N_OFFSPRINGS 2

void IEV(void){
	printf("\n\nProblem IEV: \n\n");
	FILE *f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\IEV\\rosalind_iev.txt","r");
	if(f==NULL){
		perror("File error\n");
		exit(EXIT_FAILURE);
	}
	int pobl[N_COUPLES]={0},i=0;
	while(fscanf(f,"%d ",&pobl[i])!=EOF)i++;
	fclose(f);
	double sum=0.0,Pdomin[N_COUPLES]={1.0, 1.0, 1.0, 0.75, 0.5, 0.0};
	for(i=0;i<N_COUPLES;i++) sum+=Pdomin[i]*pobl[i]*N_OFFSPRINGS;
	printf("%.2f", sum);
	return;
}
