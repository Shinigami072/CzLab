//
// Created by shinigami on 25/10/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define clear() printf("\033[H\033[J")//to czyści ekran na unix



int const winConditions[][3] = {
        {0,1,2},{3,4,5},{6,7,8},//wiersze
        {0,3,6},{1,4,7},{2,5,8},//kolumny
        {0,4,8},{2,4,6}//przekatne
};
int const winConditionSize = 8;

int gameState(int board[9]){
    //przechodzimy przez wszyskie kombinacje zakończenia gry
    for(int i=0;i<winConditionSize;i++)
        if(board[winConditions[i][0]] != 0)        //sprawdzamy czy jest symbol w 0 miejscu
            if(board[winConditions[i][1]] == board[winConditions[i][2]]
               && board[winConditions[i][0]]==board[winConditions[i][1]] )//sprawdzamy czy wszyskie miejsca mają ten sam symbol
                return board[winConditions[i][0]];//zwracamy wygrywający symbol
    //inaczej zwracamy remis
    return 0;
}

int validateInput(int i,int j, int board[9]){
    if(i<3 && i>=0 && j<3 && j>=0)//sprawdzamy czy można wykonać ruch w podanej lokacji
        return !board[3*i+j];
    return 0;
}

void playerInput(int symbol,int board[9]){
    int i,j;

    do {
        printf("wybierz pozycję:\n");
        scanf("%d %d", &j, &i);//pobieramy ruchy aż uzyskamy legalny ruch
    } while (!validateInput(i, j,board));

    board[3*i+j] = symbol;
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

void drawBoard(int turn,int currentPlayer ,int board[9]) {
    clear();

    //Status
    if(!gameState(board))
        if(turn>=9)
            printf(" Remis\n");
        else
            printf(" Tura %d - %c\n", turn, stateToChar(currentPlayer));
    else
        printf(" Wygrywa Gracz %c\n", stateToChar(gameState(board)));

    //rysowanie planszy
    printf("┏━┳━┳━┓\n");
    for (int i = 0; i < 3; i++) {
        printf("┃%c┃%c┃%c┃\n",
               stateToChar(board[3*i+0]),
               stateToChar(board[3*i+1]),
               stateToChar(board[3*i+2]));
        if(i!=2)
        printf("┣━╋━╋━┫\n");
    }
    printf("┗━┻━┻━┛\n");
}

int choice( int board[9], int target){

    if(gameState(board) !=0)
        return  gameState(board);

    int score =-2;//upewniamy się że przegrywanjący ruch jest lepszy od braku ruchu
    int move =-1;

    for(int i=0;i<9;i++)
        if (board[i] == 0) {
            board[i] = target;//modyfikujemy w celu sprawdzenia

            int temp = -choice(board,-target);//sprawdzamy jak zareagowałby przeciwnik
            if(temp > score || (temp==score && random()%2)){//jeżeli ten ruch jest lepszy lub tak samo dobry
                move=i; //aktualizujemy najlepszy wybór
                score=temp;
            }
            board[i]=0;//wracamy do poprzedniego stanu
        }

    if(move==-1)
        return 0;

    return score;


}
void AI(int target, int board[9]){

    int score =-2;//upewniamy się że przegrywanjący ruch jest lepszy od braku ruchu
    int move =-1;

    for(int i=0;i<9;i++)
        if (board[i] == 0) {
            board[i] = target;//modyfikujemy w celu sprawdzenia

            int temp = choice(board,target);//sprawdzamy jak dobrym ruchem jest ten ruch
            if(temp > score || (temp==score && random()%2)){//jeżeli ten ruch jest lepszy lub tak samo dobry
                move=i; //aktualizujemy najlepszy wybór
                score=temp;
            }
            board[i]=0;//wracamy do poprzedniego stanu
        }

    board[move]=target; //wybieramy najlepszy ruch


}

int main(){
    srand( time(NULL) );
    int ai = random()%2 ? -1: 1;//losujemy którym graczem bedzie sterował komputer
    int currentPlayer = 1;

    int board[9] = {
            0,0,0,
            0,0,0,
            0,0,0
    };

    int tura;

    for(tura=0; gameState(board) == 0 && tura<9 ; currentPlayer = -currentPlayer, tura++) {
        drawBoard(tura, currentPlayer,board);

        if (currentPlayer != ai)
            playerInput(currentPlayer,board);
        else
            AI(currentPlayer,board);
    }

    drawBoard(tura,currentPlayer,board);

}