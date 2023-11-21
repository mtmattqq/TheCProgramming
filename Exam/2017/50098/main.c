#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>

#define N 105

bool find_max_set(
    uint64_t set[], uint64_t now, 
    int choosed[],
    int n, int k, int cur, int idx
) {
    if(idx == k) {
        for(int i = 0; i < k; ++i) {
            printf("%d\n", choosed[i]);
        }
        return true;
    }

    if(n - cur + idx < k) {
        return false;
    }

    if((now & set[cur]) == 0) {
        choosed[idx] = cur;
        if(find_max_set(
            set, now | set[cur], 
            choosed, 
            n, k, 
            cur + 1, idx + 1
        )) {
            return true;
        };
    }

    return find_max_set(
        set, now, 
        choosed,
        n, k, 
        cur + 1, idx
    );
}

int main(void) {
    uint64_t set[N] = {0}, choosed[N] = {0};
    int n, k;
    scanf("%d%d", &n, &k);

    for(int i = 0; i < n; ++i) {
        int m;
        scanf("%d", &m);
        for(int j = 0; j < m; ++j) {
            uint64_t k;
            scanf("%llu", &k);
            set[i] |= (1ULL << k);
        }
    }

    find_max_set(
        set, 0ULL, 
        choosed, 
        n, k, 0, 0
    );
    return 0;
}