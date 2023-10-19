#include <stdio.h>

#ifdef DEBUG
#define SIZE 15
#else
#define SIZE 105
#endif

enum type{GREEN, BLUE};

// 1 2 3
// 4 5 6
// 7 8 9

// 7 4 1
// 8 5 2
// 9 6 3

void green(
    int cube[SIZE][SIZE][SIZE], 
    int chip[SIZE][SIZE], 
    int idx, int n
) {// idx = x
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            chip[i][j] = cube[idx][n - j - 1][i];
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cube[idx][i][j] = chip[i][j];
        }
    }
}

void blue(
    int cube[SIZE][SIZE][SIZE], 
    int chip[SIZE][SIZE], 
    int idx, int n
) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            chip[i][j] = cube[n - j - 1][i][idx];
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cube[i][j][idx] = chip[i][j];
        }
    }
}

int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);

    int cube[SIZE][SIZE][SIZE] = {0}, chip[SIZE][SIZE];
    for(int i = 0; i < n * n * n; ++i) {
        int a = i / (n * n);
        int b = (i / n) % n;
        int c = i % n;
        cube[a][b][c] = i;
    }

    int type, idx;
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &type, &idx);
        switch(type) {
          case GREEN :
            green(cube, chip, idx, n);
            break;
          case BLUE :
            blue(cube, chip, idx, n);
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < n; ++k) {
                printf("%d ", cube[i][j][k]);
            }
            printf("\n");
        }
    }
    
    return 0;
}