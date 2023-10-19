#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define SIZE 200000

typedef struct node{
    struct node *lch, *rch;
    int pri, sz;
    char val;
} Node;

void new_node(
    Node **a, char val, 
    Node pool[SIZE], int *idx
) {
    pool[*idx].lch = pool[*idx].rch = NULL;
    pool[*idx].pri = rand();
    pool[*idx].sz = 1;
    pool[*idx].val = val;
    *a = &(pool[*idx]);
    (*idx)++;
    return;
}

void pull(Node *a) {
    a -> sz = 1;
    if(a -> lch) {
        a -> sz += a -> lch -> sz;
    }
    if(a -> rch) {
        a -> sz += a -> rch -> sz;
    }
}

int fs(Node *a) {
    return a != NULL ? a -> sz : 0;
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
    int p, Node pool[SIZE], 
    int *pool_idx
) {
    p--;
    Node *a, *b;
    new_node(&a, val, pool, pool_idx);
    split(*rt, rt, &b, p);
    *rt = merge(*rt, a);
    *rt = merge(*rt, b);
    return;
}

void erase(Node **rt, int p) {
    Node *a, *b;
    split(*rt, rt, &a, p - 1);
    split(a, &a, &b, 1);
    *rt = merge(*rt, b);
    return;
}

void convert(char s[50005], Node *n) {
    static int idx = 0;
    if(!n) return;
    if(n -> lch) {
        convert(s, n -> lch);
    }
    s[idx++] = n -> val;

#ifdef PRINT
    printf("%c", n -> val);
#endif

    if(n -> rch) {
        convert(s, n -> rch);
    }
}

void print(Node *n) {
    static int idx = 0;
    if(!n) return;
    if(n -> lch) {
        print(n -> lch);
    }
    
    printf("%c", n -> val);

    if(n -> rch) {
        print(n -> rch);
    }
}

int main(void) {
    time_t t;
    srand((unsigned) time(&t));

    Node *pool;
    int pool_idx = 0;
    pool = malloc(SIZE * sizeof(Node));
    memset(pool, 0, SIZE * sizeof(Node));
    Node *rt = NULL;

#ifndef DEBUG
    char op[30];
    while (scanf("%s", op) != EOF) {
        if(strcmp("insert", op) == 0) {
            char pos[10], val[2];
            scanf("%s%s", pos, val);
            int p;
            if(isdigit(pos[0])) {
                p = atoi(pos);
            } else if(strcmp("left", pos) == 0) {
                p = 1;
            } else { // right
                p = fs(rt) + 1;
            }
            insert(&rt, val[0], p, pool, &pool_idx);
        } else { // delete
            char pos[10];
            scanf("%s", pos);
            int p;
            if(isdigit(pos[0])) {
                p = atoi(pos);
            } else if(strcmp("left", pos) == 0) {
                p = 1;
            } else { // right
                p = fs(rt);
            }
            erase(&rt, p);
        }

#ifdef PRINT
        print(rt);
        printf("\n");
#endif

    }
#endif

    char *s, *c;
    s = malloc(50005 * sizeof(char));
    c = malloc(50005 * sizeof(char));

#ifdef DEBUG
    scanf("%s", s);
    int l = strlen(s);
    for(int i = 0; i < l; ++i) {
        insert(&rt, s[i], fs(rt) + 1, pool, &pool_idx);
    }

    erase(&rt, fs(rt));
#endif

    for(int i = 0; i < 50005; ++i) {
        s[i] = '\0';
        c[i] = '\0';
    }

    convert(s, rt);
    s[fs(rt)] = '\0';
    free(pool);

#ifdef DEBUG
    printf("%s\n", s);
#endif


    int len = 1, mx_len = 0, ans_num = 0;
    char pre = s[0];
    int slen = strlen(s);

    if(slen == 0) {
        printf("0\n");
        return 0;
    }

    for(int i = 1; i < slen; ++i) {
        if(s[i] == pre) {
            len++;
        } else {
            len = 1;
        }

        if(mx_len < len) {
            mx_len = len;
            ans_num = 0;
            c[ans_num++] = pre;
            c[ans_num] = '\0';
        } else if(mx_len == len) {
            c[ans_num++] = pre;
            c[ans_num] = '\0';
        }
        pre = s[i];
    }

    if((pre != s[slen - 1] || len == 1) && mx_len < len) {
        mx_len = len;
        ans_num = 0;
        c[ans_num++] = pre;
        c[ans_num] = '\0';
    } else if(((pre != s[slen - 1] || len == 1)) && mx_len == len) {
        c[ans_num++] = pre;
        c[ans_num] = '\0';
    }

    slen = strlen(c);
    for(int i = 0; i < slen; ++i) {
        printf("%c ", c[i]);
    }
    printf("%d\n", mx_len);

    free(s);
    free(c);
    return 0;
}