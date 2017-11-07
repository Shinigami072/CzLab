#include<stdio.h>
#include<stdlib.h>


double** allocMem(double **A,int m,int n){
	//przypisanie pamięci
	A = (double **)malloc(sizeof(double *)*m);//przypisujemy pamięć na tablicę pointerów(tablic)
	A[0] = (double *)malloc(sizeof(double)*n*m);//przypisyjemy pamięć na double
	for (int i=1; i<m; i++)
		A[i] = A[0] + i*n; //przypisujemy odpowiednie tablice odpowiednim indexom
	return A;
}

double** initMatrix(double **A,int m,int n){//Funkcja testowa, przyporządkowywuje kolejnym elementom matrycy warośc ichindexu
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			A[i][j] = i*n+j;

	return A;
}

double** readMatrix(double **A,int* m,int* n){//wczytanie matrycy ze std in
	scanf("%d %d",m,n);//wczytanie jej rozmiarów

	A=allocMem(A,*m,*n);//przypisanie pamięci
	for (int i = 0; i < *m; i++)//wczytanie wartości z stdin
		for (int j = 0; j < *n; j++){
			scanf("%lf", (A[i]+j));//pokazanie pointera na odpowiedni element tablicy
		}
	return A;
}
void displayMatrix(double **A,int m,int n ) {//funkcja wyświetlająca tablicę
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			printf("%4.4f|", A[i][j]);//wyświetlenie wartosi w danym miejscu tablicy z dokładnością do 4 cyfr po przeninku
		printf("\n");
	}
}

double getMatrixValue(double **A,double **B,int aY,int row,int column){//obliczenie wartości mnożenia macieży dla zadanej kolumny i wiersza
	//aY - ilość kolumn A = iloś rzędów B
	double value = 0;//początkoea wartość
	for(int i=0;i<aY;i++)
		value+=A[row][i]*B[i][column];//dodanie kolenjnego mnożenia elementu rzędu A i kolumny rzędu B
	return value;
}
double **matrixMultiply(double **A,double **B,int aX,int aY,int bY){//funkja liczącamnożenie macieży
	double **C;
	C = allocMem(C,aX,bY);//deklaracja pamięci na nową macierz

	for(int i=0;i<aX;i++)
		for(int j=0;j<bY;j++){
			C[i][j] = getMatrixValue(A,B,aY,i,j);//wywołanie funkcji liczenia wartości i,j nowej matrycy
		}

	return C;
}

int main(){


	int m =1,n =3,o=4;
	double **A;
	double **B;
	double **C;

	A = readMatrix(A,&m,&n);//pobranie i wyswietlenie matrycy A
	printf("A\n");
	displayMatrix(A,m,n);

	B = readMatrix(B,&n,&o);//pobranie i wyświetlenie matrycy B
	printf("B\n");
	displayMatrix(B,n,o);

	printf("A*B\n");//obliczenie i wyświetlenie matrycy A*B
	C = matrixMultiply(A,B,m,n,o);
	displayMatrix(C,m,o);

	free(*A);//zwolnienie pamięci matrycy A
	free(A);

	free(*B);//zwolnienie pamięci matrycy A
	free(B);

	free(*C);//zwolnienie pamięci matrycy A
	free(C);
	return 0;
}

