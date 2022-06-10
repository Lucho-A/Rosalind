/*
	Problem TRAN: "Certain Point Mutations are More Common"

	Lucho-D
	28 may. 2022-17:22:54
*/

#include "libRosalind.h"
#define LEN 1001

void TRAN(void){
	printf("\n\nProblem TRAN: \n\n");
	FILE *f=NULL;
	open_file("TRAN","rosalind_tran.txt", &f,"r");
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
	printf("%.11f",ttr);
	return;
}
