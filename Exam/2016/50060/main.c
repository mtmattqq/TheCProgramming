#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <assert.h>

#define N 20

static inline int min(const int a, const int b) {
    return (a < b) * a + (a >= b) * b;
}

// fix only start from 0
void find_max_dis(
    const int n, const int u, 
    const int g[N][N], 
    int *min_dis, uint16_t visit, 
    const int cur_dis, const uint16_t finished
) {
    if(u == 0 && visit == finished) {
        *min_dis = min(*min_dis, cur_dis);
        return;
    }

    if(cur_dis > *min_dis || (u == 0 && !(visit == finished) && cur_dis != 0)) {
        return;
    }

    for(int i = 0; i < n; ++i) {
        if(i != u && (visit & (1 << i)) == 0) {
            find_max_dis(
                n, i, g, min_dis, visit | (1 << i), 
                cur_dis + g[u][i], finished
            );
        }
    }
    return;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int g[N][N] = {0};
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &(g[i][j]));
        }
    }

    int min_dis = INT_MAX;
    uint16_t finished = (1U << n) - 1;
    find_max_dis(n, 0, g, &min_dis, 0, 0, finished);
    printf("%d\n", min_dis);
}