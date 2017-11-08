//
// Created by shinigami on 08/11/17.
//
#include <stdio.h>
#define K 4
int iter(int N)
{
    int sum =1;
    for(int i=1;i<N;i++)
        sum*=(i+1);

    return sum;
}
int rek(int N)
{
    if(N==0 || N==1)
        return 1;
    return rek(N-1)*(N);
}
int main(){
    printf("%d %d\n",iter(K),rek(K));
}
