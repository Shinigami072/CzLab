#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>

double* vector(int n){
	double *v;
	v = malloc( n* sizeof(double));
	for(int i=0;i<n;i++)
		v[i]=0.0;
	return v;
}
void initVec(double *a,int size){
	for(int i=0;i<size;i++)
		a[i]=(double)(rand()%100)/10.0;
}
double *readVector(int size){
	double *v = vector(size);
	for(int i=0;i<size;i++)
		scanf("%le",(v+i));
	return v;

}
void printTab(double *d,int size)
{
	printf("[");
	for(int i=0;i<size-1;i++)
		printf("%f,",d[i]);
	printf("%f]",d[size-1]);
	

}
double * addVec(double *a,double *b,int size)
{
	double *c = vector(size);
	for(int i=0;i<size;i++)
		c[i]=a[i]+b[i];
	return c;
}
double lVec(double *a,int size){
	double l=0;
	for(int i=0;i<size;i++)
		l+=a[i]*a[i];
	return sqrt(l);

}
int main(){
	int size =4;
	srand(time(0));

	double *a = readVector(size);
	
	double *b = readVector(size);
	
	double *c = addVec(a,b,size);


	printTab(a,size);
	printf("%f \n",lVec(a,size));
	printTab(b,size);
	printf("%f \n",lVec(b,size));
	printTab(c,size);
	printf("%f \n",lVec(c,size));
}
