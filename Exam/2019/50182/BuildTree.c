// typedef struct Node
// {
//           int val;
//           struct Node *left, *right;
// }Node;

#include <stdio.h>
#include "BuildTree.h"

Node *next(Node *n) {
    return n->left;
}

int size(Node *list) {
    int ret = 0;
    while(list != NULL) {

#ifdef DEBUG
        printf("%d ", list->val);
#endif

        ret++;
        list = next(list);
    }

#ifdef DEBUG
        printf("\n");
#endif    

    return ret;
}



// 1 -> 2 -> 3 -> 4
void cut_list(Node *list, int size, Node **first, Node **second) {
    if(list == NULL) {
        *first = *second = NULL;
        return;
    }
    
    *first = list;
    for(int i = 0; i < size - 1; ++i) {
        list = next(list);
    }
    *second = next(list);
    list->left = NULL;
    return;
}

Node* BuildTree(Node* list1, Node* list2) {
    if(list1 == NULL) {
        return list2;
    }
    if(list2 == NULL) {
        return list1;
    }

    Node *root;
    if(list1->val < list2->val) {
        root = list1;
        list1 = next(list1);
    } else {
        root = list2;
        list2 = next(list2);
    }

    int sz1 = size(list1);
    int first_size1 = (sz1 >> 1) + (sz1 & 1);
    // int second_size1 = (sz1 >> 1);
    
    int sz2 = size(list2);
    int first_size2 = (sz2 >> 1) + (sz2 & 1);
    // int second_size2 = (sz2 >> 1);

    Node *f1, *s1;
    cut_list(list1, first_size1, &f1, &s1);
    Node *f2, *s2;
    cut_list(list2, first_size2, &f2, &s2);

    root->left = BuildTree(f1, f2);
    root->right = BuildTree(s1, s2);
    return root;
}

