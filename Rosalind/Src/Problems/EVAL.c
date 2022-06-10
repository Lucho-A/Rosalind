/*
	Problem EVAL: "Expected Number of Restriction Sites"

	Lucho-D
	10 jun. 2022-13:31:53
*/

#include "libRosalind.h"

#define DNA_LEN 10
#define GC_LEN 20

void EVAL(void){
	printf("\n\nProblem EVAL: \n\n");
	int n=0, i=0;
	char DNA[DNA_LEN]="";
	double gcContent[GC_LEN]={0.0};
	FILE *f=NULL;
	open_file("EVAL","rosalind_eval.txt",&f,"r");
	fscanf(f,"%d",&n);
	fscanf(f,"%s",DNA);
	while(fscanf(f,"%lf ",&gcContent[i])!=EOF) i++;
	fclose(f);
	int dnaLen=strlen(DNA);
	double DNAp=1.0;
	for(int l=0;l<i;l++){
		for(int j=0;j<dnaLen;j++) DNAp*=(DNA[j]=='A'||DNA[j]=='T')?((1.0-gcContent[l])/2.0):((gcContent[l]/2.0));
		printf("%.3lf ",DNAp*(n-dnaLen+1));
		DNAp=1.0;
	}
	return;
}
