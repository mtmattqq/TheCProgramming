#include <stdio.h>
#include <stdbool.h>

#define N 25

bool dfs(int n, int c, int now, bool g[N][N], int color[N]) {
    for(int i = 1; i <= c; ++i) {
        bool isv = true;
        for(int j = 0; j < n; ++j) {
            if(now != j && g[now][j] && i == color[j]) {
                isv = false;
                break;
            }
        }

        if(isv) {
            color[now] = i;
        } else {
            continue;
        }

        for(int i = 0; i < n; ++i) {
            if(now != i && g[now][i]) {
                if(color[i] == 0 && !dfs(n, c, i, g, color)) {
                    isv = false;
                }
            }
        }

        if(!isv) {
            color[now] = 0;
        }
    }

    if(color[now] == 0) {
        return false;
    }
    return true;
}

int main(void) {
    int n, c, p;
    scanf("%d%d%d", &n, &c, &p);

    bool g[N][N] = {0};
    for(int i = 0; i < p; ++i) {
        int f, t;
        scanf("%d%d", &f, &t);
        g[f][t] = g[t][f] = true;
    }

    int color[N] = {0};
    bool isv = true;
    for(int i = 0; i < n; ++i) {
        if(color[i] == 0 && !dfs(n, c, i, g, color)) {
            isv = false;
        }
    }

    if(isv) {
        for(int i = 0; i < n; ++i) {
            printf("%d\n", color[i]);
        }
    } else {
        printf("no solution.\n");
    }

    return 0;
}