//
// Created by shinigami on 08/11/17.
//
#include <stdio.h>
#include <stdlib.h>
#define DELTA (0.02)
double f(double x){//TODO: opisz to jakoś
    printf("calculating f(%f)\n",x);
    return x;
}

double pole(double a,double b){
    return (b-a)*(f(a)+4.0*f(a/2.0+b/2.0)+f(b))/6.0;
}
double poleO(double a,double b,double fa,double fb,double fc){
    return (b-a)*(fa+4.0*fc+fb)/6.0;
}


double calka(double a,double b,double delta,double S,double fa,double fb,double fc){
    double c = (a+b)/2.0;
    printf("%f,%f S1\n",a,c);
    double fc1  = f((c+a)/2.0);
    double fc2  = f((c+b)/2.0);

    double S1 = poleO(a,c,fa,fc,fc1);
    printf("\n");
    printf("%f,%f S2\n",c,b);
    double S2 = poleO(c,b,fc,fb,fc2);
    printf("\n");

    if(abs((S1+S2)-S)<delta)
        return S;

    return calka(a,c,delta/2,S1,fa,fc,fc1)+calka(c,b,delta/2,S2,fc,fb,fc2);

}

double calkaD(double a,double b,double delta){
    printf("%f,%f S\n",a,b);
    double fa = f(a);
    double fb = f(b);
    double fc = f((a+b)/2.0);

    double S = poleO(a,b,fa,fb,fc);

    return calka(a,b,delta,S,fa,fb,fc);
}
int main(){
    double a = 0;
    double b = 4;
    double delta = 0.2;
    scanf("%lf %lf %lf",&a,&b,&delta);
    printf("%f\n", calkaD(a,b, delta));
}
