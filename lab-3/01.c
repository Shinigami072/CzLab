//
// Created by shinigami on 25/10/17.
// deklaracja tablicy 10 elementowej typu double dowolnymi wartościami
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randomDouble(int point,int max){
    return (double)(rand()%(point*max)/(double)point);
}
int main(){
    srand( time(NULL));
    double d[10];
    for(int i=0;i<10;i++)
        d[i]=randomDouble(1000000,100);
/*
 * zgodnie ze specyfikacją zadania wszyskie powyższe deklaracje można uprościć do
 * double d[10] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
 * ja jednak zdecydowałem się na losową inicjalizację
 */
    for(int i=0;i<10;i++)
        printf("%f\n",d[i]);

}

