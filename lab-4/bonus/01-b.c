//
// Created by shinigami on 08/11/17.
//
#include <stdio.h>
#include <stdlib.h>
#define DELTA (0.02)
double f(double x){
    printf("calculating f(%f)\n",x);
    return x;
}

double pole(double a,double b){
    return (b-a)*(f(a)+4.0*f(a/2.0+b/2.0)+f(b))/6.0;
}

double calka(double a,double b,double delta){
    double c = (a+b)/2.0;
    double S = pole(a,b);

    printf("%f,%f S1\n",a,c);
    double S1 = pole(a,c);
    printf("\n");
    printf("%f,%f S2\n",c,b);
    double S2 = pole(c,b);
    printf("\n");

    if(abs((S1+S2)-S)<delta)
        return S;

    return calka(a,c,delta/2)+calka(c,b,delta/2);

}

double calkaD(double a,double b,double delta){
    return calka(a,b,delta);
}
int main(){
    double a = 0;
    double b = 4;
    double delta = 0.2;
    scanf("%lf %lf %lf",&a,&b,&delta);
    printf("%f\n", calkaD(a,b, delta));
}
