/*
 * =====================================================================================
 *
 *       Filename:  01.c
 *
 *    Description:  punkt
 *
 *        Version:  1.0
 *        Created:  29/11/17 08:08:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Krzysztof Stasiowski (ks), krzys.stasiowski@gmail.com
 *        Company:  N/A
 *
 * =====================================================================================
 */
#include<stdlib.h>
#include<stdio.h>


typedef struct{
	double x;
	double y;
	double z;
	char nazwa;
} Point;
char pointCount = 'A';

void printPoint(Point p){
	printf("%c(%lf,%lf,%lf)",p.nazwa,p.x,p.y,p.z);
}

Point scanPoint(){
	Point p = {0.0,0.0,0.0,pointCount++};
	scanf("%lf %lf %lf",&p.x,&p.y,&p.z);
	return p;
}

int main ( int argc, char *argv[] )
{
	Point p = {0.0,0.0,0.0,'A'};
	printPoint(p);
	p = scanPoint();
	printPoint(p);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

