//
// Created by shinigami on 07/11/17.
//
#include <stdio.h>
#define N 7

enum DIRECTION{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

void printArray(int A[N][N]) {//funkcja pomocnicza, wyświetlenie tabeli
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%2d, ",A[j][i]);
        printf("\n");
    }
}

int main() {

    int A[N][N]; //deklaracja i zerowanie tabeli
    for(int i=0;i<N*N;i++)
        A[i/N][i%N]=0;

    int i = 1;
    enum DIRECTION d = RIGHT;//ustawienie oczątkowego kierunku spirali

    int x = 0; //ustalenie pozycji startowej
    int y = 0; //
    while (i <= N * N) {
        A[x][y]=i++;//wpisanie liczby
        //printf("(%d,%d)%d - %d\n",x,y,d,i);
        switch (d) {//sprawdzenie w którym kierunku mamy przejść tabelę
            case RIGHT://pozostałe kierunki są rozwiązane analogicznie
                if(x+1 >=N || A[x+1][y]!=0) {//spradzenie czy doszliśmy do brzegu aszego kwadratu
                    d = DOWN;//ustawienie nowego kierunku
                    y++;//ustawienie nowej pozycji
                }else
                    x++;//ustawienie noewj pozycji zgodnie z kierunkiem
            break;
            case DOWN:
                if(y+1 >=N || A[x][y+1]!=0) {
                    d = LEFT;
                    x--;
                }else
                    y++;
            break;
            case LEFT:
                if(x-1 <0 || A[x-1][y]!=0){
                    d=UP;
                    y--;
                }
                else
                    x--;
            break;
            case UP:
                if(y-1 <0 || A[x][y-1]!=0){
                    d=RIGHT;
                    x++;
                }
                else
                    y--;
            break;
        }

    }


    //wydrukowanie Tablicy
    printArray(A);

}
