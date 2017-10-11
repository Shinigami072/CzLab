#include <stdio.h>

//
// Created by shinigami on 11/10/17.
//
float getBMI(float masa,float wzrost)
{
    return masa/(wzrost*wzrost);
}
int main(void){
    float masa=0.0f;
    float wzrost = 0.0f;

    printf("Kalkulator BMI:\n");
    printf("wzrost w m:\n");
    scanf("%f",/*to jest potrzebne bo tak->*/&wzrost);

    printf("masa w kg:\n");
    scanf("%f",/*to jest potrzebne bo tak->*/&masa);

    printf("BMI(wzrost=%f,masa=%f)=%f",wzrost,masa,getBMI(masa,wzrost));
    return 0;
}