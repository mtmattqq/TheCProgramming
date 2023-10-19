#include <stdio.h>
#include <stdbool.h>

#ifdef DEBUG
#define SIZE 55
#else
#define SIZE 505
#endif
#define CASE 6
#define DIR 3

const int dr[10][10] = {
    {0, -1, 1}, // 1 1 1
    {0, 0, 0},  // 1
                // 1
                // 1
    {0, 1, 0},  // 1 1
                // 1
    {0, 1, 1},  // 1 1
                //   1
    {0, 0, 1},  // 1
                // 1 1
    {0, -1, 0}  //   1
                // 1 1
};

const int dc[10][10] = {
    {0, 0, 0},  // 1 1 1
    {0, -1, 1}, // 1
                // 1
                // 1
    {0, 0, 1},  // 1 1
                // 1
    {0, 0, 1},  // 1 1
                //   1
    {0, -1, 0}, // 1
                // 1 1
    {0, 0, -1}  //   1
                // 1 1
};

bool in(int r, int c, int i, int j) {
    return (i >= 0 && i < r && j >= 0 && j < c);
}

int main(void) {
    int r, c;
    scanf("%d%d", &r, &c);
    int bd[SIZE][SIZE] = {0};
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            scanf("%d", &(bd[i][j]));
        }
    }

    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            // for every block;
            for(int k = 0; k < CASE; ++k) {
                bool isv = true;
                for(int l = 0; l < DIR; ++l) {
                    if(
                        !in(r, c, i + dr[k][l], j + dc[k][l]) || 
                        bd[i + dr[k][l]][j + dc[k][l]] != bd[i][j] ||
                        bd[i][j] == 0
                    ) {
                        isv = false;
                    }
                }

                if(isv) {
                    for(int l = 0; l < DIR; ++l) {
                        bd[i + dr[k][l]][j + dc[k][l]] = 0;
                    }
                }
            }
        }
    }

    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            printf("%d ", bd[i][j]);
        }
        printf("\n");
    }

    return 0;
}