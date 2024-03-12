#include <stdio.h>

unsigned long long factorial(unsigned long long x)
{
    if (x == 0 || x == 1)
    {
        return 1;
    }
    else if (x > 1)
    {
        return x * factorial(x - 1);
    }

    /* Catch scenario when x is zero */
    return 0;
}

int main() {
    int number;
    printf("Podaj liczbe: ");
    scanf("%d", &number);
    long long result = factorial(number);
    printf("result:  %lld", result);
    return 0;
}
