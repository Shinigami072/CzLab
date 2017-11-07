#include<stdio.h>
#include<stdlib.h>


double** allocMem(int m,int n){
	//przypisanie pamięci
	double **A = (double **)malloc(sizeof(double *)*m);//przypisujemy pamięć na tablicę pointerów(tablic)
	A[0] = (double *)malloc(sizeof(double)*n*m);//przypisyjemy pamięć na double
	for (int i=1; i<m; i++)
		A[i] = A[0] + i*n; //przypisujemy odpowiednie tablice odpowiednim indexom
	return A;
}

void freeMem(double **A){
	free(*A);//zwolnienie pamięci matrycy A
	free(A);
}

double** initMatrix(double **A,int m,int n){//Funkcja testowa, przyporządkowywuje kolejnym elementom matrycy warośc ichindexu
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			A[i][j] = i*n+j;

	return A;
}

double** readMatrix(int* m,int* n){//wczytanie matrycy ze std in
	scanf("%d %d",m,n);//wczytanie jej rozmiarów TODO: naprawić pomulone koordynaty macierzy

	double **A=allocMem(*m,*n);//przypisanie pamięci
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
double **matrixMultiply(double **A,double **B,int aX,int aY,int bY){//funkja licząca mnożenie macieży
	double **C = allocMem(aX,bY);//deklaracja pamięci na nową macierz

	for(int i=0;i<aX;i++)
		for(int j=0;j<bY;j++){
			C[i][j] = getMatrixValue(A,B,aY,i,j);//wywołanie funkcji liczenia wartości i,j nowej matrycy
		}

	return C;
}

int main(){


	int m =1,n =3,o=4;

	double **C;

	double **A = readMatrix(&m,&n);//pobranie i wyswietlenie matrycy A
	printf("A[%dx%d]\n",m,n);
	displayMatrix(A,m,n);

	double **B = readMatrix(&n,&o);//pobranie i wyświetlenie matrycy B
	printf("B[%dx%d]\n",n,o);
	displayMatrix(B,n,o);

	printf("A*B[%dx%d]\n",m,o);//obliczenie i wyświetlenie matrycy A*B (pomyliłem się przy pisaniu i pomyliłem x,y) TODO:rozwiązać ten problem
	C = matrixMultiply(A,B,m,n,o);
	displayMatrix(C,m,o);


	freeMem(A);
	freeMem(B);
	freeMem(C);
	return 0;
}

