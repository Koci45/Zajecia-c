#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int num = 5;
    int* refToNum = &num;

    *refToNum = 6;

    printf("%d", num);

    return 0;
}
