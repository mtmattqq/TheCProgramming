#include <stdio.h>
#include <stdlib.h>

#define MXN 10010

int max(int a, int b) {
    return (a > b) * a + (a <= b) * b;
}

int find_max(int n, int W, int w[], int v[]) {
    if(n == 0 || W < 0) {
        return 0;
    }

    int ret = 0;
    if(W >= w[n]) {
        ret = max(ret, find_max(n - 1, W - w[n], w, v) + v[n]);
    }
    ret = max(ret, find_max(n - 1, W, w, v));

    return ret;
}

int main(void) {
    int n, W;
    scanf("%d%d", &n, &W);

    int w[30] = {0}, v[30] = {0};
    for(int i = 1; i <= n; ++i) {
        scanf("%d%d", w + i, v + i);
    }

    printf("%d\n", find_max(n, W, w, v));

    return 0;
}