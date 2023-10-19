#include <stdio.h>
#include <stdbool.h>

int main() {
    long long s, f, t;
    scanf("%lld%lld%lld", &s, &f, &t);

    bool isv = true;

    long long c = s - t;
    isv &= c >= 0;
    isv &= ((f - 8LL * c - 2LL * t) % 2 == 0);
    long long b = (f - 8LL * c - 2LL * t) / 2LL;
    isv &= b >= 0;
    long long a = t - b;
    isv &= a >= 0;

    if(isv) {
        printf("%lld\n%lld\n%lld\n", a, b, c);
    } else {
        printf("0\n");
    }
    return 0;
}