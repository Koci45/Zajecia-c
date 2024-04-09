#include <stdio.h>
#include <stdlib.h>


int main(){

    int tablica[10];
    tablica[0] = 0;
    tablica[1] = 1;
    tablica[2] = 2;
    tablica[3] = 3;
    tablica[4] = 4;
    tablica[5] = 5;
    tablica[6] = 6;
    tablica[7] = 7;
    tablica[8] = 8;
    tablica[9] = 9;

    int * pointer = tablica;
    int i = 0;

    for(int i = 0; i < 10; i++){
        printf("%d\n", *pointer + i);
    }
}
