#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define NK 25

int cmp(const void *a, const void *b) {
    return *(uint64_t *) b - *(uint64_t *) a;
}

uint64_t find_min(
    const uint64_t a[], uint64_t sub[], const int cur, 
    const int n, const int k, uint64_t *min,
    const uint64_t cur_cost
) {
    if(cur == n) {
        return cur_cost;
    }

    if(cur_cost > *min) {
        return *min;
    }

    bool find_empty_set = false;
    for(int idx = 0; idx < k; ++idx) {
        uint64_t difference = (2 * sub[idx] + a[cur]) * a[cur];
        if(cur_cost + difference > *min) {
            continue;
        }

        if(find_empty_set) {
            break;
        }

        if(sub[idx] == 0) {
            find_empty_set = true;
        }
        sub[idx] += a[cur];
        uint64_t min_cur = find_min(a, sub, cur + 1, n, k, min, cur_cost + difference);
        *min = (*min < min_cur) ? (*min) : min_cur;
        sub[idx] -= a[cur];
    }
    return *min;
}

int main(void) {
    int n, k;
    scanf("%d%d", &n, &k);

    uint64_t a[NK] = {0};
    uint64_t sub[NK] = {0};
    for(int i = 0; i < n; ++i) {
        scanf("%llu", a + i);
    }

    uint64_t min = 0;
    for(int i = 0; i < n; ++i) {
        sub[i % k] += a[i];
    }

    for(int i = 0; i < k; ++i) {
        min += (uint64_t)(sub[i]) * sub[i];
    }

    qsort(a, n, sizeof(uint64_t), &cmp);

    memset(sub, 0, sizeof(uint64_t) * NK);

    printf("%llu", find_min(a, sub, 0, n, k, &min, 0));

    return 0;
}