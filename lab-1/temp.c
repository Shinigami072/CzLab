#include <stdio.h>

//deklaracja funkcji:
//TYP nazwa(TYP arg1,TYP arg2,...)
//{
// kod......
// return ;
// }
float toCelc(float f){
    return (f-32.0f)*5.0f/9.0f;
}
float toFaren(float c){
    return (c*1.8f+32.0f);
}


int main(void) {

    float deg =0.0f;
    printf("Wyścietlanie zmiennych %d-calkowite -%fzmienno przecinkowe\n",1,1.0f);
    //typy danych są ważne
    //wszyskie opcje sątutaj: http://www.cplusplus.com/reference/cstdio/printf/



    printf("Konwerter Farenheit ne Celcjusz\nPodaj stopnie:");
    scanf("%f",/*to jest potrzebne bo tak->*/&deg);
    printf("%fF -> %fC",deg,toCelc(deg));


    printf("Konwerter Celcjiusz na Farenheit\nPodaj stopnie:");
    scanf("%f",/*to jest potrzebne bo tak->*/&deg);
    printf("%fC -> %fF",deg,toFaren(deg));

    return 0;
}