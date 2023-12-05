#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
 
#define N 80
 
static inline int max(int a, int b) {
    return (a > b) * a + (a <= b) * b;
}
 
typedef struct {
    int a, b;
} Bond;
 
int cmp(const void *a, const void *b) {
    Bond *ba = (Bond *) a;
    Bond *bb = (Bond *) b;
    if(ba->a != bb->b) return ba->a - bb->a;
    return ba->b - bb->b;
}
 
void set(uint64_t *s, int p) {
    (*s) |= (1ULL << p);
}
 
void reset(uint64_t *s, int p) {
    (*s) = ~(*s);
    (*s) |= (1ULL << p);
    (*s) = ~(*s);
}
 
void choose_bonds(
    Bond bond[], int n, int m,
    int cur, int *mx,
    Bond choosed[], Bond best[],
    int choosed_num,
    uint64_t g[]
) {
    if(m == cur) {
        if(*mx < choosed_num) {
            *mx = choosed_num;
            for(int i = 0; i < choosed_num; ++i) {
                best[i] = choosed[i];
            }
        }
        return;
    }
 
    if((m - cur) + choosed_num < *mx) {
        return;
    }
 
    Bond now = bond[cur];
    if((g[now.a] & g[now.b]) == 0) {
        // can choose this one
        choosed[choosed_num] = now;
        set(&(g[now.a]), now.b);
        set(&(g[now.b]), now.a);
        choose_bonds(bond, n, m, cur + 1, mx, choosed, best, choosed_num + 1, g);
        reset(&(g[now.a]), now.b);
        reset(&(g[now.b]), now.a);
    }
    choose_bonds(bond, n, m, cur + 1, mx, choosed, best, choosed_num, g);
}
 
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
 
    Bond bond[N] = {0};
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &(bond[i].a), &(bond[i].b));
    }
 
    qsort(bond, m, sizeof(Bond), cmp);
 
    int mx = 0;
    Bond choosed[N] = {0}, best[N] = {0};
    uint64_t g[N] = {0};
    choose_bonds(bond, n, m, 0, &mx, choosed, best, 0, g);
 
    for(int i = 0; i < mx; ++i) {
        printf("%d %d\n", best[i].a, best[i].b);
    }
}