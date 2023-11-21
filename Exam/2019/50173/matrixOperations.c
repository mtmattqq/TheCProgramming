#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "matrixOperations.h"

bool get(uint64_t a, int r, int c) {
    return (a >> (r * 8 + c)) & 1ULL;
}

bool set(uint64_t *a, int r, int c) {
    (*a) |= (1ULL << (r * 8 + c));
}

bool reset(uint64_t *a, int r, int c) {
    (*a) &= (INT64_MAX ^ (1ULL << (r * 8 + c))) ^ (1ULL << 63);
}

void modify(uint64_t *a, int r, int c, int val) {
    if(val == 0) reset(a, r, c);
    else set(a, r, c);
}

void printMatrix(uint64_t *matrix) {
    uint64_t tp = *matrix;
    printf("%llu\n", tp);
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            printf("%llu", (tp & 1ULL));
            tp >>= 1;
        }
        printf("\n");
    }
}

void rotateMatrix(uint64_t *matrix) {
    uint64_t tp = 0, tm = *matrix;
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            modify(&tp, j, 8 - i - 1, get(tm, i, j));
        }
    }

    *matrix = 0;
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            modify(matrix, i, j, get(tp, i, j));
        }
    }
}

void transposeMatrix(uint64_t *matrix) {
    uint64_t tp = 0, tm = *matrix;
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            modify(&tp, j, i, get(tm, i, j));
        }
    }

    *matrix = 0;
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            modify(matrix, i, j, get(tp, i, j));
        }
    }
}