/*

	3 may. 2019
*/

#include "libRosalind.h"
#define LIMIT 25

void FIBO(void){
    time_t tInit=clock();
    long unsigned int fibos[LIMIT]={0};
    fibos[1]=1;
    fibos[2]=1;
    for(int i=3;i<LIMIT;i++) fibos[i]=fibos[i-1]+fibos[i-2];
    time_t tEnd=clock();
    printf("Problem FIBO - Result: %lu. Elapsed Time: %.6f\n",fibos[22],(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}
