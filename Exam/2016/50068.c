#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tree.h"

Node *top(Node *st[], int tp) {
    if(tp < 0) {
        return NULL;
    }
    return st[tp];
}

void pop(int *tp) {
    (*tp)--;
}

void push(Node *st[], Node *val, int *tp) {
    (*tp)++;
    st[(*tp)] = val;
    return;
}

void traversal(Node *root, int N, int command[]) {
    int tp = -1;
    Node *cur = root, *ans[1001] = {root};
    for(int i = 0; i < N; ++i) {
        switch(command[i]) {
          case 0 :
            printf("%d\n", cur->label);
            return;
            break;
          case 1 :
            printf("%d\n", cur->label);
            break;
          case 2 : {
            Node *par = top(ans, tp);
            if(par == NULL) {
                printf("%d\n", cur->label);
                return;
            }
            cur = par;
            pop(&tp);
            break;
          }
          case 3 :
            push(ans, cur, &tp);
            if(cur->left == NULL) {
                printf("%d\n", cur->label);
                return;
            }
            cur = cur->left;
            break;
          case 4 :
            push(ans, cur, &tp);
            if(cur->right == NULL) {
                printf("%d\n", cur->label);
                return;
            }
            cur = cur->right;
            break;
          case 5 : {
            Node *par = top(ans, tp);
            if(cur == par->left) {
                if(par->right == NULL) {
                    printf("%d\n", cur->label);
                    return;
                } else {
                    cur = par->right;
                }
            } else {
                if(par->left == NULL) {
                    printf("%d\n", cur->label);
                    return;
                } else {
                    cur = par->left;
                }
            }
            break;
          }
        }
    }
    return;
}