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
int main ( int argc, char *argv[] )
{
	buffer = malloc(bufferSize);
	char *strings[10];
	int stringI =0;
	for(int i =0;i<10;i++){
	strings[stringI]=readS();
	//sprawdzenie poprawności
	if(!strings[stringI])
		return -1;
	stringI++;	
	}
	printStrings(strings,stringI);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
