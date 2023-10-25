#ifndef __UTILS_H
#define __UTILS_H
 
int sp_rand();
void sp_srand(long long t);
 
typedef struct Node {
    int v;
    struct Node *next;
} Node;
 
void rm_list(Node *head);
Node* mk_list(int n);
 
#endif

// #include "utils.h"
 
static long long seed = 1;
int sp_rand() {
       return (seed = (seed * 9301 + 49297) % 233280);
}
void sp_srand(long long t) {
    seed = t;
}

// #include "utils.h"
#include <stdio.h>
#include <stdlib.h>
 
Node* mk_list(int n) {
    Node *head = NULL;
    Node *cur = head;
    for (int i = 0; i < n; i++) {
        Node *u = malloc(sizeof(Node));
        u->v = sp_rand(), u->next = NULL;
        if(head == NULL) {
            head = u;
            cur = u;
        } else {
            cur->next = u;
            cur = u;
        }
    }
    return head;
}
void rm_list(Node *head) {
    Node *cur = head;
    do {
        Node *tp = cur;
        cur = cur->next;
        free(tp);
    } while(cur != NULL);
    return;
}

// #include "utils.h"
#include <stdio.h>
#include <stdlib.h>
 
int main() {
    int n;
    long long s;
 
    scanf("%lld", &s);
    sp_srand(s);
    while (scanf("%d", &n) == 1) {
        Node *list = mk_list(n);
        Node *u = list;
        for (int i = 0; i < n; ++i) {
            // long long sum = 0;
            // int cnt = 1;
            // while (u && cnt < 100000) {
            //     sum += u->v * cnt;
            //     u = u->next, cnt++;
            //     i++;
            // }
            // printf("%lld\n", sum);
            printf("%d -> ", u->v);
            u = u->next;
        }
        rm_list(list);
    }
    return 0;
}