#include <stdio.h>
#include <stdlib.h>

int dodawanie(int a, int b) {
    return a + b;
}

int mnozenie(int a, int b) {
    return a * b;
}

int odejmowanie(int a, int b) {
    return a - b;
}

int operacja(int a, int b, int (*pf)(int, int)) {
    return pf(a, b);
}

int main() {

    int (*pf)(int, int);
    
    printf("jesli chcesz dodac wcisnij 1, jesli odjac wcisnij 2, jesli mnozyc wcisnij 3 : ");
    int a;
    int b;
    int wybor;
    int wynik;
    scanf("%d", &wybor);

    printf("podaj pierwsza liczbe: ");
    scanf("%d", &a);
    printf("podaj druga liczbe: ");
    scanf("%d", &b);

    if (wybor == 1) {
        pf = &dodawanie;
    }

    if (wybor == 2) {
        pf = &odejmowanie;
    }

    if (wybor == 3) {
        pf = &mnozenie;
    }

    wynik = operacja(a, b, pf);
    printf("wynik : %d\n", wynik);

    return 0;
}
