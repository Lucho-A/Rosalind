/*
	Problem RSTR: "Matching Random Motifs"

	Lucho-D
	7 jun. 2022-15:54:52
 */

#include "libRosalind.h"
#define N 90000.0
#define LEN 10
#define GC_PERC 0.6

void RSTR(void){
	printf("\n\nProblem RSTR: \n\n");
	srand(time(0));
	char nucleobasesGC[2]="GC",nucleobasesAT[2]="AT";
	char DNA[LEN]="ATAGCCGA";
	char DNARandom[LEN]="XXXXXXXX";
	int lenS=strlen(DNA);
	double cont=0.0;
	int cc=floor(lenS*GC_PERC),k=0;
	for(k=0;k<N;k++){
		strcpy(DNARandom,"XXXXXXXX");
		/*for(int i=0;i<cc;i++){
			int r=(rand()%lenS);
			if(DNARandom[r]=='X'){
				DNARandom[r]=nucleobasesGC[rand()%2];
			}else{
				i--;
			}
		}
		for(int i=0;i<lenS;i++){
			if(DNARandom[i]=='X'){
				DNARandom[i]=nucleobasesAT[rand()%2];
			}
		}*/
		for(int i=0;i<lenS;i++){
			int r=((rand()%10)+1);
			//printf("(%d)\n", r);
			if(r<=4){
				DNARandom[i]=nucleobasesAT[rand()%2];
			}else{
				DNARandom[i]=nucleobasesGC[rand()%2];
			}
		}
		if(strcmp(DNARandom,DNA)==0){
			printf("%s (%d)\n", DNARandom,k);
			cont++;
		}
	}
	printf("\nResult: %.9f", cont/N);
	printf("\nResult: %.9f", log10(cont/N));
	printf("\nResult: %.3f", log10(0.2 + 0.2 + 0.2 + 0.3 + 0.3 + 0.3 + 0.3 + 0.2));
	printf("\nResult: %.3f", log10(0.2 * 0.2 * 0.2 * 0.3 * 0.3 * 0.3 * 0.3 * 0.2));
	printf("\nResult: %.6f", log10((0.2 * 0.2 * 0.2 * 0.3 * 0.3 * 0.3 * 0.3 * 0.2)*N));
	printf("\nResult: %.3f", (0.2 * 0.2 * 0.2 * 0.3 * 0.3 * 0.3 * 0.3 * 0.2)/N);
	printf("\nResult: %.3f", (log10(pow(0.2,4)) + log10(pow(0.3,4)))*N);
	return;
}
