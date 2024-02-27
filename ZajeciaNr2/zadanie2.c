#include <stdio.h>
#include <stdlib.h>

void doubleVar(float *f){
    *f *= 2;
}

int main() {
    
    float num = 6.78;
    doubleVar(&num);
    printf("%f",num);
    return 0;
}