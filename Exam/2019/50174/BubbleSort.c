#include <stdint.h>
#include "BubbleSort.h"

// j = 5
// 76543210
// 01101010
//   ^^
//   ||


void BubbleSort(uint64_t input, uint64_t output[63]) {
    const uint64_t swap = 3;
    for(int i = 0; i < 63; ++i) {
        for(int j = 63; j > 0; --j) {
            uint64_t high = input >> (j - 1);
            uint64_t low = input & ((1ULL << (j - 1)) - 1);

            if(((high & 3ULL) ^ 3ULL) == 1) {
                high ^= swap;
                input = (high << (j - 1)) + low;
            }
        }
        output[i] = input;
    }
}