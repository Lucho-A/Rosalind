/*
 ============================================================================
 Name        : Rosalind.c
 Author      : L.
 Version     :
 Copyright   : 
 Description : Rosalind Project - main()
 ============================================================================
 */

#include "libRosalind.h"
#define NS_PER_SECOND 1000000000.0

int main(void) {
	struct timespec tInit, tEnd;
	clock_gettime(CLOCK_REALTIME,&tInit);
	//Bioinformatics Stronghold
	/*
	DNA();
	RNA();
	REVC();
	FIB();
	GC();
	HAMM();
	IPRB();
	PROT();
	SUBS();
	CONS();
	FIBD();
	LCSM();
	ORF();
	PERM();
	PRTM();
	REVP();
	SPLC();
	PROB();
	SSEQ();
	TRAN();
	KMP();
	SPEC();
	*/
	//Bioinformatics Armory
	/*
	INI();
	*/
	//Algorithmic Heights
	/*
	FIBO();
	*/
	MPRT();
	clock_gettime(CLOCK_REALTIME,&tEnd);
	printf("Elapsed Time: %.6lf secs.\n\n", (double) (tEnd.tv_sec-tInit.tv_sec)+(tEnd.tv_nsec-tInit.tv_nsec)/NS_PER_SECOND);
	return EXIT_SUCCESS;
}
