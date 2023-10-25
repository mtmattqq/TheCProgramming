#include <stdio.h>

int main() {
    long long s, f, t;
    scanf("%lld%lld%lld", &s, &f, &t);

    long long c = s - t;
    long long b = (f - 8LL * c - 2LL * t) / 2LL;
    long long a = t - b;

    printf("%lld\n%lld\n%lld\n", a, b, c);
    return 0;
}