/*
 * =====================================================================================
 *
 *       Filename:  01.c
 *
 *    Description:  funkcje
 *
 *        Version:  1.0
 *        Created:  06/12/17 08:03:27
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

int *tabAlloc(int size){
	return malloc(size*sizeof(int));
}
int* tabRealloc(int *tab,int size){
	return realloc(tab,size*sizeof(int));
}
void tabInit(int*tab,int size,int i);
void tabPrint(int* tab,int size);
int tabAvg(int *tab,int size);
int tabMin(int *tab,int size);

int main ( int argc, char *argv[] )
{
	srand(time(NULL));
	int size = random()%91+10;
	int* tab = tabAlloc(size);
	if(!tab){
		printf("mallocError");
		return -1;
	}
	tabPrint(tab,size);
	tabInit(tab,size,0);
	tabPrint(tab,size);
	printf("min=t[%d]=%d , avg=%d\n",tabMin(tab,size),tab[tabMin(tab,size)],tabAvg(tab,size));
	int* temp;
	int newsize = size+rand()%10;
	temp = tabRealloc(tab,newsize);
	if(!temp)
	{
		printf("realocFail");
		return -2;
	}
	tab =temp;
	tabInit(tab,newsize,size);
	size = newsize;

	tabPrint(tab,size);
	printf("min=t[%d]=%d , avg=%d\n",tabMin(tab,size),tab[tabMin(tab,size)],tabAvg(tab,size));
	return EXIT_SUCCESS;

}	/* ----------  end of function main  ---------- */

int tabMin (int *tab,int size)
{
	int min =0;
	for(int i=1;i<size;i++)
		if(tab[i]<tab[min])
			min=i;
	return min;
}		/* -----  end of function tabMin  ----- */

int tabAvg (int* tab,int size  )
{
	int avg=0;
	for(int i=0;i<size;i++)
		avg+=tab[i];
	return avg/size;
}		/* -----  end of function tabAvg  ----- */

void tabPrint(int* tab,int size){
	printf("[");
	for(int i=0;i<size-1;i++)
		printf("%2d, ",tab[i]);
	printf("%2d](%d)\n",tab[size-1],size);
}

void tabInit(int *tab,int size,int start){
	for(int i=start; i<size;i++)
		tab[i]=rand()%100;
}
