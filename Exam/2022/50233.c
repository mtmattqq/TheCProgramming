#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void max_heapify(int *a, int i, int heap_size) {
    int largest = get_largest(a, i, heap_size);
    while(largest != i) {
        int tp = a[i];
        a[i] = a[largest];
        a[largest] = tp;
        i = largest;
        largest = get_largest(a, largest, heap_size);
    }
}

void build_max_heap(int *a, int heap_size) {
    for(int i = heap_size; i >= 1; --i) {
        max_heapify(a, i, heap_size);
    }
}

int top_pop(int *a, int *heap_size) {
    if(*heap_size < 1) {
        exit(-1);
    }
    int mx = a[1];
    a[1] = a[*heap_size];
    (*heap_size)--;
    max_heapify(a, 1, *heap_size);
    return mx;
}

void insert(int *a, int v, int *heap_size) {
    (*heap_size)++;
    int i = *heap_size;
    a[i] = v;
    while(i > 1 && a[i >> 1] < a[i]) {
        int tp = a[i];
        a[i] = a[i >> 1];
        a[i >> 1] = tp;
        i >>= 1;
    }
}

int main(void) {
    int n, m;
    int *a = malloc(100010 * sizeof(int));
    for(int i = 0; i < 100010; ++i) {
        a[i] = 0;
    }

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i + 1);
    }

    build_max_heap(a, n);

    for(int i = 1; i <= n; ++i) {
        printf("%d%c", a[i], " \n"[i == n]);
    }

    scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
        int op;
        scanf("%d", &op);
        if(op == -1) {
            printf("%d ", top_pop(a, &n));
        } else {
            insert(a, op, &n);
        }
    }

    free(a);
}