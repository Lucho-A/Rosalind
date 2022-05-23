/*

	23 may. 2022
*/

#include "libRosalind.h"
#define LIMIT

void PROT(void){
    time_t tInit=clock();
    char rnaCodons[45][3]={"UUU","CUU","AUU","GUU",
    		"UUC","CUC","AUC","GUC",};
	//TODO

    time_t tEnd=clock();
    printf("Problem XX - Result: %f. Elapsed Time: %.6f\n",0.0 ,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}
