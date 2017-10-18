#include <stdio.h>
float f(float x){
	
	return x*x;
}
int main(){
	float x;
	float n;
	
	printf("x=")
	scanf("%f",x);
	printf("n=")
	scanf("%f",n);
	
	printf("x=%f n=%f f=%f",x,n,((f(x+n)-f(x))/n))
	return 0;
}