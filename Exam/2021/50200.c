#include <stdio.h>
#include <stdbool.h>

#ifdef DEBUG
#define SIZE 55
#else
#define SIZE 505
#endif
#define DIR 4

enum type{STONE, QUEEN, BISHOP, ROOK};

bool in(int r, int c, int i, int j) {
    return (i >= 0 && i < r && j >= 0 && j < c);
}

void attack(
    int bd[SIZE][SIZE], 
    int r, int c, int h, int w,
    int dr, int dc
) {
    int row = r + dr;
    int col = c + dc;
    while (in(h, w, row, col) && bd[row][col] == 0) {
        bd[row][col] = 1;
        row += dr;
        col += dc;
    }
}

void bishop(int bd[SIZE][SIZE], int r, int c, int h, int w) {
    int dr[DIR] = {1, 1, -1, -1}, dc[DIR] = {1, -1, 1, -1};
    for(int i = 0; i < DIR; ++i) {
        attack(bd, r, c, h, w, dr[i], dc[i]);
    }
    bd[r][c] = 1;
}

void rook(int bd[SIZE][SIZE], int r, int c, int h, int w) {
    int dr[DIR] = {0, 1, 0, -1}, dc[DIR] = {1, 0, -1, 0};
    for(int i = 0; i < DIR; ++i) {
        attack(bd, r, c, h, w, dr[i], dc[i]);
    }
    bd[r][c] = 1;
}

void queen(int bd[SIZE][SIZE], int r, int c, int h, int w) {
    bishop(bd, r, c, h, w);
    rook(bd, r, c, h, w);
}

int main(void) {
    int h, w;
    scanf("%d%d", &h, &w);
    int bd[SIZE][SIZE] = {0};

    int type, r, c;
    while(scanf("%d%d%d", &type, &c, &r) != EOF) {
        switch(type) {
          case STONE :
            bd[r][c] = 1;
            break;
          case QUEEN :
            queen(bd, r, c, h, w);
            break;
          case BISHOP :
            bishop(bd, r, c, h, w);
            break;
          case ROOK :
            rook(bd, r, c, h, w);
            break;
        }
    }

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            printf("%d ", bd[i][j]);
        }
        printf("\n");
    }

    return 0;
}