#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void find_all(
    int a[], int cur, int n, int s,
    int sum[], int ct[], int *idx
) {
    if(cur == n) {
        for(int i = 0; i < *idx; ++i) {
            if(sum[i] == s) {
                ct[i]++;
                return;
            }
        }

        sum[*idx] = s;
        ct[*idx] = 1;
        (*idx)++;
        return;
    }

    find_all(a, cur + 1, n, s + a[cur], sum, ct, idx);
    find_all(a, cur + 1, n, s, sum, ct, idx);

    return;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int a[20] = {0};
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    int *sum = calloc(1 << 16 + 10, sizeof(int));
    int *ct = calloc(1 << 16 + 10, sizeof(int));
    int idx = 0;
    find_all(a, 0, n, 0, sum, ct, &idx);

    int k;
    while(scanf("%d", &k) != EOF) {
        int is_find = false;
        for(int i = 0; i < idx; ++i) {
            if(k == sum[i]) {
                printf("%d\n", ct[i]);
                is_find = true;
                break;
            }
        }

        if(!is_find) {
            printf("0\n");
        }
    }
}