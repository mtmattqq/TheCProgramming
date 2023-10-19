#include <stdio.h>
#include <stdbool.h>

#define CIRCLE 3

typedef struct cir {
    int x, y, r;
} Cir;

void solve();
long long sq(int);
bool find(int*, int *, int, int, int);

int main(void) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        solve();
    }
}

void solve() {
    Cir cs[CIRCLE];
    for(int i = 0; i < CIRCLE; ++i) {
        scanf("%d%d%d", &(cs[i].x), &(cs[i].y), &(cs[i].r));
    }

    int ans = 0;
    int usedX[10000], usedY[10000], idx = 0;
    for(int i = 0; i < CIRCLE; ++i) {
        for(int j = cs[i].x - cs[i].r; j <= cs[i].x + cs[i].r; ++j) {
            for(int k = cs[i].y - cs[i].r; k <= cs[i].y + cs[i].r; ++k) {
                if(find(usedX, usedY, idx, j, k)) {
                    continue;
                } else {
                    usedX[idx] = j;
                    usedY[idx] = k;
                    idx++;
                }

                int ct = 0;
                for(int l = 0; l < CIRCLE; ++l) {
                    // printf("\n%d %d\n", j, k);
                    // printf("\n%lld %lld \n", sq(cs[l].x - j) + sq(cs[l].y - k), sq(cs[l].r));
                    if(sq(cs[l].x - j) + sq(cs[l].y - k) <= sq(cs[l].r)) {
                        ct++;
                    }
                }

                if(ct % 2 == 1) {
                    ans++;
                }
            }
        }
    }

    printf("%d\n", ans);
}

long long sq(int a) {
    return (long long)a * a;
}

bool find(int *a, int *b, int n, int x, int y) {
    for(int i = 0; i < n; ++i) {
        if(a[i] == x && b[i] == y) {
            return true;
        }
    }
    return false;
}