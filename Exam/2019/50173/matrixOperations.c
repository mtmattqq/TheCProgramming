#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "matrixOperations.h"

bool get(uint64_t a, int r, int c) {
    return (a >> (r * 8 + c)) & 1ULL;
}

bool set(uint64_t *a, int r, int c) {

// #ifdef DEBUG
//     uint64_t tp = (1ULL << (r * 8 + c));
//     printf("The matrix for modifying r = %d, c = %d\n", r, c);
//     printMatrix(&tp);
// #endif

    (*a) |= (1ULL << (r * 8 + c));
}

bool reset(uint64_t *a, int r, int c) {

// #ifdef DEBUG
//     uint64_t tp = (INT64_MAX ^ (1ULL << (r * 8 + c))) ^ (1ULL << 63);
//     printf("The matrix for modifying r = %d, c = %d\n", r, c);
//     printMatrix(&tp);
// #endif

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

#ifdef DEBUG
    printMatrix(matrix);
#endif

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

#ifdef DEBUG
    printMatrix(matrix);
#endif

}

#ifdef DEBUG
void test() {
    uint64_t matrix = 2378463553207140481;
    
    printMatrix(&matrix);

    printf("\n");

    rotateMatrix(&matrix);
    printMatrix(&matrix);

    printf("\n");

    transposeMatrix(&matrix);
    printMatrix(&matrix);
}
#endif