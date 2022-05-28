/*
	Problem KMP: "Speeding Up Motif Finding"

	Lucho-D
	26 may. 2022-18:34:17
 */

#include "libRosalind.h"
#define MAX_LEN	100000

void KMP(void){
	time_t tInit=clock();
	FILE *f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\KMP\\rosalind_kmp.txt","r");
	if(f==NULL){
		perror("File not found!");
		exit(EXIT_FAILURE);
	}
	char sAux[MAX_LEN]={'\0'}, s[MAX_LEN]={'\0'};
	int cont=0;
	while(fgets(sAux,MAX_LEN,f)){
		if(sAux[0]!='>'){
			for(int i=0;i<strlen(sAux);i++){
				if(sAux[i]!='\n'){
					s[cont]=sAux[i];
					cont++;
				}
			}
		}
	}
	s[cont]='\n';
	fclose(f);
	f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\KMP\\Result.txt","w");
	if(f==NULL){
		perror("File not found!");
		exit(EXIT_FAILURE);
	}
	int lenS=strlen(s)-1,pos=0;
	cont=0;
	fprintf(f,"%d",0);
	for(int i=1;i<lenS;i++){
		if(s[i]==s[cont]){
			fprintf(f," %d",cont+1);
			if(cont==0) pos=i;
			cont++;
		}else{
			while(pos<=i && cont!=0){
				pos++;
				int ok=1,aux=pos;
				for(int j=0;j<cont;j++){
					if(s[aux]!=s[j]){
						ok=0;
						break;
					}
					aux++;
				}
				if(ok==0){
					cont--;
				}else{
					break;
				}
			}
			fprintf(f," %d",cont);
		}
	}
	fclose(f);
	time_t tEnd=clock();
	printf("\n\nProblem KMP. Elapsed Time: %.3f\n\n", (double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
