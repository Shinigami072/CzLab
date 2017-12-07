#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#define MAX 20
int **mallocTab(int i,int j){
	int **tab= malloc(sizeof(int *)*j);
	tab[0] = malloc(sizeof(int)*i*j);
	for(int x=1;x<j;x++)
		tab[x]=(tab[0]+(x*i));
	return tab;
}
void initTab(int **tab,int i,int j){
	printf("initTab");
	for(int y=0;y<j;y++){
		printf("%d",y);
		for(int x=0;x<i;x++){
			printf(" [%d]",x);
			tab[y][x]=(rand()%MAX);
			printf(" %d",tab[y][x]);
		}
	}
}
void fprintTab(FILE *fp,int **tab,int i,int j){
	fprintf(fp,"%d %d\n",i,j);
	for(int y=0;y<j;y++){
		for(int x=0;x<i;x++)
			fprintf(fp,"%d ",(tab[y][x]));
		fputc('\n',fp);
	}

}
void printTab(int **tab,int i,int j){
	for(int y=0;y<j;y++)
	{
	printf("[");
	for(int x=0;x<i-1;x++)
		printf("%d, ",tab[y][x]);
	printf("%d]\n",tab[y][i-1]);
	
	}
}
void fscanTab(FILE *fp,int **tab,int *i,int* j){
	rewind(fp);
	fscanf(fp,"%d %d",i,j);
	tab = mallocTab(*i,*j);
	for(int y=0;y<*j;y++)
		for(int x=0;x<*i;x++)
			fscanf(fp,"%d",&tab[y][x]);

}
void freeTab(int **tab){
	free(*tab);
	free(tab);
}
int main(int argc, char ** argv)
{
	if(argc-1<3){
		printf("require 3 arguments\n");
		return -1;
	}
	int i = atoi(argv[2]);
	int j = atoi(argv[3]);
	char a[MAX];
	for(int i=0;i<argc;i++)
		printf("%d:%s\n",i,argv[i]);
	
	FILE * fp = fopen(argv[1],"w");
	if(fp ==NULL)
	{
		printf("unable to open %s",argv[1]);
		return 1;
	}
	int **tb = mallocTab(i,j);
	printf("malloc\n");
	srand(time(0));
	initTab(tb,i,j);
	printf("initialized\n");
	fprintTab(fp,tb,i,j);
	printf("written\n");
	printTab(tb,i,j);
	freeTab(tb);
	fclose(fp);
	printf("closing\n");
	
	fp = fopen(argv[1],"r");
	printf("reading\n");
	fscanTab(fp,tb,&i,&j);
	printTab(tb,i,j);
	printf("fp closed");
}
