/*
 * =====================================================================================
 *
 *       Filename:  01.c
 *
 *    Description:  PArametry wywołania
 *
 *        Version:  1.0
 *        Created:  03/01/18 08:07:37
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

int main(int argc, char const **argv){
	for(int i=0;i<argc;i++)
	{
	printf("argv[%d]=%s\n",i,argv[i]);
	}
}
