/*

	3 may. 2019
*/

#include "libRosalind.h"

void FIBO(void){
	char *result=NULL;
	fibonacci(6,1,0,&result);
    printf("Problem FIBO: \n\n");
    printf("%s\n\n",result);
    return;
}
