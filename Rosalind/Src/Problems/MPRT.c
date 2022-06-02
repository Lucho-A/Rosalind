/*
	Problem MPRT: "Finding a Protein Motif"

	Lucho-D
	1 jun. 2022-12:36:56
 */

#include "libRosalind.h"
#include <curl/curl.h>

#define MAX_UNIT_PROT 15
#define UNIPROT_URL "https://www.uniprot.org/uniprot/"

char unitProts[MAX_UNIT_PROT][MAX_LEN]={""};
int contProt=0;

void find_Nglycosylation_motif(char *proteinString){
	FILE *f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\MPRT\\rosalind_mprt_Result.txt","a");
	if(f==NULL){
		perror("Open file error\n");
		exit(EXIT_FAILURE);
	}
	int oneMotifFound=FALSE;
	for(int i=0;i<strlen(proteinString);i++){
		if(proteinString[i]=='N' &&
				proteinString[i+1]!='P' &&
				(proteinString[i+2]=='S' || proteinString[i+2]=='T') &&
				proteinString[i+3]!='P'){
			if(oneMotifFound==FALSE){
				fprintf(f,"%s\n", unitProts[contProt]);
				oneMotifFound=TRUE;
				fprintf(f,"%d", i+1);
			}else{
				fprintf(f," %d", i+1);
			}
		}
	}
	if(oneMotifFound==TRUE) fprintf(f,"\n");
	fclose(f);
	contProt++;
	return;
}

static size_t callback(char *protein, size_t size, size_t nitems, void *userdata){
	int firstLine=TRUE, len=nitems*size, contInd=0;
	char proteinString[MAX_LEN]="";
	for(int i=0;i<len;i++){
		while(firstLine==TRUE){
			if(protein[i]=='\n')firstLine=FALSE;
			i++;
		}
		if(protein[i]!='\n'){
			proteinString[contInd]=protein[i];
			contInd++;
		}
	}
	find_Nglycosylation_motif(proteinString);
	return len;
}

void MPRT(void){
	printf("\nProblem MPRT: ");
	FILE *f=fopen("C:\\Users\\Lucho-D\\git\\Rosalind\\Rosalind\\Resources\\MPRT\\rosalind_mprt.txt","r");
	if(f==NULL){
		perror("Open file error\n");
		exit(EXIT_FAILURE);
	}
	char unitProtLine[MAX_LEN]="";
	int contInd=0;
	while(fgets(unitProtLine,MAX_LEN,f)){
		for(int i=0;i<strlen(unitProtLine);i++){
			if(unitProtLine[i]!='\n' && unitProtLine[i]!='\0') unitProts[contInd][i]=unitProtLine[i];
		}
		contInd++;
	}
	fclose(f);
	CURL *mCurl = curl_easy_init();
	CURLcode res;
	for(int i=0;strcmp(unitProts[i],"")!=0;i++){
		char msg[MAX_LEN]="";
		sprintf(msg,"%s%s%s", UNIPROT_URL,unitProts[i],".fasta");
		if(mCurl){
			curl_easy_setopt(mCurl, CURLOPT_URL, msg);
			curl_easy_setopt(mCurl, CURLOPT_TIMEOUT, 10L);
			curl_easy_setopt(mCurl, CURLOPT_SSL_VERIFYPEER, 0L);
			curl_easy_setopt(mCurl, CURLOPT_FOLLOWLOCATION, 1L);
			curl_easy_setopt(mCurl, CURLOPT_WRITEFUNCTION, callback);
			res = curl_easy_perform(mCurl);
			if(res!=CURLE_OK){
				printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
				exit(EXIT_FAILURE);
			}
		}
	}
	curl_easy_cleanup(mCurl);
	curl_global_cleanup();
	return;
}
