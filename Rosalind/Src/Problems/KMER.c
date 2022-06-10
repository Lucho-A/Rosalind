/*
	Problem KMER: "k-Mer Composition"

	Lucho-D
	9 jun. 2022-17:50:26
 */

#include "libRosalind.h"
#define LEN		(100*1000)
#define R		4
#define SYMB	4
#define K		(pow(SYMB,R))

void KMER(void){
	printf("\n\nProblem KMER: ");
	FILE *f=NULL;
	open_file("KMER", "rosalind_kmer2.txt", &f, "r");
	char s[LEN]="", aux[MAX_LEN]="";
	int idx=0;
	while(fgets(aux,MAX_LEN,f)){
		if(aux[0]=='>') continue;
		for(int i=0;i<strlen(aux)-1;i++, idx++) s[idx]=aux[i];
	}
	char **kmers=(char **)malloc(K * sizeof(char*));
	for (int i=0;i<K;i++) kmers[i]=(char *)malloc(R*sizeof(char));
	char symbs[5]="ACGT";
	lexicographic_r_permutations(symbs, R, kmers);
	int *kmersCount=NULL;
	initIntV(&kmersCount, K, 0);
	int len=strlen(s)-1;
	for(int i=0;i<K;i++){
		for(int j=0;j<len-2;j++){
			bool foundIt=TRUE;
			for(int l=0;l<R;l++){
				if(s[j+l]!=kmers[i][l]){
					foundIt=FALSE;
					break;
				}
			}
			if(foundIt==TRUE) kmersCount[i]++;
		}
	}
	free(kmers);
	open_file("KMER", "KYMER_Result.txt", &f, "w");
	for(int i=0;i<K;i++) fprintf(f,"%d ",kmersCount[i]);
	fclose(f);
	free(kmersCount);
	return;
}
