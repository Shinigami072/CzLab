#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 20

int main(int argc, char ** argv)
{
	if(argc<3){
		printf("require 3 arguments\n");
		return -1;
	}
	char a[MAX];
	for(int i=0;i<argc;i++)
		printf("%d:%s\n",i,argv[i]);
	
	FILE * fp = fopen(argv[1],"r");
	if(fp ==NULL)
	{
		printf("unable to open %s",argv[1]);
		return 1;
	}
	FILE * wfp = fopen(argv[2],"w");
	if(wfp == NULL)
	{
		printf("unable to open %s",argv[2]);
		return 1;
	}

	int lineCount =0;
	int maxLength =0;
	int c;
	while( fgets(a,MAX,fp)!=NULL ){
		if(feof(fp)){
			printf("EOF");
			break;
		}
		else{
		c = strlen(a)-1;	
		printf("                    %s\r%2d %2d ",a,c,maxLength);
		printf(" check:");
		if(c>maxLength){
			maxLength=c;
			printf("funk this shit im out");
		}
		printf("next\n");
		lineCount++;
		char * c =strstr(a,argv[3]);
		if(c!=NULL && a==c){
			printf("found");
			fputs(a,wfp);	
		}
		}
	}
	printf("L:%d Max_Length:%d",lineCount,maxLength);
	fclose(fp);
	printf("fp closed");
	fclose(wfp);
	printf("wfp closed");
}
