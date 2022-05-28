/*
	Problem SPLC: "RNA Splicing"

	Lucho-D
	28 may. 2022-13:45:10
 */

#include "libRosalind.h"
#define MAX_LEN 1001
#define RNA_CODONS 64

void DNA_to_mRNA(char *DNA, char introns[][MAX_LEN], char *mRNA){
	int cont=0,indFound=-1;
	while(strcmp(introns[cont],"")!=0){
		for(int i=0;i<strlen(DNA)-1;i++){
			indFound=i;
			for(int j=0;j<strlen(introns[cont]);j++){
				if(DNA[i+j]!=introns[cont][j]){
					indFound=-1;
					break;
				}
			}
			if(indFound!=-1){
				for(int k=indFound;k<indFound+strlen(introns[cont]);k++) DNA[k]=' ';
			}
		}
		cont++;
	}
	cont=0;
	for(int i=0;i<strlen(DNA);i++){
		if(DNA[i]!=' '){
			mRNA[cont]=(DNA[i]!='T')?(DNA[i]):('U');
			cont++;
		}
	}
}

void mRNA_to_protein(char *mRNA, char *protein){
	char rnaCodons[RNA_CODONS][4]= {"UUUF","CUUL","AUUI","GUUV",
			"UUCF","CUCL","AUCI","GUCV",
			"UUAL","CUAL","AUAI","GUAV",
			"UUGL","CUGL","AUGM","GUGV",
			"UCUS","CCUP","ACUT","GCUA",
			"UCCS","CCCP","ACCT","GCCA",
			"UCAS","CCAP","ACAT","GCAA",
			"UCGS","CCGP","ACGT","GCGA",
			"UAUY","CAUH","AAUN","GAUD",
			"UACY","CACH","AACN","GACD",
			"UAA/","CAAQ","AAAK","GAAE",
			"UAG/","CAGQ","AAGK","GAGE",
			"UGUC","CGUR","AGUS","GGUG",
			"UGCC","CGCR","AGCS","GGCG",
			"UGA/","CGAR","AGAR","GGAG",
			"UGGW","CGGR","AGGR","GGGG"};
	int contInd=0, stop=0;
	for(int i=0;stop==0;i+=3,contInd++){
		for(int j=0;j<RNA_CODONS;j++){
			if(mRNA[i]==rnaCodons[j][0] && mRNA[i+1]==rnaCodons[j][1] && mRNA[i+2]==rnaCodons[j][2]){
				if(rnaCodons[j][3]=='/'){
					protein[contInd]='\0';
					stop=1;
					break;
				}
				protein[contInd]=rnaCodons[j][3];
				break;
			}
		}
	}
}

void SPLC(void){
	time_t tInit=clock();
	FILE *f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\SPLC\\rosalind_splc.txt","r");
	if(f==NULL){
		perror("WTFFFF??? hhahah");
		exit(EXIT_FAILURE);
	}
	char DNA[MAX_LEN]={'\0'},aux[MAX_LEN]={'\0'};
	char introns[MAX_LEN][MAX_LEN]={{'\0'}};
	int cont=0, indDNA=0, indIntrons=0;
	while(fgets(aux,MAX_LEN,f)){
		if(aux[0]=='>'){
			cont++;
			continue;
		}
		if(cont==1){
			for(int i=0;i<strlen(aux)-1;i++,indDNA++) DNA[indDNA]=aux[i];
		}else{
			for(int i=0;i<strlen(aux)-1;i++) introns[indIntrons][i]=aux[i];
			indIntrons++;
		}
	}
	fclose(f);
	char mRNA[MAX_LEN]={'\0'};
	DNA_to_mRNA(DNA,introns,mRNA);
	char *protein=(char *) malloc(strlen(mRNA)/3 * sizeof(char));
	for(int i=0;i<strlen(mRNA)/3;i++) protein[i]='\0';
	mRNA_to_protein(mRNA,protein);
	time_t tEnd=clock();
	printf("\n\nProblem SPLC.c: \n\n");
	printf("%s",protein);
	printf("\n\nElapsed Time: %.3f\n\n", (double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
