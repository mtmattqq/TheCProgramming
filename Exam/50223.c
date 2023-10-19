#include <stdio.h>

int abs(int);

int main(void) {
    int w, a, b, c, d, e;
    scanf("%d%d%d%d%d%d", &w, &a, &b, &c, &d, &e);

    int l = a + b + c;
    if(b > 0) {
        l += d * 2 + e * 2 + 2;
    } else {
        l += d + abs(d - e) + e + 2;
    }

    printf("%d", l * l + w * w);
    return 0;
}

int abs(int a) {
    return (a > 0  ?  a  :  -a);
}