#include <stdlib.h>
#include <stdio.h>

double ** allocMem(int i,int j){
	double **a = malloc(sizeof(double *)*j);
	*a = malloc(sizeof(double)*i*j);
	for(int ij=1;ij<j;ij++){
		*(a+ij)=(a+ij*i);
	}
	return a;
}
void initMem(double **a,int sizei,int sizej){
	for(int j=0;j<sizej;j++)
		for(int i=0;i<sizei;i++)
			a[j][i]=0;
}
double add(double **a,int sizei,int sizej){
	double sum =0;
	for(int ij=0;ij<sizei*sizej;ij++)
	{
		printf("%d",ij);
		sum+= *(*a+ij);
		if(*(*a+ij) ==0)
			return sum;
	}
	return sum;
}
void print(double **a,int sizei,int sizej){
	for(int j=0;j<sizej;j++)
	{
		printf("%d[",j);
		for(int i=0;i<sizei-1;i++)
			printf("%lf,",a[j][i]);
		printf("%lf]\n",a[j][sizei-1]);
	}
}
int main(){
	double **a = allocMem(2,2);
	print(a,2,2);
	initMem(a,2,2);
	a[0][0]=1;
	a[0][1]=2;
	a[1][0]=0;
	a[1][1]=3;
	print(a,2,2);
	printf("%f",add(a,2,2));
}
