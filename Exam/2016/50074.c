typedef struct ChildList ChildList;
typedef struct Node {
        ChildList *list;
} Node;
struct ChildList {
        Node *node;
        ChildList *next;
};
typedef struct Answer {
        int InternalNode;
        int Leaf;
        int MaxBranchFactor;
        int Depth;
} Answer;
void trace(Node *root, Answer *ans);

#include <stdio.h>
#include "trace.h"

int max(int a, int b) {
    return (a > b) * a + (a <= b) * b;
}

void dfs(Node *now, Answer *ans, int depth) {
    if(now->list == NULL) {
        ans->Leaf++;
        ans->Depth = max(ans->Depth, depth);
        return;
    }

    ans->InternalNode++;
    int ct = 0;
    ChildList *child = now->list;
    while(child != NULL) {
        dfs(child->node, ans, depth + 1);
        child = child->next;
        ct++;
    }
    ans->MaxBranchFactor = max(ans->MaxBranchFactor, ct);
    return;
}

void trace(Node *root, Answer *ans) {
    dfs(root, ans, 0);
}