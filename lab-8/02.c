/*
 * =====================================================================================
 *
 *       Filename:  02.c
 *
 *    Description:  tablica losowych punktów+odlgłość
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
#include<time.h>
#include<math.h>
typedef struct{
	double x;
	double y;
	double z;
	char nazwa;
} Point;
char pointCount = 'A';

void printPoint(Point p){
	printf("%c(%lf,%lf,%lf)\n",p.nazwa,p.x,p.y,p.z);
}

Point scanPoint(){
	Point p = {0.0,0.0,0.0,pointCount++};
	scanf("%lf %lf %lf\n",&p.x,&p.y,&p.z);
	return p;
}
Point getNext(){
	double x = (rand()%2? -1.0 : 1.0) * (rand()%1000/100.0);
	double y = (rand()%2? -1.0 : 1.0) * (rand()%1000/100.0);
	double z = (rand()%2? -1.0 : 1.0) * (rand()%1000/100.0);
	Point p ={x,y,z,pointCount++};
	return p;
}
double dist2(Point A,Point B){
	return pow(A.x-B.x,2.0)+pow(A.y+B.y,2.0)+pow(A.z+B.z,2.0);
}
double dist(Point A,Point B){
	return sqrt(dist2(A,B));
}
int main ( int argc, char *argv[] )
{
	Point origin = {0.0,0.0,0.0,'0'};
	Point p[30];
	double min = -1;;
	int minI =0;
	srand(time(NULL));
	for(int i=0;i<30;i++){
		p[i] = getNext();
		printPoint( p[i]);
		double dista = dist(p[i],origin);
		if(min<0 || min>dista){
			min=dista;
			minI=i;
		}
		printf("Dist %c = %lf\n",p[i].nazwa,dista);
	}
	printf("najbliżej środka:\n");
	printPoint(p[minI]);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

