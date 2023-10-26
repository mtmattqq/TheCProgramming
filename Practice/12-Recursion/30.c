#include <stdio.h>

#define N 15

int find_way(int mp[N][N], int r, int c) {
    if(mp[r][c] == 0) {
        return 0;
    }

    if(r == 1 && c == 1) {
        return 1;
    }

    if(r == 1) {
        return find_way(mp, r, c - 1);
    }

    if(c == 1) {
        return find_way(mp, r - 1, c);
    }

    return find_way(mp, r, c - 1) + find_way(mp, r - 1, c);
}

int main(void) {
    int r, c;
    scanf("%d%d", &r, &c);
    int mp[N][N] = {0};

    for(int i = r; i >= 1; --i) {
        for(int j = 1; j <= c; ++j) {
            scanf("%d", &(mp[i][j]));
        }
    }

#ifdef DEBUG
    for(int i = 1; i <= r; ++i) {
        for(int j = 1; j <= c; ++j) {
            printf("%d ", mp[i][j]);
        }
        printf("\n");
    }
#endif

    printf("%d", find_way(mp, r, c));
    return 0;
}