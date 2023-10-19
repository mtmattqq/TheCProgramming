#include <stdio.h>

#ifdef DEBUG
#define SIZE 55
#else
#define SIZE 605
#endif

enum type{NONE, DOWN, LEFT, DIAG};

void fold_down(
    int bd[SIZE][SIZE], int k, 
    int *left, int *right, int *top, int *buttom
) {
    for(int i = 0; i < k; ++i) {
        for(int j = *left; j < *right; ++j) {
            bd[*top + 2 * k - i - 1][j] += bd[i + *top][j];
            bd[i + *top][j] = 0;
        }
    }
    *top += k;
}

void fold_left(
    int bd[SIZE][SIZE], int k, 
    int *left, int *right, int *top, int *buttom
) {
    for(int i = *top; i < *buttom; ++i) {
        for(int j = 0; j < k; ++j) {
            bd[i][*right - 2 * k + j] += bd[i][*right - j - 1];
            bd[i][*right - j - 1] = 0;
        }
    }
    *right -= k;
}

void fold_diag(
    int bd[SIZE][SIZE], int k, 
    int *left, int *right, int *top, int *buttom
) {
    k--;
    for(int i = 0; i < k; ++i) {
        for(int j = 0; j <= i; ++j) {
            bd[i + *top + 1][*right - k + j - 1] += bd[j + *top][*right - k + i];
            bd[j + *top][*right - k + i] = 0;
        }
    }
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

    int left = 0, right = c, top = 0, buttom = r;

    int type, k;
    while(scanf("%d%d", &type, &k) != EOF) {
        switch(type) {
          case LEFT :
            fold_left(bd, k, &left, &right, &top, &buttom);
            break;
          case DOWN :
            fold_down(bd, k, &left, &right, &top, &buttom);
            break;
          case DIAG :
            fold_diag(bd, k, &left, &right, &top, &buttom);
            break;
        }
    }

    for(int i = top; i < buttom; ++i) {
        for(int j = left; j < right; ++j) {
            printf("%d ", bd[i][j]);
        }
        printf("\n");
    }
}