#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int count_bit(uint32_t a, int size) {
    int ret = 0;
    for(int i = 0; i < size; ++i) {
        if(a & 1) ret++;
        a >>= 1;
    }
    return ret;
}

uint32_t find_ans(uint32_t n, int size) {
    if(size == 1) {
        return n;
    }

    int one_num = count_bit(n, size);
    size = size >> 1;
    uint32_t a = n >> size, b = n & ((1U << size) - 1);

    uint32_t pa, pb;
    if(one_num & 1) {
        pa = find_ans(b, size);
        pb = find_ans(a, size);
    } else {
        pa = find_ans(a, size);
        pb = find_ans(b, size);
    }
    return (pa << size) + pb;
}

int main(void) {
    uint32_t a;
    scanf("%u", &a);
    uint32_t ans = find_ans(a, 32);
    printf("%u\n", ans);
}