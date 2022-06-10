/*
	libRosalindModule.c

	Lucho-D
	28 may. 2022-18:06:49
 */

#include "libRosalind.h"

//Variable definition

void initStrV(char **p, int size, char c){
	*p=(char*)malloc(size*sizeof(char));
	memset(*p,c,size*sizeof(char));
	return;
}

void initIntV(int **p, int size, int c){
	*p=(int*)malloc(size*sizeof(int));
	memset(*p,c,size*sizeof(int));
	return;
}

void initDoubleV(double **p, int size, int c){
	*p=(double*)malloc(size*sizeof(double));
	memset(*p,c,size*sizeof(double));
	return;
}

void open_file(char *dir, char *fileName, FILE **f, char *mode){
	char path[MAX_LEN]="";
	snprintf(path,MAX_LEN,"%s\\%s\\%s",RESOURCE_PATH,dir,fileName);
	*f=fopen(path,mode);
	if(*f==NULL){
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	return;
}

//Find first subsequence in DNA
void find_first_subsequence(char DNA[MAX_LEN], char ssDNA[MAX_LEN], int *posFound){
	int lenDNA=strlen(DNA), lenssDNA=strlen(ssDNA), ind=0;
	for(int i=0;i<lenssDNA;i++){
		for(int j=((ind-1)==-1)?(0):(posFound[ind-1]);j<lenDNA;j++){
			if(DNA[j]==ssDNA[i]){
				posFound[ind]=j+1;
				ind++;
				break;
			}
		}
	}
	return;
}

//Find capicuas jjaja
void find_DNA_reverse_palindromes(char DNA[][MAX_LEN],int reversePalindromePositions[MAX_ROWS][2]){
	int dnaLen=strlen(DNA[0])-1, cont=0, contL=0,contR=0;
	bool palindromeFound=TRUE;
	for(int i=0;i<dnaLen;i++){
		contL=i;
		contR=dnaLen;
		for(int k=dnaLen;k>i;k--){
			palindromeFound=TRUE;
			contR=k;
			contL=i;
			while(palindromeFound==TRUE && contR>i){
				if(DNA[0][contL]!=DNA[1][contR]){
					palindromeFound=FALSE;
				}else{
					contL++;
					contR--;
				}
			}
			if(palindromeFound==TRUE){
				int palindromeLen=k-i+1;
				if(palindromeLen>=4 && palindromeLen<=12){
					reversePalindromePositions[cont][0]=i+1;
					reversePalindromePositions[cont][1]=palindromeLen;
					cont++;
				}
			}
		}
	}
}

//Is stop codon???
bool is_stop_codon(char *codon){
	char resp='\0';
	for(int i=0;i<3;i++) codon[i]=(codon[i]=='T')?('U'):(codon[i]);
	for(int i=0;i<CODONS;i++){
		if(codons[i][0]==codon[0] && codons[i][1]==codon[1] && codons[i][2]==codon[2]){
			resp=codons[i][3];
			break;
		}
	}
	if(resp=='/') return TRUE;
	return FALSE;
}

bool is_start_codon(char *codon){
	if(codon[0]=='A' && (codon[1]=='U' || codon[1]=='T') && codon[2]=='G') return TRUE;
	return FALSE;
}

//Reverse DNA
void reverse_DNA(char DNA_RNA[][MAX_LEN]){
	for(int i=0;i<strlen(DNA_RNA[0]);i++){
		switch(DNA_RNA[0][i]){
		case 'A':
			DNA_RNA[1][i]='T';
			break;
		case 'T':
			DNA_RNA[1][i]='A';
			break;
		case 'G':
			DNA_RNA[1][i]='C';
			break;
		case 'C':
			DNA_RNA[1][i]='G';
			break;
		default:
			break;
		}
	}
}

//Generate ORF's
void generate_ORF(char DNA_RNA[][MAX_LEN], char orfs[][MAX_LEN]){
	char codon[4]="", DNA_aux[MAX_LEN]={'\0'};;
	int contR=0, lastPos=0, DNAlen=0;
	for(int k=0;k<2;k++){
		strcpy(DNA_aux,DNA_RNA[k]);
		if(k==1){
			DNAlen=strlen(DNA_aux);
			for(int i=DNAlen-1;i>(DNAlen-1)/2;i--){
				char aux=DNA_aux[DNAlen-i];
				DNA_aux[DNAlen-i]=DNA_aux[i];
				DNA_aux[i]=aux;
			}
		}
		for(int i=0;i<strlen(DNA_aux);i++){
			codon[0]=DNA_aux[i];
			codon[1]=DNA_aux[i+1];
			codon[2]=DNA_aux[i+2];
			if(is_start_codon(codon)){
				lastPos=i+1;
				for(int j=i;is_stop_codon(codon)==FALSE && j<strlen(DNA_aux);){
					strcat(orfs[contR],codon);
					j+=3;
					codon[0]=DNA_aux[j];
					codon[1]=DNA_aux[j+1];
					codon[2]=DNA_aux[j+2];
				}
				if(is_stop_codon(codon)==FALSE) {
					strcpy(orfs[contR],"");
					contR--;
				}else{
					for(int i=0;i<contR;i++){
						if(strcmp(orfs[i],orfs[contR])==0){
							strcpy(orfs[contR],"");
							contR--;
						}
					}
				}
				i=lastPos;
				contR++;
			}
		}
	}
	return;
}

// Lexicographic R-Permutations
void lexicographic_r_permutations(char *orderedSymbols, int r, char **res){
	int n=strlen(orderedSymbols);
	int *idx=NULL;
	initIntV(&idx,r,0);
	int idxR=0,c=0;
	while(TRUE){
		for(c=0;c<r;c++) res[idxR][c]=orderedSymbols[idx[c]];
		res[idxR][c]='\0';
		idxR++;
		idx[r-1]++;
		for(int i=r-1;i>=0;i--){
			if(idx[0]==n) return;
			if(idx[i]==n){
				idx[i]=0;
				idx[i-1]++;
			}
		}
	}
	return;
}

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

void multiply_numbers(char *n, int m, char *result){
	char n2[MAX_DIGITS]="";
	strcpy(n2,n);
	strcpy(result,n);
	for(int i=1;i<m;i++){
		sum_numbers(n, n2, result);
		strcpy(n2,result);
	}
	return;
}

void pow_numbers(char *n, int m, char *result){
	strcpy(result,n);
	for(int i=1;i<m;i++) sum_numbers(result, result, result);
	return;
}

void substract_numbers(char *n1, char *n2, char *result){
	int lenN1=strlen(n1)-1,lenN2=strlen(n2)-1,carry=0, contInd=0;
	while(lenN1>=0 || lenN2>=0){
		int sn1=(lenN1>=0)?(n1[lenN1]-'0'):(0);
		int sn2=(lenN2>=0)?(n2[lenN2]-'0'):(0);
		int dif=0;
		if(sn1-carry<sn2){
			sn1+=10-carry;
			carry=1;
			dif=sn1-sn2;
		}else{
			dif=sn1-carry-sn2;
			carry=0;
		}
		(result)[contInd]=dif+'0';
		contInd++;
		lenN1--;
		lenN2--;
	}
	for(int i=strlen(result)-1;i>(strlen(result)-1)/2;i--){
		char aux=(result)[strlen(result)-1-i];
		(result)[strlen(result)-1-i]=(result)[i];
		(result)[i]=aux;
	}
	return;
}

void sum_numbers(char *n1, char *n2, char *result){
	int lenN1=strlen(n1)-1,lenN2=strlen(n2)-1,carry=0, contInd=0;
	while(lenN1>=0 || lenN2>=0){
		int sn1=(lenN1>=0)?(n1[lenN1]-'0'):(0);
		int sn2=(lenN2>=0)?(n2[lenN2]-'0'):(0);
		int sum=sn1+sn2+carry;
		carry=sum/10;
		(result)[contInd]=(sum%10) + '0';
		contInd++;
		lenN1--;
		lenN2--;
	}
	if(carry==1)(result)[contInd]='1';
	for(int i=strlen(result)-1;i>(strlen(result)-1)/2;i--){
		char aux=(result)[strlen(result)-1-i];
		(result)[strlen(result)-1-i]=(result)[i];
		(result)[i]=aux;
	}
	return;
}

//Fibonacci
void fibonacci(lu n, lu multiplyFactor, lu substractTerm, char **result){
	char fibos[n][MAX_DIGITS], resultSum[MAX_DIGITS]="0", termF2[MAX_DIGITS]="0";
	strcpy(fibos[0],"0");
	strcpy(fibos[1],"1");
	for(int i=2;i<=n;i++){
		multiply_numbers(fibos[i-2], multiplyFactor, termF2);
		if(i<=substractTerm || substractTerm==0){
			sum_numbers(termF2, fibos[i-1],resultSum);
			strcpy(fibos[i],resultSum);
			continue;
		}
		if(i==substractTerm+1){
			substract_numbers(fibos[i-2], "1", termF2);
			sum_numbers(termF2, fibos[i-1], resultSum);
			strcpy(fibos[i],resultSum);
			continue;
		}
		substract_numbers(fibos[i-2], fibos[i-substractTerm-1], termF2);
		sum_numbers(termF2, fibos[i-1], resultSum);;
		strcpy(fibos[i],resultSum);
	}
	*result=fibos[n];
	return;
}

//Find Motif
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

//Find Failure Array
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

//Hamming Distance
int hamming_distance(char *s, char *t){
	int hammingDistance=0;
	for(int i=0;i<strlen(s);i++){
		if(s[i]!=t[i]) hammingDistance++;
	}
	return hammingDistance;
}

//Transition Transversion Ratio
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

//DNA to mRNA
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

//mRNA to Protein
void mRNA_to_protein(char *mRNA, char *protein){
	int contInd=0, stop=0;
	for(int i=0;stop==0 && i<strlen(mRNA);i+=3,contInd++){
		for(int j=0;j<CODONS;j++){
			if(mRNA[i]==codons[j][0] && mRNA[i+1]==codons[j][1] && mRNA[i+2]==codons[j][2]){
				if(codons[j][3]=='/'){
					protein[contInd]='\0';
					stop=1;
					break;
				}
				protein[contInd]=codons[j][3];
				break;
			}
		}
	}
}
