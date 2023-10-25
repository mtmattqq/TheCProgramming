#include <stdio.h>

int main() {
    int a, b, c, d, e;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    
    int surface_area = 2 * (a * b + b * c + c * a);
    surface_area += 8 * ((a - 2 * e) * d);
    surface_area += 8 * ((b - 2 * e) * d);
    surface_area += 8 * ((c - 2 * e) * d);
    printf("%d\n", surface_area);

    int volume = a * b * c;
    volume -= 2 * (a - 2 * e) * (b - 2 * e) * d;
    volume -= 2 * (b - 2 * e) * (c - 2 * e) * d;
    volume -= 2 * (c - 2 * e) * (a - 2 * e) * d;
    printf("%d\n", volume);
    return 0;
}