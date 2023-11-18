#include <stdio.h>

void print(int v[], int l, int r) {
    for(int i = l; i < r; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void merge_sort(int v[], int l, int r, int tp[]) {
    print(v, l, r);
    if(r - l == 1) {
        return;
    }

    int mid = l + r >> 1;

#ifdef DEBUG
    printf("l = %d, mid = %d, r = %d\n", l, mid, r);
#endif

    merge_sort(v, l, mid, tp);
    merge_sort(v, mid, r, tp);

    int tp_idx = 0;
    int left_idx = l, right_idx = mid;
    while(left_idx < mid && right_idx < r) {
        if(v[left_idx] < v[right_idx]) {
            tp[tp_idx++] = v[left_idx++];
        } else {
            tp[tp_idx++] = v[right_idx++];
        }
    }

    while(left_idx < mid) {
        tp[tp_idx++] = v[left_idx++];
    }

    while(right_idx < r) {
        tp[tp_idx++] = v[right_idx++];
    }

    for(int i = l; i < r; ++i) {
        v[i] = tp[i - l];
    }

    print(v, l, r);
    return;
}

int main(void) {
    int n = 0;
    int v[100010] = {0}, tp[100010] = {0};
    while(scanf("%d", v + n) == 1) {
        n++;
    }

    merge_sort(v, 0, n, tp);
    return 0;
}