/*
	Problem PROB: "Introduction to Random Strings"

	Lucho-D
	24 may. 2022-15:27:53
 */

#include "libRosalind.h"
#define N 16

void PROB(void){
	time_t tInit=clock();
	char *s="GGCCATCCCGGGATCCCATTATTGCGACTGGAGCCGCGAGCTGCACGCGGGTGGCGCTAGGGCACATTGCTTTCTAACATTCAAGCAGGTGTCTAT";
	double a[N]={0.063,0.115,0.217,0.239,0.323,0.355,0.422,0.454,0.518,0.584,0.620,0.691,0.749,0.779,0.864,0.891};
	double b[N]={0.0};
	for(int i=0;i<N;i++){
		double pCG=a[i]/2.0;
		double pTA=(1.0-pCG*2)/2.0;
		for(int j=0;j<strlen(s);j++){
			if(s[j]=='C'||s[j]=='G'){
				b[i]+=log10(pCG);
			}else{
				b[i]+=log10(pTA);
			}
		}
	}
	time_t tEnd=clock();
	printf("\n\nProblem PROB: \n\n");
	for(int i=0;i<N;i++) printf("%.3f ", b[i]);
	printf("\n\nElapsed Time: %.6f\n\n", (double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
