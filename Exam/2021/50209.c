#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool in(int r, int c, int cofr[3]) {
    return (r >= 0 && c >= 0 && r < 3 && c < cofr[r]);
}

int main(void) {
    int cofr[3] = {10, 9, 7};
    char key_board[3][30] = {
        "qwertyuiop",
        "asdfghjkl",
        "zxcvbnm"
    };

    char ori[2] = {0};
    scanf("%s", ori);
    printf("%s\n", ori);

    const int dr[] = {0, -1, -1, 0, 1, 1};
    const int dc[] = {1, 1, 0, -1, -1, 0};

    int r, c;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < cofr[i]; ++j) {
            if(ori[0] == key_board[i][j]) {
                r = i;
                c = j;
            }
        }
    }

    int m;
    while(scanf("%d", &m) == 1) {
        
        int nr = r + dr[m];
        int nc = c + dc[m];
        if(in(nr, nc, cofr)) {
            r = nr;
            c = nc;
            printf("%c\n", key_board[r][c]);
        }
    }

    return 0;
}