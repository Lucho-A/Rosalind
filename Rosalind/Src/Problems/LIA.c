/*
	Problem LIA: "Independent Alleles"

	Lucho-D
	5 jun. 2022-23:33:44
*/

#include "libRosalind.h"
#define K 7
#define N 30
#define PAa 0.5
#define PBb 0.5
#define PAaBb (PAa*PBb)
#define PNAaBb (1-PAa*PBb)
#define POBL (pow(2,K))

double counting_combinations(double n, double r){
	double result=1.0;
	for(double i=1.0;i<=r;i++,n--) result*=n/i;
	return result;
}

double calculate_probability(int n, int pobl){
	double sum=0.0;
	for(int i=n;i<=POBL;i++) sum+=pow(PAaBb,i)*pow(PNAaBb,POBL-i)*counting_combinations(POBL,i);
	return sum;
}

void LIA(void){
	printf("\n\nProblem LIA: \n");
	double r=calculate_probability(N, POBL);
	printf("\n%.3f\n",r);
	return;
}
