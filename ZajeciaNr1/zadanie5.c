#include <stdio.h>
#include <stdlib.h>

int main() {
    int liczba;
    printf("Podaj liczbe: ");
    scanf("%d", &liczba);

    if (liczba < 0) {
        printf("Podana liczba jest ujemna. Zwracam 0.\n");
        return 0;
    }

    int wynik = 0;

    for (int i = 1; i < liczba; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            wynik += i;
        }
    }

    printf("wynik to: %d\n", wynik);

    return 0;
}