#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#define MAX 20
char * getChar(FILE *fp,const char *c,int min,int max){
	rewind(fp);
	char *a = malloc(sizeof(char)*MAX);
	while( fgets(a,MAX,fp)!=NULL ){
		if(feof(fp)){
			break;
		}else{
			 if(strlen(a)-1<min || strlen(a)-1>max)
				continue;
			char * f =strstr(a,c);
			if(f == a && f != NULL && rand()%2)
					return a;
		}
	}

	return NULL;
}
char * getCharC(FILE *fp,const char c,int min,int max){
	rewind(fp);
	char *a = malloc(sizeof(char)*MAX);
	while( fgets(a,MAX,fp)!=NULL ){
		if(feof(fp)){
			break;
		}else{
			 if(strlen(a)-1<min || strlen(a)-1>max)
				continue;
			if(c == a[0] && rand()%2)
					return a;
		}
	}

	return NULL;
}
void getWord(FILE * fp,char *c,int length){
	c=getChar(fp,"",length,length);
	printf("%s",c);
}
void getWordC(FILE *fp,char *c,char cr,int length){
	c=getCharC(fp,cr,length,length);
	printf("%s\n",c);
}


int main(int argc, char ** argv)
{
	if(argc<2){
		printf("require 3 arguments\n");
		return -1;
	}
	char a[4][MAX];
	char b[MAX]; 
	for(int i=0;i<argc;i++)
		printf("%d:%s\n",i,argv[i]);
	
	int i =4;
	int j =5;
	FILE * fp = fopen(argv[1],"r");
	if(fp ==NULL)
	{
		printf("unable to open %s",argv[1]);
		return 1;
	}

	getWord(fp,a[0],5);
	printf("%s\n",a[0]);
	for(int i=0;i<5;i++){
		getWordC(fp,b,a[0][i],4);
		printf("%s\n",b);
		for(int j=0;j<4;j++)
			a[j][i]=b[j];
	}

	for(int i=0;i<5;i++)
		printf("%s\n",a[i]);

	
	
	srand(time(0));
	fclose(fp);
}
