#include <stdio.h>

float f(float x,float a)
{
	return x*x - a;
}
float fi(float x)
{
	return 2*x;
}

float absf(float a)
{
	if(a>0)
		return a;
	else
		return -a;
}

int main(){

	float N =0.01f;
	float a =9;
	float x =a;
	scanf("%f",&a);
	scanf("%f",&N);
	while(absf(f(x,a))>N){
		x = x - f(x,a)/fi(x);
	}
	printf("sqrt(%f)=%f\n",a,x);
return 0;

}