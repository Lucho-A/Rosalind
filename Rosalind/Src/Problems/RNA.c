/*

	3 may. 2019
*/

#include "libRosalind.h"

void RNA(void){
    char s[1500]="GGAACGTCGTTCCCTTAAGAGTGATTGTGCAGAATGCGGAGATACGCGGGTCCACCTGGGTAATTACCGTCAACGTATACTCCTGACAACCGTAAGTATTTGCTATATAGCGTCCCACTGACAGCTATTCATTTGTATTTCCCGAGCTATGTGAACGCTCTAAGAGTCGGATGAGGCCCAAGAGAATTACTATTAACCGTATCATAAAAACCCAACGAAGCACTCTGTTCGACGGGTTTCCATCGGAAAATTGGAATCCAGGGGGGCATCGAGAAGAGCGTAATTAAAAAAGGAGCGTAGGCAGCAGTCCGGGTTAACATTTGTCGGATATCCTAGGATGTGACACCTGTTCAATTGGCTGGCTGAACAGCAAAATTTCTGTTGGTACGAACTTGGCTCGTTCCTCAACTATATAGGGTTTCAACTAAACGCGACCCTAGGCCTCAATGCCGTAGCTCCCGATGTGGCACAGTACAAAGCTTGTCCTTTAGGTGCAATAGGAAGACCCGCAACTGGATTGAACACGCATTGATAGGCGACTGTCACGGATCCATCACTCCTCGGGCCGGACCTACGCTTCCGACAAGGAACCTGTGCTCCCCCGGGGTCTTCCGCGTTGATTTTACGCACTGGCGCCCGTTGTCACATCTTCTGCAGGGACGCTTCCCTGCCTCACTGGAAATGGCGCTCTCATTTCTAGGTTAAACGACTCGGAGGCTCATTTATTGTGCAGGGCATATCGTGATCTTGAAAGGATACAAGTTCGGTTGATGTGGTCACGCTAATACTGACGTCGTGGCTGCTCATACGAACGTCGGATCAGCGCGTTGTCCAATATAAAATTGCATCTATAGCTAGCCAGTTCTCCACCGTTGGTGTTTCCTGTAGTTATAAATGGAATGCACAGAATAAAAGTGGAGTGAGTGCAGATGAGATACAACAG";
    for(int i=0;i<strlen(s);i++) if(s[i]=='T') s[i]='U';
    printf("Problem RNA- Result: %s.\n", s);
    return;
}
