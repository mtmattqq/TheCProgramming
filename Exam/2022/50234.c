#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 400010

int bd[110][110][110] = {0};
int top[110][110] = {0};

void swap(int *a, int *b) {
    int tp = *a;
    *a = *b;
    *b = tp;
    return;
}

int get_largest(int *a, int i, int heap_size) {
    int l = i * 2;
    int r = i * 2 + 1;
    int largest = i;
    if(l <= heap_size && a[l] > a[i]) {
        largest = l;
    }
    if(r <= heap_size && a[r] > a[largest]) {
        largest = r;
    }
    return largest;
}

void max_heapify(int *a, int *r, int *c, int i, int heap_size) {
    int largest = get_largest(a, i, heap_size);
    while(largest != i) {
        swap(&(a[i]), &(a[largest]));
        swap(&(r[i]), &(r[largest]));
        swap(&(c[i]), &(c[largest]));
        i = largest;
        largest = get_largest(a, largest, heap_size);
    }
}

void pop(int *a, int *r, int *c, int *heap_size) {
    a[1] = a[*heap_size];
    r[1] = r[*heap_size];
    c[1] = c[*heap_size];
    (*heap_size)--;

#ifdef DEBUG
    printf("%d\n", *heap_size);
#endif

    max_heapify(a, r, c, 1, *heap_size);
}

void insert(int *a, int *r, int *c, int v, int rr, int cc, int *heap_size) {
    (*heap_size)++;
    int i = *heap_size;
    a[i] = v;
    r[i] = rr;
    c[i] = cc;
    while(i > 1 && a[i >> 1] < a[i]) {
        swap(&(a[i]), &(a[i >> 1]));
        swap(&(r[i]), &(r[i >> 1]));
        swap(&(c[i]), &(c[i >> 1]));
        i >>= 1;
    }
}

int main(void) {
    int n, heap_size = 0, idx = 0;
    scanf("%d", &n);
    int sz = n * (n + 1) * (2 * n + 1) / 6 + 10;
    int *a = calloc(sz, sizeof(int));
    int *r = calloc(sz, sizeof(int));
    int *c = calloc(sz, sizeof(int));
    int *ans = calloc(sz, sizeof(int));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            for(int k = 0; k <= i; ++k) {
                scanf("%d", &(bd[i][j][k]));
                if(j == i || k == i) {
                    insert(a, r, c, bd[i][j][k], j, k, &heap_size);
                }
                top[j][k] = j > k  ?  j  :  k;
            }
        }
    }

#ifdef DEBUG
    for(int i = 1; i <= heap_size; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
#endif

    while(heap_size > 0) {
        int val = a[1];
        int topr = r[1];
        int topc = c[1];
        pop(a, r, c, &heap_size);

        ans[idx++] = val;
        top[topr][topc]++;
        if(top[topr][topc] < n) {
            insert(a, r, c, bd[top[topr][topc]][topr][topc], topr, topc, &heap_size);
        }

#ifdef DEBUG
        for(int i = 1; i <= heap_size; ++i) {
            printf("%d ", a[i]);
        }
        printf("\n");
#endif
    }

    for(int i = 0; i < idx; ++i) {
        printf("%d%c", ans[i], " \n"[i == idx - 1]);
    }

    free(a);
    free(r);
    free(c);
    free(ans);
    return 0;
}