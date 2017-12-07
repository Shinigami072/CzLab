#include<stdlib.h>
#include<stdio.h>
#include<math.h>
/*
 * =====================================================================================
 *
 *       Filename:  03.c
 *
 *    Description:  Liczby urojone
 *
 *        Version:  1.0
 *        Created:  29/11/17 09:28:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Krzysztof Stasiowski (ks), krzys.stasiowski@gmail.com
 *        Company:  N/A
 *
 * =====================================================================================
 */

typedef union{
double d[2];
struct unreal{
	double real;
	double unreal;
}u;
}Unreal;

void printU(Unreal u)
{
	printf("r=%lf , i=%lf\n",u.u.real,u.u.unreal);
}
Unreal add(Unreal a,Unreal b){
	Unreal c = {a.u.real+b.d[0],a.u.unreal+b.d[1]};
	return c;
}
Unreal sub(Unreal a,Unreal b){
	Unreal c = {a.u.real-b.d[0],a.u.unreal-b.d[1]};
	return c;
}
double absU(Unreal u){
	return sqrt(u.u.real*u.u.real+u.d[1]+u.d[1]);
}
int main ( int argc, char *argv[] )
{
	Unreal u = {0.0,0.0};
	Unreal u1 = {1.0,1.0};
	printU(u);
	printU(u1);
	printU(add(u,u1));
	printU(sub(u,u1));
	printf("%lf\n",absU(u));
	printf("%lf\n",absU(u1));
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

