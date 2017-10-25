//
// Created by shinigami on 25/10/17.
//
#include <stdio.h>
#include <stdlib.h>

#define L 20
#define C 20
char cyfry[] = "0123456789abcdefghijk";
char liczba[L];


//funkcja pomocnicza - zwraca numer znaku n w tablicy cyfry lub -1 jeżeli nie znajdje się w tej tablicy
int cyfra(char c){

    for(int i=0;i<C;i++)
        if(c == cyfry[i])
            return i;

    //else
    return -1;
}
//funkcja pomocnicza - zwraca długość obecnej liczby
int length(){

    for(int i=0;i<L;i++)
        //jeżeli znajedziemy pierwszy znak końca linii to jest długość naszego łańcucha
        if(liczba[i] =='\n' || liczba[i] =='\0' || liczba[i] =='\r') {
            return i;
        }
    //else
    return -1;
}
//funkcja pomocnicza - sprawdza poprawność tablicy liczba, zwraca 1 jeżeli poprawne 0 jeżeli nie poprawne
int isValid(char l[],int baza){
    int isV =1;
    //czy zaczeliśmy czytać liczbę
    int isB =0;
    for(int i=0;i<length();i++){
        //pomijamy całą pętlę jeżeli nasza liczba nie jest poprwna
        if(!isV)
            break;
        //sprawdzamy czy zaczeliśmy czytaś liczbę
        if(!isB && liczba[i] !=' ')
            isB =1;

        //pomijamy resztę tej iteracji jeżeli nie zaczeliśmy czytać liczby
        if(!isB)
            continue;
        //sprawdzenie poprawności
        isV = (cyfra(liczba[i])>-1) && cyfra(liczba[i])<baza;
    }
    return isV;
}

void decNaBaz(int li,int baz){
    int isFin =0;
    for(int i=0;i<=L-1;i++) {

        //wypełnienie spacją charów nie zajmowanych przez liczbę
        if (isFin) {
            liczba[(L - 1) - i] = ' ';
            continue;
        }

        if (li >= 0) {
            //konwersja liczby(int li) cyfrę od tyłu
            liczba[(L - 1) - i] = cyfry[li % baz];
            //pomniejszenie liczby(int li) o pobraną cyfrę
            li /= baz;
        }
        //sprawdzenie czy zakończyliśmy konwersję liczby
        if( li == 0)
            isFin = 1;
    }
}

int bazNaDec(int baz) {
    int licz =0;

    for(int i=0;i<length();i++){
        licz*=baz;
        //jeżeli to poprawna cyfra dodajemy ją do naszej tymczasowej sumy, a następnie mnożymy przez bazę celem uzyskania liczba[n]*baza^n
        if(cyfra(liczba[i]>-1))
            licz+=cyfra(liczba[i]);
    }
    return licz;
}

int main() {

    //inicjalizacja tablicy znaków
    for (int i = 0; i < L - 1; i++)
        liczba[i] = ' ';
    //zakończenie tablicy znakow nullem
    liczba[L - 1] = '\0';

    int baza1, baza2;

    int f;

    do {
    printf("podaj bazę1:");
    scanf("%d", &baza1);
    }while(baza1<2 || baza1>20);//sprawdzenie poprawności danych

    do{
    printf("podaj bazę2:");
    scanf("%d",&baza2);
    }while(baza2<2 || baza2>20);

    do {
        printf("podaj liczbę (%d)", baza1);
        scanf("%s", liczba);
    }while(!isValid(liczba,baza1));

    printf("(%d)%s ->",baza1,liczba);//wyświetlenie oryginalnej wartości
    printf(" (10)%d ->",bazNaDec(baza1));

    decNaBaz(bazNaDec(baza1),baza2);//konwersja
    printf("(%d)%s\n",baza2,liczba);//wyświetlenie przekonwertowanej liczby
}