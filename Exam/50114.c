#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int ax, ay, bx, by, cx, cy, dx, dy;
    scanf("%d%d%d%d%d%d%d%d", 
        &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);
    printf("%d\n", 2 * (abs(ax - cx) + abs(ay - cy)));
    printf("%d\n", abs(ax - dx) * abs(ay - dy) + 
        abs(bx - cx) * abs(by - cy) + 
        abs(ay - cy) * (bx - dx));
    return 0;
}