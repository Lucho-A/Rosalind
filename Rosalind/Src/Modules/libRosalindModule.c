/*
	libRosalindModule.c

	Lucho-D
	28 may. 2022-18:06:49
 */

#include "libRosalind.h"

//Variable definition
char rnaCodons[RNA_CODONS][4]= {
		"UUUF","CUUL","AUUI","GUUV",
		"UUCF","CUCL","AUCI","GUCV",
		"UUAL","CUAL","AUAI","GUAV",
		"UUGL","CUGL","AUGM","GUGV",
		"UCUS","CCUP","ACUT","GCUA",
		"UCCS","CCCP","ACCT","GCCA",
		"UCAS","CCAP","ACAT","GCAA",
		"UCGS","CCGP","ACGT","GCGA",
		"UAUY","CAUH","AAUN","GAUD",
		"UACY","CACH","AACN","GACD",
		"UAA/","CAAQ","AAAK","GAAE",
		"UAG/","CAGQ","AAGK","GAGE",
		"UGUC","CGUR","AGUS","GGUG",
		"UGCC","CGCR","AGCS","GGCG",
		"UGA/","CGAR","AGAR","GGAG",
		"UGGW","CGGR","AGGR","GGGG"};

//Heap Permutation
void print_permutation(int *a, int n){
	for (int i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n");
}

void swap(int *a,int i,int size){
	int temp=a[i];
	a[i]=a[size-1];
	a[size-1]=temp;
}

void heap_permutation(int *a,int size, int n){
	if(size==1){
		print_permutation(a,n);
		return;
	}
	for(int i=0;i<size;i++){
		heap_permutation(a,size-1,n);
		(size%2==1)?(swap(a,0,size)):(swap(a,i,size));
	}
}

//Fibonacci
double fibonacci(lu n, lu incr){
	double fibos[3]={0,1,1};
	for(int i=3;i<=n;i++){
		fibos[0]=fibos[1]*incr+fibos[2];
		fibos[1]=fibos[2];
		fibos[2]=fibos[0];
	}
	return fibos[0];
}

int find_motif(char *s, char *t, int *result){
	int lenS=strlen(s), lenT=strlen(t), cont=0;
	bool find=FALSE;
	if(lenS>=lenT){
		for(int i=0;i<lenS;i++){
			find=FALSE;
			for(int j=0, k=i;j<lenT;j++,k++){
				if(s[k]!=t[j]){
					find=FALSE;
					break;
				}else{
					find=TRUE;
				}
			}
			if(find==TRUE){
				result[cont]=i+1;
				cont++;
			}
		}
	}
	return cont;
}

void find_failure_array(char *s, int *failureArray){
	int lenS=strlen(s)-1,pos=0, cont=0, ind=1;
	for(int i=1;i<lenS;i++){
		if(s[i]==s[cont]){
			failureArray[ind]=cont+1;
			ind++;
			if(cont==0) pos=i;
			cont++;
		}else{
			while(pos<=i && cont!=0){
				pos++;
				int ok=1,aux=pos;
				for(int j=0;j<cont;j++){
					if(s[aux]!=s[j]){
						ok=0;
						break;
					}
					aux++;
				}
				if(ok==0){
					cont--;
				}else{
					break;
				}
			}
			failureArray[ind]=cont;
			ind++;
		}
	}
}

int hamming_distance(char *s, char *t){
	int hammingDistance=0;
	for(int i=0;i<strlen(s);i++){
		if(s[i]!=t[i]) hammingDistance++;
	}
	return hammingDistance;
}

double transition_transversion_ratio(char *s1, char *s2){
	double transitions=0.0, transversion=0.0, hammingDistance=0.0;
	for(int i=0;i<strlen(s1);i++){
		if( ((s1[i]=='A' && s2[i]=='G') || (s1[i]=='G' && s2[i]=='A'))
				||
				((s1[i]=='C' && s2[i]=='T') || (s1[i]=='T' && s2[i]=='C')))
			transitions++;
	}
	hammingDistance=hamming_distance(s1, s2);
	transversion=hammingDistance-transitions;
	return transitions/transversion;
}

void DNA_to_mRNA(char *DNA, char introns[][MAX_LEN], char *mRNA){
	int cont=0,indFound=-1;
	while(strcmp(introns[cont],"")!=0){
		for(int i=0;i<strlen(DNA)-1;i++){
			indFound=i;
			for(int j=0;j<strlen(introns[cont]);j++){
				if(DNA[i+j]!=introns[cont][j]){
					indFound=-1;
					break;
				}
			}
			if(indFound!=-1){
				for(int k=indFound;k<indFound+strlen(introns[cont]);k++) DNA[k]=' ';
			}
		}
		cont++;
	}
	cont=0;
	for(int i=0;i<strlen(DNA);i++){
		if(DNA[i]!=' '){
			mRNA[cont]=(DNA[i]!='T')?(DNA[i]):('U');
			cont++;
		}
	}
}

void mRNA_to_protein(char *mRNA, char *protein){
	int contInd=0, stop=0;
	for(int i=0;stop==0;i+=3,contInd++){
		for(int j=0;j<RNA_CODONS;j++){
			if(mRNA[i]==rnaCodons[j][0] && mRNA[i+1]==rnaCodons[j][1] && mRNA[i+2]==rnaCodons[j][2]){
				if(rnaCodons[j][3]=='/'){
					protein[contInd]='\0';
					stop=1;
					break;
				}
				protein[contInd]=rnaCodons[j][3];
				break;
			}
		}
	}
}
