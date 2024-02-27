#include <stdio.h>
#include <stdlib.h>

void wpisz(int oceny[][5], int przedmiot);

int main() {
    int oceny[2][5]; // Assuming 2 subjects (math, physics) and 5 grades for each subject

    printf("wprowadz oceny z matematyki \n");
    wpisz(oceny, 0);

    printf("wprowadz oceny z fizyki \n");
    wpisz(oceny, 1);

    int sumaMatematyka = 0;
    for (int i = 0; i < 5; i++) {
        sumaMatematyka += oceny[0][i];
    }

    int sumaFizyka = 0;
    for (int i = 0; i < 5; i++) {
        sumaFizyka += oceny[1][i];
    }

    float sredniaMatma = (float)sumaMatematyka / 5;
    float sredniaFizyka = (float)sumaFizyka / 5;

    printf("srednia z matematyki to: %f \n", sredniaMatma);
    printf("srednia z fizyki to: %f \n", sredniaFizyka);

    return 0;
}

void wpisz(int oceny[][5], int przedmiot) {
    for (int i = 0; i < 5; i++) {
        printf("%d ocena: \n", i);
        scanf("%d", &oceny[przedmiot][i]);
    }
}