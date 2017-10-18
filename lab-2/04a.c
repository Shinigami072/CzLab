#include <stdio.h>

int main(){
	const int N =3;
	const int K =4;

	int sum =0;
	
	for(int i=0;i<N;i++)
		sum+=K+i;
	
	printf("N=%i K=%i sum=%i\n",N,K,sum);
	return 0;
}