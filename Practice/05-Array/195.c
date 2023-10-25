#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

int check(int (*)[3]);

int main(void) {
    int n;
    scanf("%d", &n);

    int bd[SIZE][SIZE] = {0}, cur = 1;
    for(int i = 0; i < n; ++i) {
        int r, c;
        scanf("%d%d", &r, &c);
        if(r >= 0 && r < 3 && c >= 0 && c < 3 && !bd[r][c]) {
            bd[r][c] = cur;
            cur ^= 3;
        }

#ifdef DEBUG
        for(int a = 0; a < SIZE; ++a) {
            for(int b = 0; b < SIZE; ++b) {
                printf("%d", bd[a][b]);
            }
            printf("\n");
        }
#endif

        int state = check(bd);
        switch (state) {
          case 1 :
            printf("Black wins.\n");
            return 0;
            break;
          case 2 :
            printf("White wins.\n");
            return 0;
            break;
        }
    }

    printf("There is a draw.\n");
}

int check(int bd[3][3]) {
    // o-- -o- --o
    // o-- -o- --o
    // o-- -o- --o
    for(int i = 0; i < SIZE; ++i) {
        if(bd[0][i] > 0 && bd[0][i] == bd[1][i] && bd[1][i] == bd[2][i]) {
            return bd[0][i];
        }
    }

    // ooo --- ---
    // --- ooo ---
    // --- --- ooo
    for(int i = 0; i < SIZE; ++i) {
        if(bd[i][0] > 0 && bd[i][0] == bd[i][1] && bd[i][1] == bd[i][2]) {
            return bd[i][0];
        }
    }

    // o--
    // -o-
    // --o
    if(bd[0][0] > 0 && bd[0][0] == bd[1][1] && bd[1][1] == bd[2][2]) {
        return bd[0][0];
    }

    // --o
    // -o-
    // o--
    if(bd[1][1] > 0 && bd[0][2] == bd[1][1] && bd[1][1] == bd[2][0]) {
        return bd[1][1];
    }

    return 0;
}