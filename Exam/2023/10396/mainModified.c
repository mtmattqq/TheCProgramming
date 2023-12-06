#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
 
#define N 20
 
static inline int max(int a, int b) {
    return (a > b) * a + (a <= b) * b;
}
 
int find_cur_max(int n, bool g[N][N], int cur_selection[]) {
    int mx = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(g[i][j]) {
                mx = max(
                    mx, 
                    abs(cur_selection[i] - cur_selection[j]));
            }
        }
    }
    return mx;
}
 
void select_map(
    int n, bool g[N][N],
    int cur, int *min_of_max, int cur_selection[],
    int best[], bool used[]
) {
    if(cur == n + 1) {
        int mx = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(g[i][j]) {
                    mx = max(
                        mx, 
                        abs(cur_selection[i] - cur_selection[j]));
                }
            }
        }

        if(*min_of_max > mx) {
            *min_of_max = mx;
            for(int i = 1; i <= n; ++i) {
                best[i] = cur_selection[i];
            }
        }
        return;
    }
    
    int mx = 0;
    for(int j = 1; j <= n; ++j) {
        if(g[cur - 1][j]) {
            mx = max(
                mx, 
                abs(cur_selection[cur - 1] - cur_selection[j]));
        }
    }
    
    if(mx >= *min_of_max) {
        return;
    }
 
    for(int i = 1; i <= n; ++i) if(!used[i]) {
        cur_selection[cur] = i;
        used[i] = true;
        select_map(n, g, cur + 1, min_of_max, cur_selection, best, used);
        used[i] = false;
    }
}
 
int main() {

#ifdef TEST
    freopen("bigInput", "r", stdin);
    freopen("output", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    bool g[N][N] = {0};
    for(int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a][b] = g[b][a] = true;
    }
 
    int min_of_max = INT32_MAX;
    int cur_selection[N] = {0}, best[N] = {0};
    bool used[N] = {0};
    select_map(n, g, 1, &min_of_max, cur_selection, best, used);
 
    for(int i = 1; i <= n; ++i) {
        printf("%d ", best[i]);
    }
    printf("\n");
}