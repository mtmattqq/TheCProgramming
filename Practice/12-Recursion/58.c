#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return -(*(int*) a - *(int*) b);
}

// // stack overflow QQ
// int dfs(int **bd, int r, int c) {
//     if(bd[r][c] != 1) {
//         return 0;
//     }

//     bd[r][c] = 0;

//     int ret = 0;
//     const static int dr[4] = {0, 1, -1, 0}, dc[4] = {1, 0, 0, -1};
//     for(int i = 0; i < 4; ++i) {
//         ret += dfs(bd, r + dr[i], c + dc[i]);
//     }
//     return ret + 1;
// }

int qr[405 * 405], qc[405 * 405];

int in(int r, int c, int n, int m) {
    return r > 0 && c > 0 && r <= n && c <= m;
}

int bfs(int **bd, int r, int c, int n, int m) {
    if(bd[r][c] == 0) {
        return 0;
    }
    bd[r][c] = 0;

    int front = 0, rear = 0;
    qr[0] = r;
    qc[0] = c;
    int ret = 1;
    while(front <= rear) {
        int rnow = qr[front];
        int cnow = qc[front];

#ifdef DEBUG
        printf("%d %d\n", rnow, cnow);
#endif

        front++;

        const static int dr[4] = {0, 1, -1, 0}, dc[4] = {1, 0, 0, -1};
        for(int i = 0; i < 4; ++i) {
            if(
                in(rnow + dr[i], cnow + dc[i], n, m) && 
                bd[rnow + dr[i]][cnow + dc[i]] == 1
            ) {
                bd[rnow + dr[i]][cnow + dc[i]] = 0;
                rear++;
                qr[rear] = rnow + dr[i];
                qc[rear] = cnow + dc[i];
                ret++;
            }
        }
    }

    return ret;
}

int main(void) {

#ifdef DEBUG
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    int *a = calloc((n + 2) * (m + 2), sizeof(int));
    int **bd = calloc(n + 2, sizeof(int*));

    for(int i = 0; i <= n + 1; ++i) {
        bd[i] = a + (i * m);
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            scanf("%d", &(bd[i][j]));
        }
    }

    int idx = 0;
    int *ans = calloc(400 * 400, sizeof(int));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            // int tp = dfs(bd, i, j);
            int tp = bfs(bd, i, j, n, m);
            if(tp > 0) {
                ans[idx] = tp;
                idx++;
            }
        }
    }

    qsort(ans, idx, sizeof(int), cmp);

    for(int i = 0; i < idx; ++i) {
        printf("%d\n", ans[i]);
    }

    free(a);
    free(ans);
    return 0;
}