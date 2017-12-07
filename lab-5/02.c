#include<stdlib.h>
#include<stdio.h>

int sameChars(char *a,char *b)
{
	int i=-1;
	
	while(a[i+1]==b[i+1] && a[i+1] !='\0' && b[i+1]!='\0' )
	{
		++i;
	}
	if(i ==0)
		return -1;

	return i+1;
}

int main(){
	char *a=malloc(10*sizeof(char));
	char *b=malloc(10*sizeof(char));
	scanf("%s",a);
	scanf("%s",b);

	printf("%s %s %d",a,b,sameChars(a,b));
}
