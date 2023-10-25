#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define SIZE 320000

typedef struct node{
    struct node *lch, *rch, *par;
    int sz, sum, num, col;
    char val;
} Node;

void new_node(
    Node **a, char val, int num,
    Node pool[SIZE], int *idx
) {
    pool[*idx].lch = pool[*idx].rch = 
        pool[*idx].par = NULL;
    pool[*idx].col = 1;
    pool[*idx].sz = 1;
    pool[*idx].val = val;
    pool[*idx].sum = pool[*idx].num = num;
    *a = &(pool[*idx]);
    (*idx)++;
    return;
}

int fs(Node *a) {
    return a != NULL ? a -> sz : 0;
}

int find_sum(Node *a) {
    return a != NULL ? a -> sum : 0;
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

void insert_node(Node *tree, Node *tp, int p) {
    ;
}

Node *search(Node *n, int p) {
    ;
}

void insert(
    Node **rt, char val, 
    int num, int p, 
    Node pool[SIZE], int *pool_idx
) {
    p--;
    Node *new, *cur;
    new_node(&new, val, num, pool, pool_idx);
    cur = search(*rt, p);
    insert_node(*rt, new, p);


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