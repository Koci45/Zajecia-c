#include <stdio.h>
#include <stdlib.h>

int main() {
    char ruchGracza1[25];
    char ruchGracza2[25];
    int scores[10000] = {0}; // Initialize scores array with zeros

    for (int i = 0; i < 10000; i++) {
        printf("gracz nr.1 podaj swoj ruch: ");
        scanf("%s", ruchGracza1);

        printf("gracz nr.2 podaj swoj ruch: ");
        scanf("%s", ruchGracza2);

        if (strcmp(ruchGracza1, "kamien") == 0 && strcmp(ruchGracza2, "nozyce") == 0) {
            scores[i] = 1;
        } else if (strcmp(ruchGracza1, "nozyce") == 0 && strcmp(ruchGracza2, "papier") == 0) {
            scores[i] = 1;
        } else if (strcmp(ruchGracza1, "papier") == 0 && strcmp(ruchGracza2, "kamien") == 0) {
            scores[i] = 1;
        } else if (strcmp(ruchGracza2, "kamien") == 0 && strcmp(ruchGracza1, "nozyce") == 0) {
            scores[i] = 2;
        } else if (strcmp(ruchGracza2, "nozyce") == 0 && strcmp(ruchGracza1, "papier") == 0) {
            scores[i] = 2;
        } else if (strcmp(ruchGracza2, "papier") == 0 && strcmp(ruchGracza1, "kamien") == 0) {
            scores[i] = 2;
        } else if (strcmp(ruchGracza1, "wynik") == 0 || strcmp(ruchGracza2, "wynik") == 0) {
            int punktyGracza1 = 0;
            int punktyGracza2 = 0;

            for (int x = 0; x < i; x++) {
                if (scores[x] == 1) {
                    punktyGracza1++;
                } else if (scores[x] == 2) {
                    punktyGracza2++;
                } else {
                    break;
                }
            }

            printf("Punkty gracza 1: %d\n", punktyGracza1);
            printf("Punkty gracza 2: %d\n", punktyGracza2);
            i--;
        }
    }

    return 0;
}