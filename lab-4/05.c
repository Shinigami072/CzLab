//
// Created by shinigami on 08/11/17.
//
#include <stdio.h>
#define K 3
int iter(int N)
{
    int sum =0;
    for(int i=0;i<N;i++)
        sum+=1+2*(i);

    return sum;
}
int rek(int N)
{
    if(N==1)
        return 1;
    return rek(N-1)+(1+2*(N-1));
}
int main(){
    printf("%d %d\n",iter(K),rek(K));
}