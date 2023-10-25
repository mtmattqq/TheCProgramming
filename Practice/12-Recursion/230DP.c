#include <stdio.h>
#include <stdlib.h>

#define MXN 10010

int max(int a, int b) {
    return (a > b) * a + (a <= b) * b;
}

int main(void) {
    int n, W;
    scanf("%d%d", &n, &W);

    int *a = calloc(10010 * 2, sizeof(int));
    int *dp[2] = {a, a + MXN};

    int w[30] = {0}, v[30] = {0};
    for(int i = 1; i <= n; ++i) {
        scanf("%d%d", w + i, v + i);
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= W; ++j) {
            if(j < w[i]) {
                dp[i & 1][j] = dp[i & 1 ^ 1][j];
            } else {
                dp[i & 1][j] = max(dp[i & 1 ^ 1][j], dp[i & 1 ^ 1][j - w[i]] + v[i]);
            }
        }
    }

    printf("%d\n", dp[n & 1][W]);

    return 0;
}