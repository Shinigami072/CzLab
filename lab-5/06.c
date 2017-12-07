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
double *findMinMax(double *a,double *minmax,int size){
	
	printf("setting minmax\n");
	minmax[0]=a[0];
	minmax[1]=a[0];
	printf("forlooptraversal\n");
	for(int i=1;i<size;i++){
		printf("%d:",i);
		if(a[i]>minmax[1])
			minmax[1]=a[i];
		if(a[i]<minmax[0])
			minmax[0]=a[i];
	}
	printf("succ\n");
	return minmax;	
}

double *findMinMax2(double **a,double *minmax,int sizeA,int sizeB){
	double *minmaxes = malloc(sizeA*2* sizeof(double));
	printf("malloc successful\n");
	for(int i=0;i<sizeA;i++){
		printf("row:%d:%d\n",2*i,2*sizeA);
		findMinMax(a[i],&minmaxes[i*2],sizeB);
	}
	printf("findminmax in rows\n");
	findMinMax(minmaxes,minmax,2*sizeA);
	printf("find minmax in minmax\n");
	free(minmaxes);
	printf("free\n");
	return minmax;

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
int isParallel(double *a,double *b,int size){
	double d = a[0]/b[0];
	for(int i=1;i<size;i++)
		if( d != (a[i]/b[i]))
			return 0;
	return 1;
}
int main(){

	int size =4;
	srand(time(0));

	double *a = readVector(size);
	
	double *b = readVector(size);
	
	double *c = addVec(a,b,size);
	printf("\n");	
	printf("%d isParal",isParallel(a,b,size));
	printTab(a,size);
	printf("%f \n",lVec(a,size));
	printTab(b,size);
	printf("%f \n",lVec(b,size));
	
	double **mat = malloc(2*sizeof(double *));
	mat[0] = a;
	mat[1]= b;
	printTab(c,size);
	double *minmaxes = vector(2);
	findMinMax2(mat,minmaxes,2,size);
	printTab(minmaxes,2);
}
