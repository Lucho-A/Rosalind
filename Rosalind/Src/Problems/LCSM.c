/*
	Problem LCSM: "Finding a Shared Motif"

	Lucho-D
	24 may. 2022-19:27:20
 */

#include "libRosalind.h"
#define MAX_DNA_STRINGS 2000
#define MAX_LINE_LEN 1000

void LCSM(void){
	FILE *fp = fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\LCSM\\rosalind_lcsm.txt", "r");
	if(fp==NULL){
		printf("File not found\n");
		exit(EXIT_FAILURE);
	}
	int contLines=0;
	char lines[MAX_DNA_STRINGS][MAX_LINE_LEN]={""};
	while(fgets(lines[contLines], MAX_LINE_LEN, fp)!=NULL) contLines++;
	fclose(fp);
	int dnaStrings=0;
	for(int i=0;strcmp(lines[i],"")!=0;i++){
		if(lines[i][0]=='>') dnaStrings++;
	}
	char **dnaStringsMatrix=(char **) malloc(dnaStrings * sizeof(char*));
	for(int i=0;i<dnaStrings;i++) dnaStringsMatrix[i]=(char *) malloc(MAX_LINE_LEN * sizeof(char));
	for(int i=0;i<dnaStrings;i++){
		for(int j=0;j<MAX_LINE_LEN;j++) dnaStringsMatrix[i][j]='\0';
	}
	int contR=0, contC=0;
	for(int i=1;strcmp(lines[i],"")!=0;i++){
		if(lines[i][0]=='>'){
			contR++;
			contC=0;
			continue;
		}
		for(int j=0;lines[i][j]!='\n';j++,contC++) dnaStringsMatrix[contR][contC]=lines[i][j];
	}
	char *sAux=(char *) malloc(strlen(dnaStringsMatrix[0])*sizeof(char));
	char *maxStringFound=(char *) malloc(strlen(dnaStringsMatrix[0])*sizeof(char));
	for(int i=0;i<strlen(dnaStringsMatrix[0]);i++) maxStringFound[i]='\0';
	int index=1, strFound=TRUE;
	for(int i=0;i<strlen(dnaStringsMatrix[0]);i++){
		for(int i=0;i<strlen(dnaStringsMatrix[0]);i++) sAux[i]='\0';
		sAux[0]=dnaStringsMatrix[0][i];
		index=1;
		strFound=TRUE;
		for(int j=i+1;j<strlen(dnaStringsMatrix[0]);j++,index++){
			sAux[index]=dnaStringsMatrix[0][j];
			if(strlen(sAux)<strlen(maxStringFound)) continue;
			for(int i=1;i<dnaStrings;i++){
				if(strstr(dnaStringsMatrix[i],sAux)==NULL){
					strFound=FALSE;
					break;
				}
			}
			if(strFound==TRUE && strlen(sAux)>strlen(maxStringFound)) strcpy(maxStringFound,sAux);
		}
	}
	printf("\n\nProblem LCSM: \n\n");
	printf("%s",maxStringFound);
	return;
}
