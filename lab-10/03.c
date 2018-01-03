#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define BUFFER 1024

int main(int argc,char const **argv){
	FILE *in;
	FILE *out;
	enum ConvertType {NONE,UPPER,LOWER,SWAP};
	
	enum ConvertType c = NONE;
	char b[BUFFER];
	for(int i=1;i<argc;i++){
		if(argv[i][0]=='-'){
			
			for(int j=1;argv[i][j] != '\0';j++)
				switch(argv[i][j]){
					case 'u':
						c=UPPER;
					break;
					case 'l':
						c=LOWER;
					break;
					case 'r':
						c=SWAP;
					break;
				}
				
		}
		
		else if(in == NULL)
			in=fopen(argv[i],"r");
		else
			out=fopen(argv[i],"w");
			
	}
	
	while(fgets(b,BUFFER,in)){
		for(int i=0; b[i]!='\0' && i<BUFFER;i++){
		switch(c){
			case UPPER:
				b[i]=toupper(b[i]);
			break;
			case LOWER:
				b[i]=tolower(b[i]);
			break;
			case SWAP:
				if(islower(b[i]))
					b[i]=toupper(b[i]);
				else
					b[i]=tolower(b[i]);
			break;
			case NONE:
			break;
		}
	}
		printf("%s",b);
		fprintf(out,"%s",b);
	}
	return 0;


}
