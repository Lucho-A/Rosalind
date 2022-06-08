/*
	Problem GRPH: "Overlap Graphs"

	Lucho-D
	8 jun. 2022-15:21:14
 */

#include "libRosalind.h"
#define	K 3

struct DNA{
	char dnaName[MAX_LEN];
	char dnaString[MAX_LEN];
};

void GRPH(void){
	printf("\n\nProblem GRPH: ");
	FILE *f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\GRPH\\rosalind_grph4.txt","r");
	if(f==NULL){
		perror("File error\n");
		exit(EXIT_FAILURE);
	}
	char dnaStringAux[MAX_LEN]="";
	int i=0,dnaCount=-1,idx=0;
	struct DNA dnas[700]={{"",""}};
	while(fgets(dnaStringAux,MAX_LEN,f)){
		if(dnaStringAux[0]=='>'){
			dnaCount++;
			for(i=1;i<strlen(dnaStringAux)-1;i++){
				if(dnaStringAux[i]!='\n') dnas[dnaCount].dnaName[i-1]=dnaStringAux[i];
			}
			idx=0;
			continue;
		}else{
			for(i=0;i<strlen(dnaStringAux)-1;i++, idx++){
				if(dnaStringAux[i]!='\n') dnas[dnaCount].dnaString[idx]=dnaStringAux[i];
			}
		}
	}
	f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\GRPH\\GRPH_result.txt","w");
	if(f==NULL){
		perror("File error\n");
		exit(EXIT_FAILURE);
	}
	bool isAdj=TRUE;
	for(i=0;strcmp(dnas[i].dnaName,"")!=0;i++){
		int len=strlen(dnas[i].dnaString)-1;
		for(int j=0;strcmp(dnas[j].dnaName,"")!=0;j++){
			if(i==j) continue;
			isAdj=TRUE;
			for(int l=len;l>len-K;l--){
				if(dnas[i].dnaString[l]!=dnas[j].dnaString[l-len+K-1]){
					isAdj=FALSE;
					break;
				}
			}
			if(isAdj==TRUE) fprintf(f,"%s %s\n",dnas[i].dnaName,dnas[j].dnaName);
		}
	}
	fclose(f);
	return;
}
