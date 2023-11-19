#include <stdio.h>

typedef struct {
    int n;
    int matrix[9][9];
} Matrix;

void print(Matrix *matrix) {
    for(int i = 0; i < matrix->n; ++i) {
        for(int j = 0; j < matrix->n; ++j) {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

int find_determinant(Matrix matrix) {
    print(&matrix);
    if(matrix.n == 1) {
        return matrix.matrix[0][0];
    }
    int ret = 0;
    for(int i = 0; i < matrix.n; ++i) {
        int sign = i & 1; // 0 for positive
        Matrix next_layer = {0};
        next_layer.n = matrix.n - 1;
        for(int j = 1; j < matrix.n; ++j) {
            int idx = 0;
            for(int k = 0; k < matrix.n; ++k) if(i != k) {
                next_layer.matrix[j - 1][idx++] = matrix.matrix[j][k];
            }
        }
        ret += matrix.matrix[0][i] * 
            (sign ? -1 : 1) * find_determinant(next_layer);
    }
    printf("determinant=%d\n", ret);
    return ret;
}

int main(void) {
    int n;
    scanf("%d", &n);

    Matrix matrix = {0};
    matrix.n = n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &(matrix.matrix[i][j]));
        }
    }
    
    find_determinant(matrix);
}