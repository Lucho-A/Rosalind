/*
	Problem CONS

	Lucho-D
	23 may. 2022-16:14:55
 */

#include "libRosalind.h"

#define MAX_DNA_STRINGS 1000
#define MAX_LINE_LEN 1000
#define A 0
#define C 1
#define G 2
#define T 3

void CONS(void){
	time_t tInit=clock();
	int contLines=0;
	char line[MAX_DNA_STRINGS][MAX_LINE_LEN]={""};
	FILE *fp = fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\CONS\\rosalind_cons3.txt", "r");
	if(fp==NULL){
		printf("File not found\n");
		exit(EXIT_FAILURE);
	}
	while(fgets(line[contLines], MAX_LINE_LEN, fp)!=NULL) contLines++;
	fclose(fp);
	int len=0;
	for(int i=1;line[i][0]!='>';i++){
		for(int j=0;line[i][j]!='\n';j++) len++;
	}
	int dnaStrings=0;
	for(int i=0;strcmp(line[i],"")!=0;i++){
		if(line[i][0]=='>') dnaStrings++;
	}
	char **dnaStringsMatrix=(char **) malloc(dnaStrings * sizeof(char*));
	for(int i=0;i<dnaStrings;i++){
		dnaStringsMatrix[i]=(char *) malloc(len * sizeof(char));
	}
	for(int i=0;i<dnaStrings;i++){
		for(int j=0;j<len;j++){
			dnaStringsMatrix[i][j]=' ';
		}
	}
	char *consensus=(char *) malloc(len * sizeof(char));
	for(int i=0;i<len;i++) consensus[i]='\0';
	int *profile[4]={0};
	for(int i=0;i<4;i++) profile[i] = (int *) malloc(len * sizeof(int));
	for(int i=0;i<4;i++){
		for(int j=0;j<len;j++){
			profile[i][j]=0;
		}
	}
	int contR=0, contC=0;
	for(int i=1;strcmp(line[i],"")!=0;i++){
		if(line[i][0]=='>'){
			contR++;
			contC=0;
			continue;
		}
		for(int j=0;line[i][j]!='\n';j++,contC++) dnaStringsMatrix[contR][contC]=line[i][j];
	}
	int maxDNA=-1;
	for(int j=0;j<len;j++){
		maxDNA=-1;
		for(int i=0;i<dnaStrings;i++){
			switch(dnaStringsMatrix[i][j]){
			case 'A':
				profile[A][j]++;
				if(profile[A][j]>maxDNA){
					maxDNA=profile[A][j];
					consensus[j]='A';
				}
				break;
			case 'C':
				profile[C][j]++;
				if(profile[C][j]>maxDNA){
					maxDNA=profile[C][j];
					consensus[j]='C';
				}
				break;
			case 'G':
				profile[G][j]++;
				if(profile[G][j]>maxDNA){
					maxDNA=profile[G][j];
					consensus[j]='G';
				}
				break;
			case 'T':
				profile[T][j]++;
				if(profile[T][j]>maxDNA){
					maxDNA=profile[T][j];
					consensus[j]='T';
				}
				break;
			default:
				break;
			}
		}
	}
	time_t tEnd=clock();
	printf("Problem CONS - Result:\n\n");
	for(int i=0;i<len;i++) printf("%c", consensus[i]);
	printf("\nA: ");
	for(int i=0;i<len;i++) printf("%d ", profile[A][i]);
	printf("\nC: ");
	for(int i=0;i<len;i++) printf("%d ", profile[C][i]);
	printf("\nG: ");
	for(int i=0;i<len;i++) printf("%d ", profile[G][i]);
	printf("\nT: ");
	for(int i=0;i<len;i++) printf("%d ", profile[T][i]);
	printf("\n\nElapsed Time: %.6f\n", (double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
