#include <stdio.h>

int main(){

	
	int N,K;
	
	printf("N=");
	scanf("%i",&N);
	printf("K=");
	scanf("%i",&K);
	
	int sum =0;
	
	for(int i=0;i<N;i++)
		sum+=K+i;
	
	printf("N=%i K=%i sum=%i\n",N,K,sum);
	return 0;
}