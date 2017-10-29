//
// Created by shinigami on 25/10/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define clear() printf("\033[H\033[J")

int board[][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
        };

int validateInput(int i,int j){
    if(i<3 && i>=0 && j<3 && j>=0)
        return !board[i][j];
    return 0;
}

int checkRow(int r){
    int rowState=0;
    for(int i=0;i<3;i++)
        rowState+=board[i][r];
    if(rowState == 3)
        return 1;
    if(rowState == -3)
        return -1;
    return 0;
}

int checkColumn(int c){

    int colState=0;
    for(int i=0;i<3;i++)
        colState+=board[c][i];
    if(colState == 3)
        return 1;
    if(colState == -3)
        return -1;
    return 0;
}

int checkDiagon(){
    int diagState=0;
    for (int i = 0; i < 3; i++) {
        diagState+=board[i][i];
    }
    if(diagState == 3)
        return 1;
    else if(diagState == -3)
        return -1;


    diagState=0;

    for (int i = 0; i < 3; i++) {
        diagState+=board[2-i][i];
    }

    if(diagState == 3)
        return 1;
    else if(diagState == -3)
        return -1;
    else
        return 0;
}

int gameState(){
    int state = checkDiagon();
    if(state !=0)
        return state;
    for(int i=0;i<3;i++){
        state = checkColumn(i);
        if(state !=0)
            return state;
        state = checkRow(i);
        if(state !=0)
            return state;
    }

    return 0;
}

char stateToChar(int state){
    char c = '0'+state;
    switch(state){
        case 1: c='O'; break;
        case -1: c='X'; break;
        case 0: c=' '; break;
    }
    return c;
}

void drawBoard(int tura,int gracz) {
    clear();

    if(!gameState())
        printf(" Tura %d - %c\n", tura, stateToChar(gracz));
    else
        printf(" Wygrywa Gracz %c\n", stateToChar(gameState()));

    printf("┏━┳━┳━┓\n");
    for (int i = 0; i < 3; i++) {
        printf("┃");
        for (int j = 0; j < 3; j++)
            printf("%c┃",stateToChar(board[i][j]));
        if(i!=2)
        printf("\n┣━╋━╋━┫\n");
    }
    printf("\n┗━┻━┻━┛\n");
}

void AI(int symbol){
    int i;
    do{
        i = random()%9;
    }while(board[i/3][i%3]!=0);
    board[i/3][i%3]=symbol;
}
int main(){
    int i,j;
    int tura =0;
    int gracz = 1;
    srand( time(NULL) );
    int ai = random()%2 ? -1: 1;

    while(gameState() == 0 && tura<9) {
        drawBoard(++tura, gracz);
        if (gracz != ai) {
            do {
                printf("wybierz pozycję:\n");
                scanf("%d %d", &j, &i);
            } while (!validateInput(i, j));
            board[i][j] = gracz;
        }
        else
            AI(ai);

        gracz = -gracz;
    }
    drawBoard(tura,gracz);

}