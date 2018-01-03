/*
 * =====================================================================================
 *
 *       Filename:  02.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/01/18 08:15:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Krzysztof Stasiowski (ks), krzys.stasiowski@gmail.com
 *        Company:  N/A
 *
 * =====================================================================================
 */
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char const **argv){
	int sum =0;
    char *c;
	for (int i=1;i<argc;i++)
	{
        int j =strtol(argv[i],&c,10);
        if(j ==0 && argv[i]==c)
        {
            printf("BŁĄD - nieporawny numer: %s %s\n",argv[i],c);
            return -1;
        }
        sum+=j;
	}
	printf("suma: %d\n",sum);
}



