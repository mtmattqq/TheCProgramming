#include <stdio.h>
#include <string.h>

#ifdef DEBUG
#define SIZE 105
#else
#define SIZE 10010
#endif
#define LEN 105

typedef struct info {
    char s[LEN];
    int r, c;
} Info;

void swap(Info *a, Info *b) {
    Info t = *a;
    *a = *b;
    *b = t;
}

int get_largest(Info *hp, int idx, int *heap_size) {
    int l = idx * 2;
    int r = idx * 2 + 1;
    int ret = idx;

    if(l <= *heap_size && strcmp(hp[l].s, hp[idx].s) > 0) {
        ret = l;
    }

    if(r <= *heap_size && strcmp(hp[r].s, hp[ret].s) > 0) {
        ret = r;
    }

    return ret;
}

void max_heapify(Info *hp, int idx, int *heap_size) {
    int largest = get_largest(hp, idx, heap_size);
    while(idx != largest) {
        swap(&(hp[idx]), &(hp[largest]));
        idx = largest;
        largest = get_largest(hp, idx, heap_size);
    }
}

Info pop(Info *hp, int *heap_size) {
    Info ret = hp[1];
    hp[1] = hp[*heap_size];
    (*heap_size)--;
    max_heapify(hp, 1, heap_size);
    return ret;
}

void push(Info *hp, Info new, int *heap_size) {
    (*heap_size)++;
    int idx = *heap_size;
    hp[idx] = new;
    while(idx > 1 && strcmp(hp[idx >> 1].s, hp[idx].s) < 0) {
        swap(&(hp[idx >> 1]), &(hp[idx]));
        idx >>= 1;
    }
}

int main(void) {
    int pq_size = 0;
    Info pq[SIZE] = {0};
    char tow[LEN][LEN][LEN] = {0};
    int top[LEN][LEN] = {0};

    int n, m;
    scanf("%d%d", &n, &m);
    for(int layer = 0; layer < m; ++layer) {
        for(int i = 0; i < n; ++i) {
            scanf("%s", &(tow[layer][i]));
        }
    }
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            Info new = {0};
            while(tow[top[i][j]][i][j] != '0') {
                new.s[top[i][j]] = tow[top[i][j]][i][j];
                top[i][j]++;
            }
            new.s[top[i][j]] = '\0';
            top[i][j]++;
            new.r = i;
            new.c = j;
            push(pq, new, &pq_size);
        }
    }

#ifdef DEBUG
    for(int i = 1; i <= pq_size; ++i) {
        printf("pq[i].s = %s\n", pq[i].s);
    }
#endif

    while(pq_size > 0) {
        Info now = pop(pq, &pq_size);
        printf("%s\n", now.s);

        int idx = 0;
        while(top[now.r][now.c] <= n && tow[top[now.r][now.c]][now.r][now.c] != '0') {
            now.s[idx] = tow[top[now.r][now.c]][now.r][now.c];
            top[now.r][now.c]++;
            idx++;
        }
        now.s[idx] = '\0';
        top[now.r][now.c]++;

        if(strlen(now.s) > 0) {
            push(pq, now, &pq_size);
        }
    }
    return 0;
}