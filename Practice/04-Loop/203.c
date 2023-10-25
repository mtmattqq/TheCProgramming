#include <stdio.h>

void swap(int *, int *);

int main(void) {
    int X, Y, x1, y1, x2, y2, dx1, dy1, dx2, dy2;
    scanf("%d%d", &X, &Y);
    scanf("%d%d", &x1, &y1);
    scanf("%d%d", &x2, &y2);
    scanf("%d%d", &dx1, &dy1);
    scanf("%d%d", &dx2, &dy2);

    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; ++i) {
        x1 += dx1;
        y1 += dy1;
        x2 += dx2;
        y2 += dy2;
        if(x1 <= 1 || x1 >= X) {
            dx1 = -dx1;
        }
        if(y1 <= 1 || y1 >= Y) {
            dy1 = -dy1;
        }
        if(x2 <= 1 || x2 >= X) {
            dx2 = -dx2;
        }
        if(y2 <= 1 || y2 >= Y) {
            dy2 = -dy2;
        }
        if(x1 == x2 && y1 == y2) {
            swap(&dx1, &dx2);
            swap(&dy1, &dy2);
        }

    }

    printf("%d\n%d\n%d\n%d\n", x1, y1, x2, y2);

    return 0;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
    return;
}