/*
	Problem PERM: "Enumerating Gene Orders"

	Lucho-D
	25 may. 2022-15:47:39
 */

#include "libRosalind.h"
#define MAX_LEN 7

void print_permutation(int *a, int n){
    for (int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
}

void swap(int *a,int i,int size){
	int temp=a[i];
	a[i]=a[size-1];
	a[size-1]=temp;
}

void heap_permutation(int *a,int size, int n){
    if(size==1){
        print_permutation(a,n);
        return;
    }
    for(int i=0;i<size;i++){
        heap_permutation(a,size-1,n);
        (size%2==1)?(swap(a,0,size)):(swap(a,i,size));
    }
}

void PERM(void){
	time_t tInit=clock();
	int vPermut[MAX_LEN]={0};
	for(int i=0;i<MAX_LEN;i++) vPermut[i]=i+1;
	int totalPermut=1;
	for(int i=2;i<=MAX_LEN;i++) totalPermut*=i;
	printf("\n\nProblem PERM: \n\n");
	printf("%d\n",totalPermut);
	heap_permutation(vPermut,MAX_LEN,MAX_LEN);
	time_t tEnd=clock();
	printf("\n\nElapsed Time: %.3f\n\n", (double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
