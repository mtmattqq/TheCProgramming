#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
// #include "spmm.h"

#include <stdio.h>
void sparseMatrixMult(int** A, int** B);

void sparseMatrixMult(int** A, int** B) {
    for(int i = 0; A[i] != NULL; ++i) {
        for(int j = 0; B[j] != NULL; ++j) {
            int ca = 1, rb = 1;
            int sum = 0;
            while(A[i][ca] != -1 && B[j][rb] != -1) {
                if(A[i][ca] < B[j][rb]) {
                    ca += 2;
                } else if(A[i][ca] > B[j][rb]) {
                    rb += 2;
                } else {// A[i][ca] == B[j][rb]
                    sum += A[i][ca + 1] * B[j][rb + 1];
                    ca += 2;
                    rb += 2;
                }
            }
            
            if(sum != 0) {
                printf("%d %d %d\n", A[i][0], B[j][0], sum);
            }
        }
    }
}

int main (void) {
    int P, Q, R, N, M;
    assert(scanf("%d%d%d", &P, &Q, &R) == 3);
    assert(scanf("%d", &N) == 1);
    int** A = (int **) malloc(sizeof(int*)*(N+1));
    for (int i = 0; i < N; i++) {
        int rowIdx, x;
        assert(scanf("%d%d", &rowIdx, &x) == 2);
        int *row = (int *) malloc(sizeof(int)*(x*2+2));
        row[0] = rowIdx;
        for (int i = 0; i < x; i++)
            assert(scanf("%d%d", &row[i*2+1], &row[i*2+2]) == 2);
        row[x*2+1] = -1;
        A[i] = row;
    }
    A[N] = NULL;
 
    assert(scanf("%d", &M) == 1);
    int** B = (int **) malloc(sizeof(int*)*(M+1));
    for (int i = 0; i < M; i++) {
        int colIdx, y;
        assert(scanf("%d%d", &colIdx, &y) == 2);
        int *col = (int *) malloc(sizeof(int)*(y*2+2));
        col[0] = colIdx;
        for (int i = 0; i < y; i++)
            assert(scanf("%d%d", &col[i*2+1], &col[i*2+2]) == 2);
        col[y*2+1] = -1;
        B[i] = col;
    }
    B[M] = NULL;
 
    sparseMatrixMult(A, B);
}