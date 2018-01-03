/*
 * =====================================================================================
 *
 *       Filename:  04.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/12/17 18:16:08
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
#include<math.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int ** allocTable(int length){
	int **table = malloc(sizeof(int *)*length);
	
	if(!table)
		return NULL;
	
	for(int i=0;i<length;i++){
		table[i]=malloc(sizeof(int)*(length-i));
		if(!table[i])
			return NULL;
	}
	return table;
}
void printTable(int **table,int length){
	
	printf("Tabela [%d:%d]\n",length,length);

	for(int i=0;i<length;i++)
	{
		printf("[");
		for(int j=i;j>0;j--)
		printf("      ");
		for(int j=i;j<length-1;j++)
			printf("%4d, ",table[i][j-i]);
		printf("%4d]\n",table[i][length-1-i]);
	}		
}
void initTable(int **table,int xp,int xk,int yp,int yk){
	for(int j=0;j<=yk-yp;j++)
	for(int i=j;i<=xk-xp;i++)
		table[j][i-j]=(xp+i)*(yp+j);
}
int getTableVal(int **table,int x,int y,int xp,int yp){
	int i = MIN(x-xp,y-yp);
	int j = MAX(x-xp,y-yp);
 
	return table[i][j-i];
}
int main(){
	int xp,xk, yp,yk;
	scanf("%d %d %d",&xp,&xk,&yp);
	yk = (xk-xp)+yp;
	int length = xk-xp+1;

	int ** table = allocTable(length);

	if(!table)
		return -1;

	initTable(table,xp,xk,yp,yk);

	printTable(table,length);
	int i,j;
	
	do{
	scanf("%d",&i);
	}while(!(i<=xk && xp<=i));
	do{
	scanf("%d",&j);
	}while(!(j<=yk && yp<=j));
	printf("%d*%d=%d\n",i,j,getTableVal(table,i,j,xp,yp));

	
	return 0;
}

