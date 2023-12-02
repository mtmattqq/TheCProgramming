#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define N 80

static inline int max_int(int a, int b) {
    return (a > b) * a + (a <= b) * b;
}

void find_max_donation(
    int donate[], uint64_t g[], 
    int n, int cur, int sum, uint64_t selected, int *max
) {
    if(n == cur) {
        *max = max_int(*max, sum);
        return;
    }

    int remain = 0;
    for(int i = cur; i < n; ++i) {
        remain += donate[i];
    }

    if(remain + sum < *max) {
        return;
    }

    if(!(selected & (1ULL << cur))) {
        find_max_donation(
            donate, g, n, 
            cur + 1, sum + donate[cur], 
            selected | g[cur], max
        );
    }

    find_max_donation(
        donate, g, n, 
        cur + 1, sum, 
        selected, max
    );
}

int main(void) {
    int n;
    scanf("%d", &n);

    int donate[N] = {0};
    for(int i = 0; i < n; ++i) {
        scanf("%d", donate + i);
    }

    uint64_t g[N] = {0};
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int hate;
            scanf("%d", &hate);
            g[i] |= ((uint64_t) hate) << j;
        }
    }

    int max = 0;
    find_max_donation(donate, g, n, 0, 0, 0, &max);
    printf("%d\n", max);
    return 0;
}