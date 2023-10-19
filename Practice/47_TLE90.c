#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define SIZE 320000

typedef struct node{
    struct node *lch, *rch;
    int pri, sz, sum, num;
    char val;
} Node;

void new_node(
    Node **a, char val, int num,
    Node pool[SIZE], int *idx
) {
    pool[*idx].lch = pool[*idx].rch = NULL;
    pool[*idx].pri = rand();
    pool[*idx].sz = 1;
    pool[*idx].val = val;
    pool[*idx].sum = pool[*idx].num = num;
    *a = &(pool[*idx]);
    (*idx)++;
    return;
}

void pull(Node *a) {
    a -> sz = 1;
    a -> sum = a -> num;
    if(a -> lch) {
        a -> sz += a -> lch -> sz;
        a -> sum += a -> lch -> sum;
    }
    if(a -> rch) {
        a -> sz += a -> rch -> sz;
        a -> sum += a -> rch -> sum;
    }
}

int fs(Node *a) {
    return a != NULL ? a -> sz : 0;
}

int find_sum(Node *a) {
    return a != NULL ? a -> sum : 0;
}

Node *merge(Node *a, Node *b) {
    if(a == NULL || b == NULL) return a != NULL ? a : b;

    if(a -> pri > b ->pri) {
        a -> rch = merge(a -> rch, b);
        pull(a);
        return a;
    } else {
        b -> lch = merge(a, b -> lch);
        pull(b);
        return b;
    }
}

void splitCsz(Node *T, Node **a, Node **b, int p) {
    if(T == NULL) {
        *a = NULL;
        *b = NULL;
        return;
    }

    if(find_sum(T -> lch) + T -> num <= p) {
        *a = T;
        splitCsz(T -> rch, &((*a) -> rch), b, 
            p - find_sum(T -> lch) - T -> num);
        pull(*a);
    } else {
        *b = T;
        splitCsz(T -> lch, a, &((*b) -> lch), p);
        pull(*b);
    }
    return;
}

void split(Node *T, Node **a, Node **b, int k) {
    if(T == NULL) {
        *a = NULL;
        *b = NULL;
        return;
    }

    if(fs(T -> lch) < k) {
        *a = T;
        split(T -> rch, &((*a) -> rch), b, k - fs(T -> lch) - 1);
        pull(*a);
    } else {
        *b = T;
        split(T -> lch, a, &((*b) -> lch), k);
        pull(*b);
    }
    return;
}

void insert(
    Node **rt, char val, 
    int num, int p, 
    Node pool[SIZE], int *pool_idx
) {
    p--;
    Node *a, *b, *c, *d, *e;
    new_node(&a, val, num, pool, pool_idx);
    splitCsz(*rt, rt, &b, p);
    split(b, &b, &c, 1);
    int rt_sz = find_sum(*rt);

#ifdef DEBUG
    printf("%d\n", rt_sz);
#endif

    if(rt_sz == p) {
        a = merge(a, b);
        a = merge(a, c);
        *rt = merge(*rt, a);
    } else {
        p -= rt_sz;
        new_node(&d, b -> val, p, pool, pool_idx);
        new_node(&e, b -> val, b -> num - p, pool, pool_idx);
        d = merge(d, a);
        d = merge(d, e);
        d = merge(d, c);
        *rt = merge(*rt, d);
    }
    return;
}

void convert(char s[SIZE], int num[SIZE], Node *n, int sz) {
    static int idx = 0;
    if(!n) return;
    if(n -> lch) {
        convert(s, num, n -> lch, sz);
    }
    s[idx] = n -> val;
    num[idx] = n -> num;
    idx++;

    if(n -> rch) {
        convert(s, num, n -> rch, sz);
    }

    if(idx == sz) {
        idx = 0;
    }
}

int main(void) {
    srand(59);

    Node *pool;
    int pool_idx = 0;
    pool = calloc(SIZE * 2, sizeof(Node));
    Node *rt = NULL;

    char *s, *c;
    int *num, *num2;
    s = calloc(SIZE * 2, sizeof(char));
    c = calloc(SIZE, sizeof(char));
    num = calloc(SIZE * 2, sizeof(int));
    num2 = calloc(SIZE, sizeof(int));

    char op[20] = {0};
    char pos[10] = {0}, val[2] = {0};
    while(scanf("%s", op) != EOF) {
        if(strcmp("insert", op) == 0) {
            int num, p;
            scanf("%s%s%d", pos, val, &num);
            if(isdigit(pos[0])) {
                p = atoi(pos);
            } else if(strcmp("left", pos) == 0) {
                p = 1;
            } else { // right
                p = find_sum(rt) + 1;
            }
            insert(&rt, val[0], num, p, pool, &pool_idx);
        } else { // print
            int node_num = fs(rt);
            convert(s, num, rt, node_num);
            char pre = s[0];
            int len = 0, idx = 0, stack_idx = 0;
            for(int i = 0; i < node_num; ++i) {
                if(pre != s[i]) {
                    c[idx] = pre;
                    num2[idx] = len;
                    idx++;
                    len = 0;
                }

                pre = s[i];
                len += num[i];
            }

            c[idx] = pre;
            num2[idx] = len;
            idx++;
            len = 0;

            if(fs(rt) == 0) {
                printf("$\n");
                continue;
            }
            for(int i = 0; i < idx; ++i) {
                printf("%c %d ", c[i], num2[i]);
            }
            printf("$\n");
        }
    }

    free(pool);
    free(s);
    free(c);
    free(num);
    return 0;
}