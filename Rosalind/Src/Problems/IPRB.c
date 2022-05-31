/*
	Problem IPRB: "Mendel's First Law" (https://rosalind.info/problems/iprb/)

	Lucho-D
	24 may. 2022-12:42:33
 */

#include "libRosalind.h"
#define LEN 100000000.0

void IPRB(void){
	srand(time(NULL));
	int pobK=21,pobM=28,pobN=27;
	char *pobTotal= (char *) malloc((pobK+pobM+pobN)*sizeof(char));
	long int cont=0;
	for(long int i=0;i<pobK;i++,cont++) pobTotal[cont]='k';
	for(long int i=0;i<pobM;i++,cont++) pobTotal[cont]='m';
	for(long int i=0;i<pobN;i++,cont++) pobTotal[cont]='n';
	pobTotal[cont]='\0';
	long int r[2]={0},selectionOk=FALSE;
	char kF[2]="YY",mF[2]="Yy",nF[2]="yy",newInd[2]="xx";
	double dominantPhenotype=0.0;
	for(long int i=0;i<LEN;i++){
		selectionOk=0;
		while(selectionOk==FALSE){
			r[0]= rand()%strlen(pobTotal);
			r[1]= rand()%strlen(pobTotal);
			if(r[0]!=r[1]) selectionOk=TRUE;
		}
		for(int i=0;i<2;i++){
			switch(pobTotal[r[i]]){
			case 'k':
				newInd[i]=kF[rand()%2];
				break;
			case 'm':
				newInd[i]=mF[rand()%2];
				break;
			case 'n':
				newInd[i]=nF[rand()%2];
				break;
			default:
				break;
			}
		}
		if(newInd[0]=='Y'||newInd[1]=='Y') dominantPhenotype++;
	}
	printf("\n\nProblem IPRB: \n\n");
	printf("%.5f",(double)dominantPhenotype/LEN);
	return;
}
