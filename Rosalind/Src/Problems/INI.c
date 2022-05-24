/*
	Problem INI

	Lucho-D
	23 may. 2022-22:28:36
 */

#include "libRosalind.h"
#define MAX_LEN 10000
#define A 0
#define C 1
#define G 2
#define T 3

void INI(void){
	time_t tInit=clock();
	char s[MAX_LEN]="AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC";
	int result[4]={0};
	for(int i=0;s[i]!='\0';i++){
		switch(s[i]){
		case 'A':
			result[A]++;
			break;
		case 'C':
			result[C]++;
			break;
		case 'G':
			result[G]++;
			break;
		case 'T':
			result[T]++;
			break;
		default:
			break;
		}
	}
	time_t tEnd=clock();
	printf("\nProblem INI - Result: \n\n");
	printf("%d %d %d %d", result[A], result[C], result[G], result[T]);
	printf("\n\nElapsed Time: %.6f\n",(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
