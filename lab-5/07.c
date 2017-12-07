#include <stdio.h>
#include <stdlib.h>

int *allocTab(int size){
	int *i = malloc(sizeof(int) *size);
	return i;
}

int *findMin(int* tab,int size){
	int* min = malloc(sizeof(int)*(size+1));
	min[0]=1;
	min[1]=0;
	int count=1;
	for(int i=1;i<size;i++){
		if(tab[i]<tab[min[1]])
		{
			printf("%dless detected.\n",i);
			free(min);
			min = malloc(sizeof(int)*(size-i+1));
			min[0]=1;
			min[1]=i;	
		}else if(tab[i] == tab[min[1]]){
			printf("%d %d %dfound equal.\n",i,tab[i],tab[min[1]]);
			min[1+min[0]++]=i;	
		}		
	}

	return min;
}
void printTab(int* tab,int size){
	printf("[");
	for(int i=0;i<size-1;i++)
		printf("%d,",tab[i]);
	printf("%d]",tab[size-1]);
}

int main(){
	int a[6] = {2,2,2,3,4,1};
	int *min = findMin(a,6);
	printTab(a,6);
	printTab(min+1,min[0]);
	printTab(min,min[0]+1);
}
