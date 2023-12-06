#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
 
#define N 20
 
typedef struct {
    int a, b;
} Bond;
 
int cmp(const void *a, const void *b) {
    Bond *ba = (Bond *) a;
    Bond *bb = (Bond *) b;
    if(ba->a != bb->b) return ba->a - bb->a;
    return ba->b - bb->b;
}
 
static inline int max(int a, int b) {
    return (a > b) * a + (a <= b) * b;
}
 
// int find_cur_max(int n, int m, Bond bond[], int cur_selection[]) {
//     int mx = 0;
//     int idx = 0;
//     while(idx < m && bond[idx].a <= n) {
//         if(bond[idx].b <= n) {
//             mx = max(mx, abs(
//                 cur_selection[bond[idx].a] - cur_selection[bond[idx].b])
//             );
//         }
//         idx++;
//     }
//     return mx;
// }
 
void select_map(
    int n, int m, Bond bond[],
    int cur, int *min_of_max, int cur_selection[],
    int best[], bool used[]
) {
    int mx = 0;
    int idx = 0;
    while(idx < m && bond[idx].a <= cur - 1) {
        if(bond[idx].b <= cur - 1) {
            mx = max(mx, abs(
                cur_selection[bond[idx].a] - cur_selection[bond[idx].b])
            );
        }
        idx++;
    }

    if(cur == n + 1) {
        if(*min_of_max > mx) {
            *min_of_max = mx;
            for(int i = 1; i <= n; ++i) {
                best[i] = cur_selection[i];
            }
        }
        return;
    }

    if(mx >= *min_of_max) {
        return;
    }
 
    for(int i = 1; i <= n; ++i) if(!used[i]) {
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
        scanf("%d%d", &(bond[i].a), &(bond[i].b));
    }
    qsort(bond, m, sizeof(Bond), cmp);
 
    int min_of_max = INT32_MAX;
    int cur_selection[N] = {0}, best[N] = {0};
    bool used[N] = {0};
    select_map(n, m, bond, 1, &min_of_max, cur_selection, best, used);
 
    for(int i = 1; i <= n; ++i) {
        printf("%d ", best[i]);
    }
    printf("\n");
}