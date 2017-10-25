//
// Created by shinigami on 25/10/17.
// deklaracja tablicy 10 elementowej typu double dowolnymi wartościami
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randomDouble(int point,int max){
    return (double)(rand()%(point*max)/(double)point);
}
void printArray(double d[],int size){
    for(int i=0;i<size;i++)
        printf("%f\n",d[i]);
}

double sumArray(double d[],int size){
    double sum=0;

    for(int i=0;i<size;i++)
        sum+=d[i];

    return sum;
}

int main(){
    srand( time(NULL));
    double d[10];


    for(int i=0;i<10;i++)
        d[i]=randomDouble(1000000,100);
    printArray(d,10);
    printf("suma = %f\n",sumArray(d,10));

}

