#include<stdlib.h>
#include<stdio.h>
/*
 * =====================================================================================
 *
 *       Filename:  05.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/12/17 23:40:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Krzysztof Stasiowski (ks), krzys.stasiowski@gmail.com
 *        Company:  N/A
 *
 * =====================================================================================
 */

	enum color {BLACK,WHITE,RED,GREEN,BLUE};
	enum engine{ELECTRIC,HYBRID,DIESEL,GAS};
	enum make{VOLVO,OPEL,BMW};
typedef struct car{
	enum color c;
	enum engine e;
	enum make m;
	long tech[10];
	int price;
	int doorC;
} Car;

typedef struct truck{
	enum color c;
	enum engine e;
	enum make m;
	long tech[10];
	int price;
	int length;
	int payload;
	int axiC;	
} Truck;

typedef struct bus{
	enum color c;
	enum engine e;
	enum make m;
	long tech[10];
	int price;
	int length;
	int seatC;
	int axiC;	
} Bus;

typedef union vehicle{
	Bus b;
	Truck truck;
	Car c;
} Vehicle;

	int
main ( int argc, char *argv[] )
{
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
