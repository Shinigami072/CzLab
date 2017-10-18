#include <stdio.h>

float f(float x,float a)
{
	return x*x - a;
}
float fi(float x)
{
	return 2*x;
}

int main(){

	const int N =5;
	float a =9;
	float x =a;
	scanf("%f",&a);
	for(int i=0;i<N;i++){
		x = x - f(x,a)/fi(x);
	}
	printf("sqrt(%f)=%f\n",a,x);
return 0;

}