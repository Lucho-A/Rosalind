/*

	23 may. 2022
*/

#include "libRosalind.h"
#define LIMIT

void GC(void){
    time_t tInit=clock();

    FILE *fp;
    char *line = NULL;
    size_t lenLine = 0;
    ssize_t read;
    char result[100]="0";
    fp = fopen("Resources/GC/Dataset", "r");
    if(fp == NULL) exit(EXIT_FAILURE);
    //while ((read = getline(&line, &lenLine, fp)) != -1) sum_big_numbers(result,line,result);
    fclose(fp);
    if(line) free(line);

    time_t tEnd=clock();
    printf("Problem XX - Result: %f. Elapsed Time: %.6f\n",0.0 ,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}
