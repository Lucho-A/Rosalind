/*
	Problem KMP: "Speeding Up Motif Finding"

	Lucho-D
	26 may. 2022-18:34:17
 */

#include "../Headers/libRosalind.h"
#define LEN	100000

void KMP(void){
	FILE *f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\KMP\\rosalind_kmp.txt","r");
	if(f==NULL){
		perror("File not found!");
		exit(EXIT_FAILURE);
	}
	char sAux[LEN]={'\0'}, s[LEN]={'\0'};
	int cont=0;
	while(fgets(sAux,LEN,f)){
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
	int failureArray[LEN]={0};
	find_failure_array(s, failureArray);
	printf("\n\nProblem KMP:\n\n");
	for(int i=0;i<cont;i++) fprintf(f,"%d ",failureArray[i]);
	fclose(f);
	return;
}
