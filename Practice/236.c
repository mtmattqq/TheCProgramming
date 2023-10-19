#include <stdio.h>

int gcd(int, int);
int lcm(int, int);

int main(void) {
    int n, ans;
    
    scanf("%d", &ans);
    while(scanf("%d", &n) != EOF) {
        ans = lcm(ans, n);
    }

    printf("%d", ans);

    return 0;
}

int gcd(int a, int b) {
    return a % b == 0  ?  b  :  gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}