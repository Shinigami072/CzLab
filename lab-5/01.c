#include<stdio.h>
#include<stdlib.h>

char mostFrequentChar(char * in){
	int occurences[255];
	for(int i=0;i<255;i++)
		occurences[i]=0;
	char mostfrequent =0;
	int i =0;
	while(in[i] !='\0'){
		printf("%c",in[i]);
		occurences[in[i]]+=1;
		if(occurences[in[i]] > occurences[mostfrequent])
			mostfrequent=in[i];
		i++;
	}
	return mostfrequent;
}

int main(){
	char *s = "";
	printf("%c",mostFrequentChar(s));
}
