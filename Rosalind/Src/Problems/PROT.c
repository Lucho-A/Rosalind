/*
	Problem PROT - "Translating RNA into Protein"

	23 may. 2022
*/

#include "libRosalind.h"
#define RNA_CODONS 64

void PROT(void){
    time_t tInit=clock();
    char rnaCodons[RNA_CODONS][4]={
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
    char *s="AUGCAUGCAUUGUUUAAACCAUCUGAACUCGCGCCUAGCCCUUGCAGAUACAGGGUGUGCAACUGGCAUCCUAGACUGCUGCGAAUUAGCCGCCCUGUAAGCGCGUCCGUCAGAUGCCUAGAUGGCGUGCAUGCGAAGCGGCACCAAUGUCAAAACUAUAUGCAUCGCCCCUCCAGGCGACAUCUGCGUACAAUUUGUAUGCCUCGGGAAAAGAUUCCUAAGCAUUGUCCGCAAGUCCUAUCCUGGCGAUCGAUGUACUCGUUGGUAUAUACCUGUGCCCCGUUUCGCCGGCCUACUGCCUUCCUGAUGAGCUGGUCGGCAGUGACAGCAGCGAACCAAGUGUGGACUCCUCAGUCUGCGGCAGGCCCCACUGGUGACAUAGGUGGAGUCCAAUCCCCGUCGAGAUUGUGGCCGAUCGAAUUUGUAGUGAAGUGCGGGCUUUUAGUUCGCUUUUAUACAACAAUGUGCGACAUAGCCCCCUGGGCGACAAGUACUCUACUGCUAUAUAAGUACCACUCCGCAACACUACGAGAGCAGGGAGACGCCUGCCAUUCCGCCUUACCACAUAGUGCCCCUGUAUCCAGAAGCGUAGUGCCCUAUCUCGCACAUCACCUGAGUAAAAGCCAAGAGUUAACGAGGCCGGCCAUAAUCGUAUCGAUACAUGACGUUAAAAAACUCGACCCUUUAAGGUGUGUUAAUAUCCGUACGCGGUCCACGGCUGUAACGCGCUUUAAACUUCUUAGAAACAGUGACCCGGCCCUGGGUCAUGCGCCCAGGGUAUUGCAAACCGGGAAACUACAACACCCGCCGAUAACGCAGUCACGGCCAGUGAGCCAGGGGCGUGACGCUUGCGGGCCAACCUCUAUGCAAAGACUUUUCGCUGUCGCGUCAGUAACGCCAUGCGAUCUGGUCGUCGUUGGUUCUUUGGGUUACGAAAAAUGUCUAGGGCAGUCACAUCUUCAGACAGCCGCACCGGACGUGUUACCUCAGUCUAGAUUUGCCACUACAUCCGUGGAAUUGUCUCAACAAAAUGUUAGUUACAGGAAAACACGUCAGCAACCAUCAAUUACUCAUAUUGCUAGCAACGCUAUCGUGUGUAUGUUCAUUUGUGGAACACGACUCUGUCCGCACAUUUCAUAUUUCGCUGGCCGACAUGAAAAGCGGAACCUAUACCCCAUUACCGCGACAUUUGGAUUCGCAUGCAUGUCGGGAAUAUGGGGACUAGGACAAUGGGUUACAAGCUCCGCUCCACAGGUCCUAUCGCUGAAGCAUUUUUCCUGCAUCAAUCCCUGGUGUGUUACCAGCCUAUGCCCAAAAUUUCGAGGCCACGCCUCAUAUAACGCGGGCAUCUCGACCCAUGAUCGGCCUCGUGCGUGUCGCACUCCAGGCUCACGUCAUUCUGAUGUCGGCCUUGACACCCCAGUGCGAGCUCACGGAAUGAUCUGUUUUGCAGGCAACGUACUGCACUCCCCGCGACGUGAGAGCGGUAGCUUGGUAGGCAAGACGAGGAUAGGAAGGGGCUCAACGCAAUGUACAUGCAAUGGAUUAGGUAUGAGUUCGGUCCUGGCGAAACCGAGGUGUCUCCGCGCAGAAUUCCGUAUGCUGCAAUCCAAGCUCAUGCACACAACAUGCUGUUUCCUAACAAGCGGUGUAAUAGCGACUAUUGAUUCGCAAUGGCGACUGGGCAAUAGCCCCAGGAUCGCGAAGAGGGCAUACGAAAACUUGACCUACAGCCGCCUUUUCCCACCCGUUCUGUUUGCUGUCUGCUUACCCUCGUAUACGUGGCUUGGAUCGCAAAUCAAGCUAAUCCCAGUUGGAGCAUUUGGCAUAGUCCCAUACCGUUGCAAGUUGGAGUGGAGCAAUCUGGGAAGGAGUUUGCCUUUCUUGUUACAGGCAAUUAGAAAAAGACGUUGGGUCCUAAAAGUUUUACUCUGUAUCUGGAUCGGCAUGAAAGUCGGGAUUCGGUGCCGCCAACUUACUUCAGCCCCGAGAAAGCAUAACGAUACAGGACAAAGUUGGAGAAGAAAAAGGGUUGCAUGUCUUUCUGUCGUAAAAGAAUUAGGACGUAGUUGUAAAAUAUCGUUUGUGACCGACCGGAGCGGUCAAUUUACACUAUGUACCGUCUCUGGCCCAGCCGUACCCUCGUUAGGCUACUUUGACAGAUUGCUGUUUGACGGGUCAAGCUUUCAGAAGGAGGACUUAAGAAGAAUAAUUUUCAAAGAGCCGUAUCGUCGUCACAAGAGUAGAGCCUUUGACGUCGUCCAUCAGACACCCGAUCUGGCGUUCACGGAUUUCCAAAAGCUAGUCUUCGUUUCUAUCGUACUGCACAGAAUCUAUGCAGCGUGGCCCCUAAACAUUCGGAUGCAAGGCUCUAGCUCGGAGGUAUUUAGCCUCACGGCUGGCGUGGGGACGUUAGUGCAUGCUAAAUGGGCUCGUAGCGAAACUCUAUUAGCGGUCUGCGCUCCAGGAAGCCCGAGGGGCCGUAACAUUAGGCAACCUAACCCGGGGUGCGGGUGCUCAGGCUCUAUAAGCCCAUCAAGUAGGCUCCUCCGAAUAAUUUCUCGGAGCUCCAACUGCUGGGCCUUGGUGGUGCCGCGCGUACAACUAAUACGUAACAUUUCUGGAGGGGCAGCACCGGCCGACUUGAGAGAUCCGAUCCUAUCAGCCCUGCAGCAACUAAAGGCACUAUGUCUUACCUUACGUGUUGCGACAAGCGGUAGUUGCCGGUGUCGGCCCACAUGCAUCAGAUUGGGGACCGGCCAUGUUCUAUCUACCCUUAUGAAAAUCAGGUUACCCCCAGUCGUGUAUUUCCACACGUGGACCCUGGCGGUAGGUUGGUGCAUAAACGGUGGGCGUCGAGUUAGACUUUACAAUCUUCGUCUUCGAAUAAUAGGAGUGUCGUCCGUUAAACAUGCAGCCCUCCCAUGCGGGGCGGCCUCUAACUUUGGCUACGGUCAGGCUACGGAUCACUGGAAGCUGAAUGGUCUGUGCUUGAGGAGGGGCGAUACAGCUCCAUCCCAAUCUUCUCACCUCAGGACAUUAAGGUGGUCAAUGCGAACUAUCUCCAGAUCCGCUCUAGUUUCGCUCCCGGCUUUGAUGGCUCGUCCCGGCGAGCAAUGGGGGCGAGUGCCGAUUUAUAACCUUACCGAAUUAUUCUCAAUCAGUGUGUCUCACACCUGCUCCAGCAGUCUUCAUAGUAAAACGAUUGAUAGUAUGGUCCUACAUUACUGCCGUGUUAUCCAAGCAAUCCAACCUAGUUGCAAUCCGGCAGAGGGGGAGCUGAGAGCGGAUCAACACUUACGAGCAUCGUUCUGGGUUGGCUACAUCAUCUCACUCGCUCCUGGGGGCUAUCCUCCGGGAGCGCCGACGCUCGAUUCGCGGGUUGGGGUCGAAUUAAUCGUUGCAUUUUUUCCCUCAGAUUUAUUCAUAUCUUGUCAAACCUCUUAUUGUGUAGAAAUUUCUAGCGCGCACAGAAGAAUAUUUGUCGAGACACUCAGGCUCAUAACCCAGGGAAACGUGGUCCGCCGGUCGAAGCAAGUGGUUACUUGGACCGCUAUCCUUGGCUCAGUACCUAGCGGGGGAAAAAAACCAGUAAGGUUUCGCUCCCUCGCCCAUAAUGUUGCCCCACGUUGCUGCGAGCUAAACCACCUCUACGUUUUUGUAGGGGCCCCACGGGGCCCGUUUUUGUAUCAUUUAAACAGCGCCUUGAUUUCCUGUUUGACGGUCCAAGACAUCACAUCAGCUACCCUACUUCCCGCCCCAAGCUCCUACGAUGUGCGUUCUUUUGUUGAUGGUACUACUCGUCCUCACAGCACCAUGCACCCACCUGCCAGACAGGUCUUGUACGGUUUCACGUACGUAAAGGCAAGAGAGUCUCAAGCUAACAUGAGGAAGCGCCCCUAUGAGCCACCUCUUACAUCGUUUACCUUACUCCUAUCGCGGGUCACGGUUGUAAAAAAAUUGCGAUGGUGUCAAGAUAGUUUGACACGGAACUGUGUCUGGAAAGCCGAAGACCCCACGCAGAAGCCGCUAAGUCCUCGCUUUUCACAAAUGUUCGAAAGAUCCUACUCCAGCCGCUUUGCUUUCCACACCCGGGCGGAUGGUGGGCGUCUGACCCUCAUUGGACCGGAAUCUCCACCUGAACCUUCCACUGCUCGAAGAUAUUCAGCUAACGCUCACCUAGAGACUCCUUGCGAUUUAAGUGCGGUUCUACUAUGUAGAGCUCUCCAUCGGCAUGGAUGUUGCAUUCGGCGCCGCAGAUUUGUAAACUCCGGACUGCCCCAAGCACAGGCGGUGUCUGACCGGCAAUGCGGAAUUAAACCCACGAACAGCGUGGCUCCGCCAAGCGAGGCGCUACAGUCUAGUCCUGUUAUCGCAACUUCUGCCCGCGGACCUCAGGACUCAACAACGGGAUUGGCUCAUACGGCCAAUUACCCCAAGUUCGUACCGUCUCGUGUGUCCAUAAAAAUUCCCAAUACAAGCCGAAGAAAAGUCUUCCUGUUAUUCCGUCUCUAUAUAGGUGGAAGGAACCCAGCUUACACGUUUGCUCUUGUACUGUCGCCGGCACAAUUUUCUCCACAGCUAUCUAUGCGGGCGAGAGGAGCAGCCUAUGGGACAAAUCUAUGUGCUAGCAAUACAGCGAAUGGACUCAUACCCGUACCGCCAUCUCGGGUAACGCCCGCGGGUGGCGGGCCGAGGCUACGCAAACCAUCGACAAAGGGGUUUACACUAAGCCGACAUGUCGACACGUCAGGCAAAGUUAUACGCCGAGCGGCGUUCUCCAGCGUGCGUGUAGGAGACGAUGUGUUUAGCUUUCAUAUCUGGUCGCCGCUCGUAGCCUGGCCCGGCGGAAAGCAGAGCGAGUCUGUUUGCUAUCUCAUCGAAAGACAAUUUGCAACGGAUCCAGUAAACUUUGAUCGGCGCCAGUCAGUAAUAGCGACUCGUGGAAGACUUUUUUACUACUGUGGCCUCACCAGACUCCGUAUCGUAACUAAGCUCACCUGGCGCGGGAUAGCGCGUGACGGGGACAGGCUCACCCCUCCUGCCGUAGGAGAAAAGAGGGGGUAUCACCUCGCUUUUUUUGCACUAGAAAUUCCCAACGCAGAGUCGCAUCGUCGCUUGUACACUUCCAUAGUCAUACAUGUACGGCUAGUAUGGCUCUACCAUCCGCUGGGCACCGCACAAACGCUCACCGCCGCUACUAACCCAGGCUUGUUGCCGCGGAUAACAGAGACGUCGCAGAAUCCGACGUUCUUCGUAUGCUACGGUUACGCGCGCGACGAGUGCCAGACCAAUCCAGAUCUCGAGAGCCACUGUUCUGUUUCCGAAGUCGGGAGUCACUUGAACUGCUAUGAUAGGAACUGGAUGGGAGAGUCGAGCGCUGCAGCCGUAAGCGAGAGUCUUCGGGUCACGGCCUGUAAAGAACAAUUUGCAGGUGGCCACGCGUGUGCGAAGCAGGCUAACACCGGUAAGACCCAUCCGGGCCGGAAGGAACGUCAUGGUAAGCCCGGGCGCCCUCACCGAGACCCCUCGCUGGUCUUAGGGCUACUUGCGUCUGUGCAUGAGAGUCAACGUUCUGCAACGACCCUCCCAGCCCAUACUCAUUUCCUUAUAGUGGUGAGUUCUAAAACCAUGAAGGACCGACGCUUUUACUACUGUAUUAGACACACCGAUAUGAACCGCAAUCUAGGUCAAACCGUAAGUUCAGUCGCCCUGUUCCGGCCUAGUGUCACUUCUUAUGUUCUGUCUCCCAGGGCGCAGGCUUUAAGAUGUGAAAUGCCAGCACGGCACGAACUGCACUGUGGGGCCCGAGAACCACUCCUUGGUCGGUGGAUUCUAAUACAUAAGCGUACGCCUGUCGGUUCUGAGUUAAUAGUUUACAUCGGCUCUACGAUUAGUAACCACAUUUCACAGCUUCCCCAGCCUAACUCACGGGGUAUUUUCGGUGCCCGGCAUGUAUGUCUGCCAGAUUACAUGGGGUCGAAUUGCUCCCCAUUCGAUGUCGUUCCCCGGAGCCUUUCUUGCCCUAGAUGGGAUAUAUGGGUAAUCGACGUUAACGCACGAGGCAUCUGUGUACUAUCCAGCGCGCCAUACGCAGCGCGCUUGUGUUGGUAUGUGCUUAUAUCUCAUGGGCCCGUUACCCGUAAUCAGUGGACACCCUGCGUGCGAGGCAAGCAGCAUCUAAUAGGGUUAGUCGGAAUAGUUUUGUUGCUCCAACCCGAAGUGGCUACCUAUUUGCUUCCCACAGCUAUCGGAACGGUGUUUGCUCUAUCAGCAGCCCUAAUUUUAAAUAGUCGAUGCAGGCUAGCGUAUUCAGUACCAAGUGGCACCCUCGCUGAAGCGAGGACCGCAGCAGCUAUAAUUGCGUACGAUGGCACAUUGAGUCUCACGAUCGCAAGUAACUUAAACGUGUUCUUACGUCGCGCUGUAGGGAUCCCUGAUGGUUCAAUGCCCAACCGCAGAGGGUCUCGCCUGUCCGUAACAUCAAACGACCAGCGUAAAUCCGUCCCUAAUCUCCGCCUUAUGCUAGGCCUUUUCCGGGUUUCCAGAACUGUAAUACAAGUUCUGUAUUGUCAUCGCGGAAGGAGCAUGCAGCCAGAAACAGCGUUCUCUCAGCGGCCCUCUUUUGCGAAGCGUGAGAGCAUGCCACGGUCGCUGUCUAACAUCUCCUCCAGAUACGACUUUAAACAUCUGUGCAGCACCGGAGCGACCGUAAGUCAAAUUGAAUCGGAACGCGCUCUUAGAUCCCACUCGAAUAAGUUUGAGUUAGGUAGUCCACGUAGACACGUGCGAAUUCAUAGGAAUCUGCUGCGCAUGGAAACCGUACUACUUUGCUGGGAGCAGUGCCCCGAUGAAUAUUGUUCAGCUGCGUGUAAGAUCGCUGUCUGCAGUAGGUGCUAUCUGAAACUCAAUCGCCGGUGUCGCUACCGAGCGCGUCGCCAGCCCAGUAAACCGAAGAAAGUUAACUCCAUCAAUGUAGUGACGCUAGACUACGUGAUAUUGUCCGACCAGGCCUCGGAACCAAGCCUGAUGAUGCUAACCUCGUGGCAGCGCUUGUGCCAGAGAAGCAUAAGCCAUAUCGCAUCUGGUUUCCAGCUCUUAAUUUCAAUGUCCCCGAUAUGCCGACAUUGUAAUAGGUGGUAUCGGGCAUGCUACCGAGCGGUUCACAAUCUACUGGGAGAACGAAAUCUUCGGAGUAAAGUCAAUCCAGGUAGAAUUAAAAGCUAUGAGAGUUUGAAGUUAUUACACGCGAAGACAGAAGGGAUAAUCGCCGGUGCUCAUGGCCUAUUAUACCACUGGUAUAGGACGCGACCGCCACGAGGCGAACCGAUAGGUCGCAUGAAGCCAUUGGUGCAACCGAACCCGGGGACGUUGAGCAUAAUGCAAAUUAUCAUUACACUCGAGCUGGGUUCCUUAAUGACGAUAGAUUGGCUCAAAGUUUUUAAGCCGCCACAUCUGGUUGGGUCAGUUGGACUUCGACACAAACACGCGAAAACCAUUCUUAGCAACGACGAACGUAUAAACUCACGGUUAGGGUCAACGGAAUCCCCGCGGCUGAGGGUAACGCGAAACACUCGUGCGUUGAUGCGCAAAAGAGCAGAGGCUAUCUGCAGUGCAUCAAGUAUUUGUGAUCGCCUUGUAGAUUGCUCUUUUAGGCCGCACCAUAUUGUUACGAUACAAACUUGUCAGUCCACAACCCUCGGGGUUUUUACGUGCACCUAUCGACUCGACACACCGGGGGACAGUCACUACUGUAACAUCAACGUCCGCAUCACAGACUUUUGCAGGUUAAUCUUAGGCUGGUCAUCUCUGACAUUCCCUGCGGUGCCGCCUUUCGACCUUGAUCUGGGGCGCUGGAUCCCGGGUCAACGACGAGCUGUAGGUCACAGGCUGGCUUACCCGCACAUAUUAUUUUUAGCCAUAAUAAUGAGAAGUCUGCGAGGGAAAACGAUCGUACAGAUUAACGUCGUUGUCAGCCGGCAGACUACAUCCGGUUCUGGUUCUUGGUGCCAAGGGCCUAUAUGCCUCGUUUUCGCGGGUCGCCGAGACGAGUCCUUGUAUGCUCGACGUGCCAGUGACGUAGGUUGCAACCUAAGGCCCAUCUCAACCAGCCAUUUCACGGACAUGAGAUUAGCUCUCUUUCGGUCUCACCAUAUUUUGACAAAUUCGAGACUAUUAGAAGAGUACCCCCGUAAAAGCGUUGUAAUAGCGGAUGAUCAACAUACUCUUGACACCCACGUGGACCCCUGCAAGCGGUUACUGGCUUAUCCUGGACCUUAUCGACACAGGGAGCCCGAAGGUCCACGUAUUUUUGAUUACGCUUAUCAUCUUGAAAUCAGGCUACCCGCAGCGUGGGGGGAAAAAGGUUGUAACGUCACAGCGCCGGUGAUAGCGCAGUACGGCUCGUCAAUUCGCAACGUGGGGCGAAACGAGGCCUCGCGCCGUGUGAAAAGCAUGUUCAUGCUGAAAAUGCCCAUUGAGCCUAGCAGGGCACGGUUGGACUAUAACCCCCGCAUGCGGCGCAGUUUGGCCCCACUAACUCACCUGGGCGAGGGCAUUGGAUGCGGACGCCUAAACCAUCUACCGGUAUAUUCCCUAAGAAGAUACAAAGGCAUUUGUGUAUCAAUCUUAGAGAGGUGUAAUGAUGUAGAAACCAGAUGUUAUAGCACUGGGAUGGAAAUACCGUGCGCUGUCGAGAACGCGCGCAGGAAAGAUGGGGCGCUGAGGAAUGCCUGCAAGCUCAACGGCCCACGCAUUGAAGAUAGCUCUAUCCGUACGAGAAGUCGUCUCAUCCUCGCGUUCGGGGAACCUCUAUUACAUUUGUUUGAUAUCAACUACAGUAAGGGAAUAAGACUACUUGCUCCGACGAAGGUAAGUGCUGAGCCGCCGUCAGUCACUUACCAUAGCGCAUAUCGACCCCAAGCCCGCGUUUGUUCGCGUCGGGCCUUAUCCACAGCAUGUCCGCGGGCCUUCAACCGAGGGUGGUAUUCCCGCCAAGUAUCCCAGUACAGCACACGUCAUCUGGGGGGGAUGAAAAUUUAUAGGACCAUAGAUAUUGAGUAUAGGAGUCGGCAUACCUGGGUUUGGCACAGGGUAAGAGGCAACCGCUACGGCCUAUAUAAUCAUGAAGUGGCCGGCGAUGCUAAGGCUUUUCGGCUUGCGAGGGUCUCCGCUGAUGCGCGAGUGAUCAAACCUGGCAGUGUGCACACAUACCAAUGGUGUAAGGACCCUGUAGUACCUGUCUACCAUAGGAAAAACAUUCUCCGUGCGGGUCUGGCGGCGCGACCACUUGUAUCAGGUCAAAAGAUCUGCAUUACACCUGUAAUAUUCGCACGAGGAGAUCUUGAGAGUGGUCCUCCCCAUAGCAUGACGGAAACUAGGUUUAACAAGUUCGACGGAACUGAUAUAAUCACACUCGCACAGCGCCCAUUGGAGGAGAUAACAUAUGCCCAGCGGUGGGUGCUCCUACCGGAAUGCGUUCCCAGGGGUUCACGCGACUACACUUCUAUUUCAAUGACCCCGCCCAGGAUGAUAGUGUACAUACGAGUGUAUCAAAAUGUUCUCCUAACGAUGCUGGAUAACGCCCCGUGCCAUGGGAAUGUUUACCUAGCGUCGAUGAACGGAUUCCAAAUCGUCUAUCUAAAGGAUCCCGAGGAUAGGUCGCCACUCAUGAUUUUCUGCCAUCGGCUCACGUGGCUGCUCCAGGUCUCCACGGGCCACGAACACUCUAACAUAGCAUUCAGUUUCCCGCCACGACUGAGGAAUGGGUACACUUGCGUCGAAAGUCUCGCCCAAGUACGGGGAAAUCUUUCUACUUGCUCGGUGUCUUCGUAUCAAGGAGGCCGAAUGGGGGGAGGGGUCCACCGGCGUGCGUAUACGGAACCAGCUUAUAUUGUCCCGACGGAGCCCACAGCAUGUUUGCGGGCAUGUAGGAGGACAACAAGGGUUACCCAAGACGGUCUAAGUUGCAUGCUCCGGGAUUAG";
	char *result= (char *) malloc (strlen(s) * sizeof(char));
	for(int i=0;i<strlen(s);i++) result[i]='\0';
	int contInd=0, stop=0;
	for(int i=0;stop==0;i+=3){
		for(int j=0;j<RNA_CODONS;j++){
			if(s[i]==rnaCodons[j][0] && s[i+1]==rnaCodons[j][1] && s[i+2]==rnaCodons[j][2]){
				if(rnaCodons[j][3]=='/'){
					result[contInd]='\0';
					stop=1;
					break;
				}
				result[contInd]=rnaCodons[j][3];
				break;
			}
		}
		contInd++;
	}
    time_t tEnd=clock();
    printf("\n\nProblem PROT - Result: \n\n");
    printf("%s", result);
    printf("\n\nElapsed Time: %.6f\n",(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}
