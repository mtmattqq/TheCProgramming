#include <stdio.h>

void find_fill_pattern(int l, int m, int ty, int n, int r, int c) {
    if((r > l - m && c > l - m) || n == 0) {
        return;
    }
    
    printf("%d %d %d\n", ty, r, c);
    const static int nty[4][4] = {
        {1, 2, 1, 4},
        {1, 2, 3, 2},
        {3, 2, 3, 4},
        {1, 4, 3, 4}
    };
    
    const static int dx[4] = {-1, 1, 1, -1}, dy[4] = {-1, -1, 1, 1};
    for(int i = 0; i < 4; ++i) {
        find_fill_pattern(
            l, m, nty[ty - 1][i], n >> 1, 
            r + dx[i] * (n >> 1), c + dy[i] * (n >> 1)
        );
    }
    
    return;
}

int main(void) {
    int l, m;
    scanf("%d%d", &l, &m);
    find_fill_pattern(l, m, 1, l >> 1, l >> 1, l >> 1);
}