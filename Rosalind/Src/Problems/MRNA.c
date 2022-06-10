/*
	Problem XXX: ""

	Lucho-D
	10 jun. 2022-00:48:49
*/

#include "libRosalind.h"
#define N 1000
#define MOD_LIMIT 1000000

void MRNA(void){
	printf("\n\nProblem MRNA: \n\n");
	FILE *f=NULL;
	open_file("MRNA", "rosalind_mrna.txt", &f, "r");
	char *protein=NULL, aux[MAX_LEN]="";
	int idx=0;
	initStrV(&protein, N, '\0');
	while(fgets(aux,MAX_LEN,f)!=NULL){
		for(int i=0;i<strlen(aux)-1;i++,idx++) protein[idx]=aux[i];
	}
	protein[idx]='/';
	int *proteinCount=NULL, proteinLen=strlen(protein);
	initIntV(&proteinCount,proteinLen, 0);
	long int multi=1;
	for(int i=0;i<proteinLen;i++){
		for(int j=0;j<64;j++){
			if(codons[j][3]==protein[i]) proteinCount[i]++;
		}
		multi*=proteinCount[i];
		if(multi>MOD_LIMIT) multi%=MOD_LIMIT;
	}
	printf("%lu\n",multi);
	return;
}
