#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int cur;
    int s;
} Node;

void push(Node stack[], int *sz, Node val) {
    (*sz)++;
    stack[*sz] = val;
}

Node pop(Node stack[], int *sz) {
    Node ret = stack[*sz];
    (*sz)--;
    return ret;
}

void find_all(
    int a[], int n,
    int sum[], int ct[], int *idx
) {
    int sz = -1;
    Node stack[100] = {0};
    Node start;
    start.cur = 0;
    start.s = 0;
    push(stack, &sz, start);
    while(sz >= 0) {
        Node now = pop(stack, &sz);
        if(now.cur == n) {
            bool is_find = false;
            for(int i = 0; i < *idx; ++i) {
                if(sum[i] == now.s) {
                    ct[i]++;
                    is_find = true;
                    break;
                }
            }

            if(is_find) {
                continue;
            }

            sum[*idx] = now.s;
            ct[*idx] = 1;
            (*idx)++;
            continue;
        }

        Node choose_this_one, dont_choose_this;
        choose_this_one.cur = now.cur + 1;
        dont_choose_this.cur = now.cur + 1;

        choose_this_one.s = now.s + a[now.cur];
        dont_choose_this.s = now.s;
        push(stack, &sz, choose_this_one);
        push(stack, &sz, dont_choose_this);
    }
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
    find_all(a, n, sum, ct, &idx);

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
    return 0;
}