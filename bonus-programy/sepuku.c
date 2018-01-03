#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define clear() printf("\033[H\033[J")

void restoreHonor(int tab[9][9]);
void commitSepuku(int tab[9][9]);
void dishonorFamily(int tab[9][9]);

int main(){
	int  you[9][9];
	dishonorFamily(you);
	commitSepuku(you);
	restoreHonor(you/*'r family*/);
	
}






























void printSepuku(int tab[9][9]){
	
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			printf(" %1x ", tab[i][j]);
			
			if(j%3==2)
				printf("|");	
		}
		printf("\n");
		
		if(i%3==2){	
			for(int j=0;j<3*(1+3*3);j++)
				printf("-");
		printf("\n");
		}		
	}
}
void restoreHonor(int tab[9][9]){
	printSepuku(tab);
}
void dishonorFamily(int tab[9][9]){
	srand(time(0));
	for(int i=0;i<9*9;i++)
		tab[i/9][i%9]=0;
}
int isInRow(int tab[9][9],int row,int c){
	for(int i =0;i<9;i++)
		if(tab[row][i] == c)
			return 1;
	return 0;
}
int isInCol(int tab[9][9],int col,int c){
	for(int i =0;i<9;i++)
		if(tab[i][col] == c)
			return 1;
	return 0;
}
int isInBox(int tab[9][9],int box,int c){
	for(int i =0;i<9;i++)
		if(tab[(box/3)*3+i/3][(box%3)*3+i%3] == c)
			return 1;
	return 0;
}
int getDigit(int i){
	return i%9+1;//zwracamy cyfrę od 1-9
}
int digitToTry(int d){
	return 1<<(d-1);//BIT Shift - przesuwamy i tyle bitów w lewo
}
void commitSepuku(int tab[9][9]){
	int iter=0;
	int i =0;
	//licznik prób - sprawdza jakie cyfry sprawdziliśmy dla danego miejsca
	int tries[9][9];
	for(int j=0;j<9*9;j++)
		tries[j/9][j%9]=0;

	while(i<9*9){//przechodzimy przez tą pętle aż wypełnimy wszyskie elementy cyframi
		
		iter++;//licznik iteracji

		int z = getDigit(rand()); //losujemy cyfrę (1-9)
		//printf("%d=i\n",i);
		//printSepuku(tab);

		if(tab[i/9][i%9]!=0){//jeżeli na tym miejscu już jest cyfra - poprawiamy tą iterację
			z=getDigit(tab[i/9][i%9]+1);//pobieramy o 1 większą
			tab[i/9][i%9]=0;//zerujemy tablicę - żeby sprawdzić pozostałe cyfry
		}

		//printf("%d:",z);
		while( (tries[i/9][i%9]^0x1ff) /*XOR 1 1=0 |1 0=1*/ )//używamy xora by sprawdzić czy istniją nie sprawdzone komn=binacje
		{
			
			if(!/*WAżna negacja*/ ( (tries[i/9][i%9]&digitToTry(z) /*AND sprawdzamy czy próbowalićmy już tej cyfry*/ )
					       	|| isInCol(tab,i%9,z) 
						|| isInRow(tab,i/9,z)
					       	|| isInBox(tab,3*(i/27)+((i%9)/3),z)) ){
				tab[i/9][i%9]=z;
				tries[i/9][i%9]|=digitToTry(z);//dodajemy cyfrę do listy sprawdzonych
				break;
			}

			tries[i/9][i%9]|=digitToTry(z);//JW
			z=(z+1)%9+1;
		}	
		//printf("%d\n",z);
		//Wybraliśmy cyfrę spełniającą sudoku - przechodzimy do kilejnej iteracji	
		if(tab[i/9][i%9]!=0){
			i++;
			continue;
		}
		//nie mogliśmy znaleśc tej liczby
		//printf("%d %xsepuku resolver %x",i,tries[i/9][i%9],tries[(i-1)/9][(i-1)%9]);
		tab[i/9][i%9]=0;//zerujemy liczniki
		tries[i/9][i%9]=0;
		i--;//cofamy się do poprzedniej cyfry i ją poprawiamy
	}

	printf("solved in %d iterations\n",iter);
}



