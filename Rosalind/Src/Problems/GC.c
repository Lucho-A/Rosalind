/*
	Problem GC

	23 may. 2022
 */

#include "libRosalind.h"
#define MAX_LINE_LEN 1000
#define MAX_DNA_STRINGS 1000

void GC(void){
	time_t tInit=clock();
	FILE *fp;
	int contLine=0;
	char line[MAX_DNA_STRINGS][MAX_LINE_LEN]={""};
	fp=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\GC\\Dataset.txt", "r");
	if(fp == NULL){
		printf("File not found\n");
		exit(EXIT_FAILURE);
	}
	while(fgets(line[contLine], MAX_LINE_LEN, fp)!=NULL) contLine++;
	fclose(fp);
	double contCG=0.0, totalString=0.0, highestGC=0.0, porc=0.0;
	char maxID[MAX_LINE_LEN]="", id[MAX_LINE_LEN]="";
	for(int i=0;strcmp(line[i],"")!=0;i++){
		if(line[i][0]=='>'){
			porc=contCG/totalString;
			if(highestGC<porc){
				strcpy(maxID,id);
				highestGC=porc;
			}
			strcpy(id,line[i]);
			contCG=0.0;
			totalString=0.0;
			continue;
		}else{
			for(int j=0;line[i][j]!='\n';j++){
				if(line[i][j]=='C' || line[i][j]=='G') contCG++;
				totalString++;
			}
		}
	}
	porc=contCG/totalString;
	if(highestGC<porc){
		strcpy(maxID,id);
		highestGC=porc;
	}
	time_t tEnd=clock();
	printf("Problem GC - Result: \n\n%s%f. \n\nElapsed Time: %.6f\n",maxID, highestGC *100,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
