/*
	Problem TRAN: "Certain Point Mutations are More Common"

	Lucho-D
	28 may. 2022-17:22:54
*/

#include "libRosalind.h"

void TRAN(void){
	time_t tInit=clock();
	FILE *f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\TRAN\\rosalind_tran.txt","r");
	if(f==NULL){
		perror("File error\n");
		exit(EXIT_FAILURE);
	}
	char s[2][MAX_LEN]={{'\0'}}, aux[MAX_LEN]={'\0'};
	int contS=-1, ind=0;
	while(fgets(aux,MAX_LEN,f)){
		if(aux[0]=='>'){
			contS++;
			ind=0;
			continue;
		}
		for(int i=0;i<strlen(aux)-1;i++,ind++) s[contS][ind]=aux[i];
	}
	fclose(f);
	double ttr=transition_transversion_ratio(s[0], s[1]);
	time_t tEnd=clock();
	printf("\n\nProblem TRAN: \n\n");
	printf("%.11f",ttr);
	printf("\n\nElapsed Time: %.3f\n\n", (double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
