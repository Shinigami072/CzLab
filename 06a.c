#include <stdio.h>

void dzienZint(int i){
	switch(i){
		case 0:
			printf("Ni");
		break;
		case 1:
			printf("Po");
		break;
		case 2:
			printf("Wt");
		break;
		case 3:
			printf("Sr");
		break;
		case 4:
			printf("Cz");
		break;
		case 5:
			printf("Pt");
		break;
		case 6:
			printf("So");
		break;
}

}



int main(){
	
	int miesc = 1;
	int dzien =1;
	
	printf("Miesiac=");
	scanf("%i",&miesc);
	
	printf("Dien=");
	scanf("%i",&dzien);
	
	printf("Miesac %i\n|",miesc);
	
	for(int i=0;i<7;i++){
		dzienZint(i);
		printf("|");
	}
	int d =1;
	while(d<=31){
		printf("\n|");
		for(int i=0;i<7;i++){
			if(--dzien<=0 && d <=31){
				if(d>=10)
					printf("%i|",d++);
				else
					printf(" %i|",d++);}
			else
				printf("  |");
		}
	}
	printf("\n");
	return 0;
}