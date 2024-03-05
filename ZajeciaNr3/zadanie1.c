#include <stdio.h>
#include <stdlib.h>

int factorial(int number);

int newton(int n, int k);

void drawTriangle(int size);

int newton(int n, int k) {
    int result = factorial(n) / (factorial(k) * factorial(n - k));
    return result;
}

void drawTriangle(int size) {
    for (int n = 0; n < size; n++) {
        for (int k = 0; k <= n; k++) {
            int number = newton(n, k);
            printf("%d ", number);
        }
        printf("\n");
    }
}

int factorial(int number) {
    int result = 1;
    for (int i = 1; i <= number; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int size;
    printf("Podaj wielkosc trojkata: ");
    scanf("%d", &size);
    drawTriangle(size);
    return 0;
}
