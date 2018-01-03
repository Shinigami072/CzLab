/*
 * =====================================================================================
 *
 *       Filename:  03.c
 *
 *    Description:  String Madness
 *
 *        Version:  1.0
 *        Created:  06/12/17 08:49:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Krzysztof Stasiowski (ks), krzys.stasiowski@gmail.com
 *        Company:  N/A
 *
 * =====================================================================================
 */
#include<stdlib.h>
#include<stdio.h>
# define BUFFER_EXP 1
#define BUFFER_SIZE 1
#define DEBUG 0
char *buffer;
int bufferSize =BUFFER_SIZE+2;

int len(char *s){
	int i =0;
	while(s[i] !=0)
		i++;
	return i;
}

char *readS(){
	//wczytujemy pierwotny string do bufforu
	fgets(buffer,bufferSize,stdin);
	//pobieramy długość pierwotnego stringa
	int strLen = len(buffer);
	//debug output
	if(DEBUG)
	printf("%s, %d, %c\n",buffer,strLen,buffer[strLen-1]);
	//wczutujemy do buffou aż nie wczytamy całości
	char *tBuf;
	while(buffer[strLen-1] != '\n'){
		//rozszeżamy buffor
		tBuf =realloc(buffer,(bufferSize+BUFFER_EXP)*sizeof(char));
		if(!tBuf)
			return NULL;//w przypadku błeðu allokcaji zwracamy null
		buffer=tBuf; //Aktualizujemy dane o bufforze
		bufferSize+=BUFFER_EXP;	
		
		//pobieramy kolejne znaki -
		//zapisujemy je w odpowiednim miejscu buffora
		fgets(buffer+strLen,bufferSize-strLen,stdin);
		//aktualizujemy długość string
		strLen=len(buffer);
		//debug output
		if(DEBUG)
		printf("%s, %d, %d\n",buffer,strLen,bufferSize);
	}
	
	//allokujemy pamięć na string
	char *str = malloc(strLen*sizeof(char));
	
	//zwarcamy NULL w przypadku błędu
	if(!str)
		return NULL;
	//kopiujemy char do str 
	for(int i=0;i<strLen;i++){
		str[i]=buffer[i];
		buffer[i]='\0';//czyścimy buffor
	}
	str[strLen-1]='\0'; //zamieniamy \n na \0
	//debug output
	if(DEBUG)
	printf("%s\n",str);

	return str;	

}
void printStrings(char **strings,int size){
	for(int i=0;i<size;i++)
		printf("%d %s\n",i,strings[i]);	
}
void freeStrings(char **strings,int size){
	for(int i=0;i<size;i++)
		if(strings[i])
			free(strings[i]);
	free(strings);	
}
int main ( int argc, char *argv[] )
{
	buffer = malloc(bufferSize);
	char **strings;
	int stringBuffSize =1;
	strings = malloc(stringBuffSize* sizeof(char *));
	int stringI =0;

	if(!strings){
		return -1;
	}

	while(stringI<stringBuffSize){
	
	if(stringI +1 >= stringBuffSize){
		stringBuffSize+=1;
	}
	
	char ** t = realloc(strings,stringBuffSize* sizeof(char *));
	if(!t)
		return -1;
	strings = t;
	
	char *c =readS();
	//sprawdzenie poprawności
	if(!c)
		return -1;
		
	if(len(c) == 0)
		break;
	
	strings[stringI++]=c;
	}
	printf("%d %d\n",stringI,stringBuffSize);
	printStrings(strings,stringI);
	freeStrings(strings,stringBuffSize);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
