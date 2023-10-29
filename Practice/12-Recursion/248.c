#include <stdio.h>
#include <stdbool.h>

#define N 9
#define DIR 9

bool in(int x, int y, int mx, int my) {
    return x >= 0 && y >= 0 && x < mx && y < my;
}

bool check(int bd[N][N], int ans[N][N], int r, int c) {
    const static int dr[DIR] = {0, 1, 0, -1, 0, 1, 1, -1, -1};
    const static int dc[DIR] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
    int i = r - 1;
    int j = c - 1;
    int ct = 0;
    for(int k = 0; k < DIR; ++k) {
        int nr = i + dr[k], nc = j + dc[k];
        if(in(nr, nc, N, N)) {
            ct += ans[nr][nc];
        }
    }

    return ct == bd[i][j];
}

bool find_solution(int bd[N][N], int ans[N][N], int r, int c) {
    if(r == N) {
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N; ++j) {
                if(!check(bd, ans, i, j)) {
                    return false;
                }
            }
        }
        return true;
    }

    if(r >= 1 && c >= 2) {
        if(!check(bd, ans, r, c - 1)) {
            return false;
        }
    }

    int nr, nc;
    nr = r + (c == N - 1);
    nc = (c + 1) % N;

    ans[r][c] = 0;
    if(find_solution(bd, ans, nr, nc)) {
        return true;
    }
    ans[r][c] = 1;
    if(find_solution(bd, ans, nr, nc)) {
        return true;
    }
    return false;
}

int main(void) {
    int bd[N][N] = {0}, ans[N][N] = {0};
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            scanf("%d", &(bd[i][j]));
        }
    }

    if(find_solution(bd, ans, 0, 0)) {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                printf("%d%c", ans[i][j], " \n"[j == N - 1]);
            }
        }
    } else {
        printf("no solution\n");
    }
    return 0;
}