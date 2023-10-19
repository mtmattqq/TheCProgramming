#include <stdio.h>

int main(void) {
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);

    printf("%d\n", (a + b + c + d + e + f) * 2);
    printf("%d\n", a * (b + d + f) + c * (d + f) + e * f);
}