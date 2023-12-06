#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
 
#define N 20
 
typedef struct {
    int16_t a, b;
} Bond;
 
int cmp(const void *a, const void *b) {
    Bond *ba = (Bond *) a;
    Bond *bb = (Bond *) b;
    if(ba->a != bb->b) return ba->a - bb->a;
    return ba->b - bb->b;
}
 
static inline int16_t max(int16_t a, int16_t b) {
    return (a > b) * a + (a <= b) * b;
}
 
int16_t find_cur_max(int16_t n, int16_t m, Bond bond[], int16_t cur_selection[]) {
    int16_t mx = 0;
    int16_t idx = 0;
    while(idx < m && bond[idx].a <= n) {
        if(bond[idx].b <= n) {
            mx = max(mx, abs(
                cur_selection[bond[idx].a] - cur_selection[bond[idx].b])
            );
        }
        idx++;
    }
    return mx;
}
 
void select_map(
    const int16_t n, const int16_t m, Bond bond[],
    const int16_t cur, int16_t *min_of_max, int16_t cur_selection[],
    int16_t best[], bool used[]
) {
    int16_t mx = find_cur_max(cur - 1, m, bond, cur_selection);
    if(cur == n + 1) {
        if(*min_of_max > mx) {
            *min_of_max = mx;
            for(int16_t i = 1; i <= n; ++i) {
                best[i] = cur_selection[i];
            }
        }
        return;
    }
 
    if(mx >= *min_of_max) {
        return;
    }
 
    for(int16_t i = 1; i <= n; ++i) if(!used[i]) {
        cur_selection[cur] = i;
        used[i] = true;
        select_map(n, m, bond, cur + 1, min_of_max, cur_selection, best, used);
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
 
    Bond bond[N * N] = {0};
    for(int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        bond[i].a = a;
        bond[i].b = b;
    }
    qsort(bond, m, sizeof(Bond), cmp);
 
    int16_t min_of_max = INT16_MAX;
    int16_t cur_selection[N] = {0}, best[N] = {0};
    bool used[N] = {0};
    select_map(n, m, bond, 1, &min_of_max, cur_selection, best, used);
 
    for(int16_t i = 1; i <= n; ++i) {
        printf("%d ", best[i]);
    }
    printf("\n");
}