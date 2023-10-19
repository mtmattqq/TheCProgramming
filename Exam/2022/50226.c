#include <stdio.h>

int gcd(int, int);
int lcm(int, int);

int main(void) {
    int a, b, c, d;
    while(scanf("%d%d%d%d", &a, &b, &c, &d) != EOF) {
        printf("%d\n", lcm(lcm(lcm(a, b), c), d) / a);
    }
    return 0;
}

int gcd(int a, int b) {
    return a % b == 0  ?  b  :  gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}