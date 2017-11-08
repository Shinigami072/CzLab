//
// Created by shinigami on 08/11/17.
//
#include <stdlib.h>
#include <stdio.h>
#define L 5
double sum(double* t,int size){
    double sum = 0;

    for(int i=0;i<size;i++)
        sum+=t[i];

    return sum;
}
double avg(double* t,int size){
    return sum(t,size)/size;
}
double max(double* t,int size){
    double m=t[0];
    for(int i=0;i<size;i++)
        if(t[i]>m)
            m=t[i];

    return m;
}
double min(double* t,int size){
    double m=t[0];
    for(int i=0;i<size;i++)
        if(t[i]<m)
            m=t[i];

    return m;
}
void printArray(double* t,int size){
    for(int i=0;i<size;i++)
        printf("%f,",t[i]);
}
int main(){
    double i[] = {1.0,2.0,3.0,4.0,5.5};

    printArray(i,L);
    printf("\n%f\n%f\n%f\n%f\n",sum(i,L),avg(i,L),max(i,L),min(i,L));

}