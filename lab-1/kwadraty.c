//
// Created by shinigami on 11/10/17.
//

#include <stdio.h>
#include <math.h>

float delta(float a,float b, float c){
    return b*b-4*a*c;
}

int ileRozwZdelt(float delta){
    if(delta<0)
        return 0;
    else if(delta == 0)
        return 1;
    else
        return 2;
}
int main(void) {
    float a=0.0f;
    float b=0.0f;
    float c=0.0f;

    float del = 0.0f;
    int ile = 0;
    float x1= 0.0f;
    float x2 = 0.0f;

    printf("Kalkulator Równań kwadratowych:\n");
    printf("\na=");
    scanf("%f",&a);
    printf("\nb=");
    scanf("%f",&b);
    printf("\nc=");
    scanf("%f",&c);
    printf("\nRównanie:\n");

    printf("%fx^2+%fx+%f\n",a,b,c);

    del=delta(a,b,c);

    ile = ileRozwZdelt(del);
    printf("ma %d rozwiazan\n",ile);

    //wykonuje ©óżne case w zależności od zminnej ile
    switch(ile){
        case 0:
           //nic
            return 0;
        break;
        case 2:
            //jeżeli w casew switchu nie damy break będzie on kontynuował wykonywanie
        case 1:
            x2 = (-b+sqrt(del)) / (2.0f*a);
            x1 = (-b-sqrt(del)) / (2.0f*a);
        break;

    }
    printf("x1=%f x2=%f\n",x1,x2);


    return 0;
}
