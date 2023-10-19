#include <stdio.h>
#include <stdbool.h>

#define DIRECTIONS 4

int main(void) {
    int r, c;
    scanf("%d%d", &r, &c);

    int bd[105][105] = {0};
    
    for(int i = 1; i <= r; ++i) {
        for(int j = 1; j <= c; ++j) {
            scanf("%d", &(bd[i][j]));
        }
    }

    const int dr[DIRECTIONS] = {0, 1, 0, -1};
    const int dc[DIRECTIONS] = {1, 0, -1, 0};

    for(int i = 1; i <= r; ++i) {
        for(int j = 1; j <= c; ++j) {
            bool isv = true;
            for(int k = 0; k < DIRECTIONS; ++k) {
                isv = isv & (bd[i][j] > bd[i + dr[k]][j + dc[k]]);
            }

            if(isv) {
                printf("%d\n", bd[i][j]);
            }
        }
    }
    
    return 0;
}