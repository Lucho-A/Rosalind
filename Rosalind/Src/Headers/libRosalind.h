/*
 * libRosalind.h
 *
 *  Created on: 2 may. 2019
 *      Author: lucho
 */

#ifndef HEADERS_LIBROSALIND_H_
#define HEADERS_LIBROSALIND_H_
	//includes
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <string.h>

	//defines
    #define FALSE 0
    #define TRUE 1
	#define PI 3.14159265358979323846264338327950288419716939937510
	#define MAX_LEN 1024
	#define MAX_ROWS 1024

	//typedef
	typedef int bool;
	typedef long double ld;
    typedef long unsigned int lu;
    typedef long long unsigned int llu;

    //libRosalindModule.c
    void find_first_subsequence(char DNA[MAX_LEN], char ssDNA[MAX_LEN], int *posFound);
    void find_DNA_reverse_palindromes(char DNA[][MAX_LEN],int reversePalindromePositions[MAX_ROWS][2]);
    void reverse_DNA(char DNA_RNA[][MAX_LEN]);
    void generate_ORF(char DNA_RNA[][MAX_LEN], char orfs[][MAX_LEN]);
    bool is_start_codon(char *codon);
    bool is_stop_codon(char *codon);
    void heap_permutation(int *a,int size, int n);
    void swap(int *a,int i,int size);
    void print_permutation(int *a, int n);
    double fibonacci(lu n, lu incr, lu decr);
    int find_motif(char *s, char *t, int *result);
    void find_failure_array(char *s, int *failureArray);
    int hamming_distance(char *s, char *t);
    double transition_transversion_ratio(char *s1, char *s2);
    void DNA_to_mRNA(char *DNA, char introns[][MAX_LEN], char *mRNA);
    void mRNA_to_protein(char *mRNA, char *protein);
#endif /* HEADERS_LIBROSALIND_H_ */
