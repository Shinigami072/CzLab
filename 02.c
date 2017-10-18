#include <stdio.h>

int max(int a,int b){
	if(a>b)
		return a;
	return b;
}
int main(){

	int a,b;
	scanf("%i",&a);
	scanf("%i",&b);
	printf("a=%i b=%i max(a,b)=%i\n",a,b,max(a,b));
	
	return 0;

}