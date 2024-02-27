#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
}  Point; 

typedef struct {
    int bokA;
    int bokB;
} Rect;

void move(Point *p_ptr, int moveByX, int moveByY) {
    p_ptr->x += moveByX;
    p_ptr->y += moveByY;
}

int calcRectArea(Rect *rect){
    return rect->bokA * rect->bokB;
}

int main() {
    Point punkt = {3, 5};
    move(&punkt, 2, 2);
    printf("Nowe wspolrzedne: (%d, %d)\n", punkt.x, punkt.y);

    Rect prostokat = {2, 5};
    int pole = calcRectArea(&prostokat);
    printf("pole prostokata to: %d", pole);
    return 0;
}