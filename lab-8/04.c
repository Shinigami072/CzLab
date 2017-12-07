#include<stdlib.h>
#include<stdio.h>
/*
 * =====================================================================================
 *
 *       Filename:  04.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/12/17 23:20:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Krzysztof Stasiowski (ks), krzys.stasiowski@gmail.com
 *        Company:  N/A
 *
 * =====================================================================================
 */
typedef union{
int date[6];
struct {
int year;
int month;
int day;
int hour;
int min;
int sec;
}d;
}Date;

void printD(Date d){
printf("%02d:%02d:%02d %02d/%02d/%d",d.d.hour,d.d.min,d.d.sec,d.d.day,d.d.month,d.d.year);
}

int isEqual(Date a,Date b)
{
for(int i=0;i<6;i++)
	if(a.date[i] != b.date[i])
		return 0;
return 1;
}
	int
main ( int argc, char *argv[] )
{
	Date d = {2017,10,7,20,44,0};
	Date b = {2017,10,7,20,44,1};
	printD(d);
	printf("%d %d",isEqual(d,d),isEqual(d,b));
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
