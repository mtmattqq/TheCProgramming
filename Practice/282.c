#include <stdio.h>

int main(void) {
    long long n;
    while(scanf("%lld", &n) != EOF) {
        int ct = 0;
        while(n > 0) {
            ct += n & 1;
            n >>= 1;
        }
        printf("%d\n", ct);
    }
}