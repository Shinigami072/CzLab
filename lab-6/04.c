#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#define MAX 20
#define M 10
#define N 15
void getRandWord(FILE *fp,char *c,int length);
void getRandWordC(FILE*fp,char *c ,char b,int length);
int main(int argc, char ** argv)
{
	char c[MAX];
	int length =6;
	if(argc<2){
		printf("require 3 arguments\n");
		return -1;
	}
	
	for(int i=0;i<argc;i++)
		printf("%d:%s\n",i,argv[i]);
	
	FILE * fp = fopen(argv[1],"r");
	if(fp ==NULL)
	{
		printf("unable to open %s",argv[1]);
		return 1;
	}

	
	srand(time(0));
	for(int i=0 ;i<4;i++)
	{
		getRandWord(fp,c,length+i);
		printf("%d %s\n",i,c);
		char b = c[0];
		for(int j=0;j<4;j++){
			getRandWordC(fp,c,b,length+i);
			printf("-%d%s\n",j,c);
		}
	}
	
	char tab[M][N+1];
	char temp[N];
	getRandWord(fp,tab[0],N);
	for(int i=0;i<N;i++){
		getRandWordC(fp,temp,tab[0][i],M);
		printf("%c:%s\n",tab[0][i],temp);
		for(int j=0;j<M;j++){
			tab[j][i]=temp[j];
			tab[j][N]=0;
		}
	}
	printf("\n");
	for(int i=0;i<M;i++)
		printf("%s\n",tab[i]);

	fclose(fp);
}

void getRandWord(FILE *fp,char *c,int length){
	long size;
	fseek (fp, 0, SEEK_END);	
 	fgetpos(fp, &size);
	fseek(fp, rand()%size, SEEK_SET);
	fgets(c,MAX,fp);
	while(fgets(c,MAX,fp) != NULL)
 	{
 		if(strlen(c)-1 == length)
			break;
 	}
	
	c[strlen(c)-1]=0;
	return;
}


void getRandWordC(FILE*fp,char *c ,char a,int length){ 
	rewind(fp);
	while(fgets(c,MAX,fp) != NULL)
 	{
 		if(c[0]==a && strlen(c)-1 == length &&random()%10){
			c[strlen(c)-1]=0;
			return;
		}
		else{
		for(int i=rand()%10;i>0;i--)
		fgets(c,MAX,fp);
		}
	}
		c[0]=a;
		for(int i=1;i<length;i++)
			c[i]=' ';
		c[length]=0;
		return;
	
}
