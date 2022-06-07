/*
	Problem LGIS: "Longest Increasing Subsequence"

	Lucho-D
	2 jun. 2022-00:41:06
 */

#include "libRosalind.h"
#define MAX_N 20001
#define INCR 0
#define DECR 1

int subsequenceLen(int *v){
	int i=0;
	for(i=0;v[i]!=0;i++);
	return i;
}

void find_longest_subsequence(int *pi, int *longestSubsequenceResult, int incrDecr){
	int maxLen=0,found=FALSE,n=0,lastInd=0;
	double tot=pi[0];
	for(int i=1;pi[i+1]!=0;i++){
		printf("\n%.3f %%\n",(double)(i/tot)*100.0);
		switch(incrDecr){
				case INCR:
					if(pi[i]>=n && n!=0) continue;
					break;
				case DECR:
					if(pi[i]<=n && n!=0) continue;
					break;
				default:
					break;
		}
		printf("\n%d (%d)\n",pi[i], lastInd);
		fflush(stdout);
		for(int j=lastInd;pi[j+1]!=0;j++){
			int contInd=0,aux[MAX_N]={0};
			found=FALSE;
			aux[contInd]=pi[i];
			for(int k=j+1;pi[k]!=0;k++){
				switch(incrDecr){
				case INCR:
					if(aux[contInd]<pi[k]){
						if(found==FALSE){
							j=k;
							found=TRUE;
						}
						contInd++;
						aux[contInd]=pi[k];
					}
					break;
				case DECR:
					if(aux[contInd]>pi[k]){
						if(found==FALSE){
							j=k;
							found=TRUE;
						}
						contInd++;
						aux[contInd]=pi[k];
					}
					break;
				default:
					break;
				}
				int len=subsequenceLen(aux);
				if(len>maxLen){
					n=pi[i];
					maxLen=len;
					int i=0;
					for(i=0;aux[i]!=0;i++) longestSubsequenceResult[i]=aux[i];
					int n=aux[i-1];
					for(i=0;pi[i]!=0;i++){
						// TODO if
						if(pi[i]==n) lastInd=i;
					}
				}
			}
		}
	}
}

void LGIS(void){
	printf("\nProblem LGIS: ");
	//FILE *f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\LGIS\\rosalind_lgis0.txt","r");
	FILE *f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\LGIS\\SampleDataset3.txt","r");
	if(f==NULL){
		perror("File error\n");
		exit(EXIT_FAILURE);
	}
	int pi[MAX_N]={0},i=0;
	while(fscanf(f, " %d", &pi[i])!=EOF) i++;
	fclose(f);
	int maxIncr[MAX_N]={0}, maxDecr[MAX_N]={0};
	find_longest_subsequence(pi, maxIncr, INCR);
	//find_longest_subsequence(pi, maxDecr, DECR);
	f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\LGIS\\rosalind_lgisResult.txt","a");
	if(f==NULL){
		perror("File error\n");
		exit(EXIT_FAILURE);
	}
	for(int i=0;maxIncr[i]!=0;i++) (i==0)?(fprintf(f,"%d",maxIncr[i])):(fprintf(f," %d",maxIncr[i]));
	fprintf(f,"\n");
	//for(int i=0;maxDecr[i]!=0;i++) (i==0)?(fprintf(f,"%d",maxDecr[i])):(fprintf(f," %d",maxDecr[i]));;
	fprintf(f,"\n");
	fclose(f);
	return;
}
