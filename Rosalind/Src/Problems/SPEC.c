/*
	Problem SPEC: "Introduction to Mass Spectrometry"

	Lucho-D
	27 may. 2022-22:57:00
 */

#include "libRosalind.h"
#define N 101
#define PREC 0.001

void SPEC(void){
	time_t tInit=clock();
	FILE *f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\SPEC\\rosalind_spec.txt","r");
	if(f==NULL){
		perror("WTFFFF??? hhahah");
		exit(EXIT_FAILURE);
	}
	char alphabet[20]="ACDEFGHIKLMNPQRSTVWY";
	double alphabetWeights[20]={71.03711,103.00919,115.02694,129.04259,147.06841,57.02146,137.05891,113.08406,128.09496,
								113.08406,131.04049,114.04293,97.05276,128.05858,156.10111,87.03203,101.04768,99.06841,
								186.07931,163.06333};
	char protein[N]="", aux[N]="\0";
	double l[N]={0.0};
	int index=0, contN=0;
	while(fgets(aux,N,f)){
		l[contN]=strtod(aux,NULL);
		contN++;
	}
	fclose(f);
	double dif=0.0;
	for(int i=0;i<contN-1;i++){
		dif=l[i+1]-l[i];
		for(int j=0;j<strlen(alphabet);j++){
			if(dif-alphabetWeights[j]>-PREC && dif-alphabetWeights[j]<PREC){
				protein[index]=alphabet[j];
				index++;
				break;
			}
		}
	}
	(strlen(protein)==contN-1)?(printf("Lenghts OK")):(printf("Lenghts not OK"));
	time_t tEnd=clock();
	printf("\n\nProblem SPEC: \n\n");
	printf("%s",protein);
	printf("\n\nElapsed Time: %.3f\n\n", (double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
