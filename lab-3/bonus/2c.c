//
// Created by shinigami on 25/10/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define clear() printf("\033[H\033[J")//to czyści ekran na unix

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

int checkRow(int r,int board[3][3]){
    int rowState=0;
    for(int i=0;i<3;i++)
        rowState+=board[i][r];
    if(rowState == 3)
        return 1;
    if(rowState == -3)
        return -1;
    return 0;
}

int checkColumn(int c,int board[3][3]){

    int colState=0;
    for(int i=0;i<3;i++)
        colState+=board[c][i];
    if(colState == 3)
        return 1;
    if(colState == -3)
        return -1;
    return 0;
}

int checkDiagon(int board[3][3]){
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

int gameState(int board[3][3]){
    int state = checkDiagon(board);
    if(state !=0)
        return state;
    for(int i=0;i<3;i++){
        state = checkColumn(i,board);
        if(state !=0)
            return state;
        state = checkRow(i,board);
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

void drawBoard(int tura,int gracz,int board[][3]) {
    //clear();

    if(!gameState(board))
        if(tura>=9)
            printf(" Remis\n");

        else
            printf(" Tura %d - %c\n", tura, stateToChar(gracz));
    else
        printf(" Wygrywa Gracz %c\n", stateToChar(gameState(board)));

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
int choice( int board[3][3], int target){

    if(gameState(board) !=0)
        return  (target==gameState(board)) ? 10: -10;

    int score =-2;
    int move =-1;

    for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if (board[i][j] == 0) {

                board[i][j] = target;
                int temp = -choice(board,-target);
                if(temp > score){
                    move=i;
                    score=temp;
                }
                board[i][j]=0;
            }

    if(move==-1)
        return 0;

    return score;


}
void AI(int symbol){

    int score =-2;
    int move =-1;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if (board[i][j] == 0) {

                board[i][j] = symbol;
                int temp = -choice(board,-symbol);
                if(temp > score){
                    move=i*3+j;
                    score=temp;
                }
                board[i][j]=0;
            }

    board[move/3][move%3]=symbol;


}
void playerInput(int symbol){
    int i,j;

    do {
        printf("wybierz pozycję:\n");
        scanf("%d %d", &j, &i);
    } while (!validateInput(i, j));
    board[i][j] = symbol;
}
int main(){
    srand( time(NULL) );
    int ai = random()%2 ? -1: 1;
    int currentPlayer = 1;

    int tura;
    for(tura=0; gameState(board) == 0 && tura<9 ; currentPlayer = -currentPlayer, tura++) {
        drawBoard(tura, currentPlayer,board);
        if (currentPlayer != ai)
            playerInput(currentPlayer);
        else
            AI(ai);


    }

    drawBoard(tura,currentPlayer,board);

}