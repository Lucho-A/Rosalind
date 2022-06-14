/*
	Problem LEXV: "Ordering Strings of Varying Length Lexicographically"

	Lucho-D
	10 jun. 2022-18:56:21
*/

#include "libRosalind.h"
#define MAX_N 3

void LEXV(void){
	printf("\n\nProblem LEXV:\n\n");
	char *symb="DNA";
	FILE *f=NULL;
	open_file("LEXV","permutations.txt",&f,"w");
	int totPermuts=0,symbLen=strlen(symb);
	for(int i=1;i<=MAX_N;i++){
		int permuts=pow(symbLen,i);
		char **r=(char **)malloc(permuts*sizeof(char**));
		for(int i=0;i<permuts;i++) r[i]=(char *)malloc(symbLen*sizeof(char*));
		for(int i=0;i<permuts;i++){
			for(int j=0;j<symbLen;j++) r[i][j]='\0';
		}
		int lexiCount=lexicographic_r_permutations(symb, i, r);
		for(int i=0;i<lexiCount;i++) fprintf(f,"%s\n", r[i]);
		totPermuts+=lexiCount;
		free(r);
	}
	fclose(f);
	char **permuts=(char **)malloc(totPermuts*sizeof(char**));
	char *aux=(char *)malloc(symbLen*sizeof(char*));
	for(int i=0;i<totPermuts;i++) permuts[i]=(char *)malloc(symbLen*sizeof(char*));
	for(int i=0;i<totPermuts;i++){
		for(int j=0;j<symbLen;j++){
			permuts[i][j]='\0';
			aux[j]='\0';
		}
	}
	open_file("LEXV", "permutations.txt", &f, "r");
	int i=0;
	while(fscanf(f,"%s",aux)!=EOF){
			strcpy(permuts[i],aux);
			i++;
	}
	for(int i=0;i<totPermuts;i++) printf("%s\n", permuts[i]);
	return;
}
