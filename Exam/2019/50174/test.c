#include <stdio.h>
#include <stdint.h>

// 10010
int main(void) {
    uint64_t a = 0b1001;
    a ^= 3ULL;
    printf("%llu\n", a);

    uint64_t input = 0b11001;
    int j = 3;
    uint64_t high = input >> (j - 1);
    uint64_t low = input & ((1ULL << (j - 1)) - 1);

    printf("%llu\n", (high & 3ULL) ^ 3ULL);
    if(((high & 3ULL) ^ 3ULL) == 1) {
        high ^= 3ULL;
        input = (high << (j - 1)) + low;
    }
    printf("%llu", input);
}