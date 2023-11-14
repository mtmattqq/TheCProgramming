#include <stdio.h>
#include <stdint.h>

int main(void) {
    int n;
    scanf("%d", &n);

    uint64_t a;
    for(int i = 0; i < n; ++i) {
        scanf("%llu", &a);
        for(int j = 0; j < 12; ++j) {
            printf("%c", (char)(a & ((1ULL << 5) - 1)) + 'a');
            a >>= 5;
        }
    }
    return 0;
}