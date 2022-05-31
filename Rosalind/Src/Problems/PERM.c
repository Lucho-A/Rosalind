/*
	Problem PERM: "Enumerating Gene Orders"

	Lucho-D
	25 may. 2022-15:47:39
 */

#include "../Headers/libRosalind.h"
#define LEN 7

void PERM(void){
	int vPermut[LEN]={0};
	for(int i=0;i<LEN;i++) vPermut[i]=i+1;
	int totalPermut=1;
	for(int i=2;i<=LEN;i++) totalPermut*=i;
	printf("\n\nProblem PERM: \n\n");
	printf("%d\n",totalPermut);
	heap_permutation(vPermut,LEN,LEN);
	return;
}
