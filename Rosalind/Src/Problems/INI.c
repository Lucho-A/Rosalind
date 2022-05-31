/*
	Problem INI

	Lucho-D
	23 may. 2022-22:28:36
 */

#include "libRosalind.h"
#define LEN 10000
#define A 0
#define C 1
#define G 2
#define T 3

void INI(void){
	char s[LEN]="AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC";
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
	printf("\nProblem INI - Result: \n\n");
	printf("%d %d %d %d", result[A], result[C], result[G], result[T]);
	return;
}
