#include <stdio.h>
#include <stdbool.h>

bool find_m(
    int g[105][105], const int n, int ans[],
    const int m, int idx, int can[]
) {
    if(idx == m) {
        return true;
    }

    if(idx + n < m || n == 0) {
        return false;
    }

    int next_can[105] = {0};
    int next_n = 0;

    for(int i = 1; i < n; ++i) {
        if(g[can[i]][can[0]] == 0) {
            next_can[next_n] = can[i];
            next_n++;
        }
    }

    ans[idx] = can[0];
    return (
        find_m(g, next_n, ans, m, idx + 1, next_can) ||
        find_m(g, n - 1, ans, m, idx, can + 1)
    );
}

int main(void) {
    int n, m;
    int g[105][105] = {0};
    while(scanf("%d%d", &n, &m) != EOF) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &(g[i][j]));
            }
        }

        int ans[105] = {0}, can[105] = {0};
        for(int i = 0; i < n; ++i) {
            can[i] = i;
        }

        if(find_m(g, n, ans, m, 0, can)) {
            for(int i = 0; i < m; ++i) {
                printf("%d ", ans[i]);
            }
            printf("\n");
        } else {
            printf("no solution\n");
        }
    }
}