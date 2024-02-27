#include <stdio.h>
#include <stdlib.h>

int silnia(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * silnia(n - 1);
}

void oblicz_silnie(int array[], int length) {
    for (int i = 0; i < length; i++) {
        int wynik = silnia(array[i]);
        printf("Silnia z %d = %d\n", array[i], wynik);
    }
}

int main() {
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int length = sizeof(array) / sizeof(array[0]);
    
    oblicz_silnie(array, length);
    
    return 0;
}