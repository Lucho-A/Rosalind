/*

	3 may. 2019
*/

#include "libRosalind.h"
#define LIMIT 25

void FIBO(void){
    time_t tInit=clock();
    double resp=fibonacci(22);
    time_t tEnd=clock();
    printf("Problem FIBO - Result: %.0f. Elapsed Time: %.6f\n",resp,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}
