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
	GRPH();
	IEV();
	LCSM();
	LIA();
	MPRT();
	MRNA();
	ORF();
	PERM();
	PRTM();
	REVP();
	SPLC();
	LEXF();
	PROB();
	SSEQ();
	TRAN();
	KMER();
	KMP();
	RSTR();
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
	//TODO LGIS();
	EVAL();
	clock_gettime(CLOCK_REALTIME,&tEnd);
	printf("\n\nElapsed Time: %.3lf secs.\n\n", (double) (tEnd.tv_sec-tInit.tv_sec)+(tEnd.tv_nsec-tInit.tv_nsec)/NS_PER_SECOND);
	return EXIT_SUCCESS;
}
