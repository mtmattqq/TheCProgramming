#include <stdio.h>

int main(void) {
    int a, b, c, d, e, f, g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);

#ifdef DEBUG
    printf("%d %d %d %d %d %d %d", a, b, c, d, e, f, g);
#endif

    printf("%d\n", a + b + c + d + (a + b + c) * e + (c + d) * f + e * g + f + g);
    printf("%d\n", (a + b + c) * e * g + (c + d) * f);
}