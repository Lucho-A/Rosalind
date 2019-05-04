/*
 * libRosalind.h
 *
 *  Created on: 2 may. 2019
 *      Author: lucho
 */

#ifndef LIBROSALIND_H_
#define LIBROSALIND_H_
//includes
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <math.h>
    #include <string.h>
//defines
    #define FALSE 0
    #define TRUE 1
	#define PI 3.14159265358979323846264338327950288419716939937510
//typedef
	typedef int bool;
	typedef long double ld;
    typedef long unsigned int lu;
    typedef long long unsigned int llu;
//math.c
    double fibonacci(lu n, lu incr);
#endif /* LIBROSALIND_H_ */
