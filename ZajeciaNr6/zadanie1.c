#include <stdio.h>
#include <stdlib.h>

union unia{
  int theInt;
  float theFloat;
  char theChar;
  char bytes[sizeof(int)];
};

int main(){

    union unia intFloatChar;
    intFloatChar.theInt = 1;
    printf("unia z intem %d\n", intFloatChar.theInt);
    intFloatChar.theFloat = 1.5;
    printf("unia z floatem %f\n", intFloatChar.theFloat);
    intFloatChar.theChar = 'a';
    printf("unia z charem %c\n", intFloatChar.theChar);
}
