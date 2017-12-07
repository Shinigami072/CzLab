#include <stdio.h>
#include <stdlib.h>
int compare(char *a, char *b){
	int i=0;
	printf("compare(%s , %s)\n" ,a,b);
	while(*(a+i)!='\0' && *(b+i)!='\0')
	{
		printf("%c %c %d",*(a+i),*(b+i),(*(a+i)-*(b+i)));
		if(*(a+i)<*(b+i))
			return -1;
		else if(*(a+i)>*(b+i))
			return 1;
		i++;
	}
	
	return 0;
}
void printTab(char **tab,int size){
	printf("[");
	for(int i=0;i<size-1;i++)
		printf("%s, ",tab[i]);
	printf("%s]",tab[size-1]);
			
}
void selectionsort(char **tab,int size){
	int min = 0;
	int max = size-1;

	for(int i=0;i<size;i++){
		if(compare(tab[i],tab[min])<0)
			min=i;
		if(compare(tab[i],tab[max])>0)
			max=i;
	}
	
	char *a = tab[0];
	tab[0]=tab[min];
	tab[min]=a;
	a=tab[size-1];
	tab[size-1]=tab[max];
	tab[max]=a;

	if(size>2)
		selectionsort((tab+1),size-2);
		
		

}
void bubblesort(char **tab,int size){
 int c;
 int start =0;
 do{
	c=0;
	printf("sorting from %d to %d\n",start,size);
 	for(int i=start+1;i<size;i++)
 	{
		printf("%d:%s",i,tab[i]);
		if(compare(tab[i-1],tab[i])>0){
			printf("switching@%d\n",i);
			char * a = tab[i-1];
			tab[i-1]=tab[i];
			tab[i]=a;
			c++;
		}
		
	}
	if(start<size)
	start++;
 }while(c>0 && start<size);
 printf("sorted\n");

}
int main(){
	int maxChars =10;
	int maxLength =10;

	char **tab = malloc(maxChars*sizeof(char *));
	for(int i=0;i<maxChars;i++){
		*(tab+i)=malloc(maxLength+sizeof(char));
		fgets(*(tab+i),maxLength,stdin);
	}
	printTab(tab,maxLength);
	selectionsort(tab,maxLength);
	printTab(tab,maxLength);
	//printf("%s %s %d",a,b,compare(a,b));
}

