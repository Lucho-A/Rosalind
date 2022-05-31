/*
	Problem TRAN: "Certain Point Mutations are More Common"

	Lucho-D
	28 may. 2022-17:22:54
*/

#include "../Headers/libRosalind.h"
#define LEN 1001

void TRAN(void){
	FILE *f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\TRAN\\rosalind_tran.txt","r");
	if(f==NULL){
		perror("File error\n");
		exit(EXIT_FAILURE);
	}
	char s[2][LEN]={{'\0'}}, aux[LEN]={'\0'};
	int contS=-1, ind=0;
	while(fgets(aux,LEN,f)){
		if(aux[0]=='>'){
			contS++;
			ind=0;
			continue;
		}
		for(int i=0;i<strlen(aux)-1;i++,ind++) s[contS][ind]=aux[i];
	}
	fclose(f);
	double ttr=transition_transversion_ratio(s[0], s[1]);
	printf("\n\nProblem TRAN: \n\n");
	printf("%.11f",ttr);
	return;
}
