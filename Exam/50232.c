#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, k;
    scanf("%d%d", &n, &k);

    int *m, *t;
    m = malloc(n * n * sizeof(int));
    t = malloc(k * k * sizeof(int));

    for(int i = 0; i < n * n; ++i){
        scanf("%d", &(m[i]));
    }

    for(int i = 0; i < k * k; ++i) {
        scanf("%d", &(t[i]));
    }

    int len = n - k + 1;
    for(int i = 0; i < len * len; ++i) {
        int sum = 0;
        for(int j = 0; j < k; ++j) {
            for(int l = 0; l < k; ++l) {
                sum += m[(i / len + j) * n + i % len + l] * t[j * k + l];
            }
        }
        printf("%d%c", sum, " \n"[i % len == len - 1]);
    }

    free(m);
    free(t);
    return 0;
}