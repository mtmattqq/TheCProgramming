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

void swap(int *a, int *b) {
    int tp = *a;
    *a = *b;
    *b = tp;
    return;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int a[20] = {0};
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    int *sum = (int *) calloc(1 << 16 + 10, sizeof(int));
    int *ct = (int *) calloc(1 << 16 + 10, sizeof(int));
    int idx = 0;
    find_all(a, 0, n, 0, sum, ct, &idx);

    for(int i = 0; i < idx; ++i) {
        for(int j = 0; j < idx - 1; ++j) {
            if(sum[j] > sum[j + 1]) {
                swap(&(sum[j]), &(sum[j + 1]));
                swap(&(ct[j]), &(ct[j + 1]));
            }
        }
    }

#ifdef DEBUG
    for(int i = 0; i < idx; ++i) {
        printf("%d %d\n", sum[i], ct[i]);
    }
#endif

    int k;
    while(scanf("%d", &k) != EOF) {
        int l = 0, r = idx;
        while(r - l > 1) {
            int mid = (l + r) >> 1;
            if(sum[mid] < k) {
                l = mid;
            } else {
                r = mid;
            }
        }

        if(sum[r] == k) {
            printf("%d\n", ct[r]);
        } else {
            printf("0\n");
        }
    }
    return 0;
}