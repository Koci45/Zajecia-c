#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int x;
    int y;
    printf("podaj pierwszy wymiar tablicy: ");
    scanf("%d", &x);
    printf("podaj drugi wymiar tablicy: ");
    scanf("%d", &y);

    int **numbers = (int **) malloc(x * sizeof(int *));

    for(int i = 0; i < x; i++){
        numbers[i] = (int *) malloc(y * sizeof(int *));
        for(int j = 0; j < y; j++){
            numbers[i][j] = 0 + rand() % (9);
        }
    }


    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
        free(numbers[i]);
    }

    free(numbers);
    return 0; 
}
