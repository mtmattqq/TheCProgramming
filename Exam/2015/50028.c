#include "subtree.h"
#include <stdio.h>
#include <stdbool.h>

int max(int a, int b) {
    return (a > b) * a + (a <= b) * b;
}

bool dfs(Node *now, int k, int **p) {
    if(now == NULL) {
        return 0;
    }

    bool l = dfs(now->left, k, p);
    bool r = dfs(now->right, k, p);

    if(l && r && now->label != k) {
        *(*p) = now->label;
        (*p)++;
    }

    return l || r || now->label == k;
}

int getNode(Node *root, int label[], int k) {
    int *p = label;
    dfs(root, k, &p);
    return p - label;
}