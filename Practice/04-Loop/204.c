#include <stdio.h>

// -------
// |  0  |
// |3 + 1|
// |  2  |
// -------

const int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};

int main(void) {
    int w, d;
    scanf("%d%d", &w, &d);
    int mir[105][105];

    for(int i = 1; i <= d; ++i) {
        for(int j = 1; j <= w; ++j) {
            scanf("%d", &mir[i][j]);
            mir[i][j]++;
        }
    }

    // Building the flag
    // number 1 ~ w
    for(int i = 1; i <= w; ++i) {
        mir[d + 1][i] = -(i - 1);
    }
    // number w + 1 ~ w + d
    for(int i = 1; i <= d; ++i) {
        mir[i][w + 1] = -(w + d - i);
    }
    // number w + d + 1 ~ w + d + 1 + w
    for(int i = 1; i <= w; ++i) {
        mir[0][i] = -(2 * w + d - i);
    }
    // number 2w + d + 1 ~ 2w + 2d
    for(int i = 1; i <= d; ++i) {
        mir[i][0] = -(2 * w + d + i - 1);
    }

    // for(int i = 0; i <= d + 1; ++i) {
    //     for(int j = 0; j <= w + 1; ++j) {
    //         printf("%3d", mir[i][j]);
    //     }
    //     printf("\n");
    // }

    // Runing Simulation
    // number 1 ~ w
    for(int i = 1; i <= w; ++i) {
        int curR = d + 1, curC = i, dir = 0;
        curR += dr[dir];
        curC += dc[dir];
        while(mir[curR][curC] > 0) {
            if(mir[curR][curC] == 2) {
                dir ^= 1;
            }
            curR += dr[dir];
            curC += dc[dir];
        }
        printf("%d\n", -mir[curR][curC]);
    }
    // number w + 1 ~ w + d
    for(int i = d; i >= 1; --i) {
        int curR = i, curC = w + 1, dir = 3;
        curR += dr[dir];
        curC += dc[dir];
        while(mir[curR][curC] > 0) {
            if(mir[curR][curC] == 2) {
                dir ^= 1;
            }
            curR += dr[dir];
            curC += dc[dir];
        }
        printf("%d\n", -mir[curR][curC]);
    }
    // number w + d + 1 ~ w + d + 1 + w
    for(int i = w; i >= 1; --i) {
        int curR = 0, curC = i, dir = 2;
        curR += dr[dir];
        curC += dc[dir];
        while(mir[curR][curC] > 0) {
            if(mir[curR][curC] == 2) {
                dir ^= 1;
            }
            curR += dr[dir];
            curC += dc[dir];
        }
        printf("%d\n", -mir[curR][curC]);
    }
    // number 2w + d + 1 ~ 2w + 2d
    for(int i = 1; i <= d; ++i) {
        mir[i][0] = -(2 * w + d + i - 1);
        int curR = i, curC = 0, dir = 1;
        curR += dr[dir];
        curC += dc[dir];
        while(mir[curR][curC] > 0) {
            if(mir[curR][curC] == 2) {
                dir ^= 1;
            }
            curR += dr[dir];
            curC += dc[dir];
        }
        printf("%d\n", -mir[curR][curC]);
    }


    return 0;
}