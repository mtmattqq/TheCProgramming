#ifndef _ARRAY_H
#define _ARRAY_H
 
typedef struct arr {
    int lb, rb;
    int val[4096];
} ARRAY;
 
void init(ARRAY *a,  int left, int right);
int set(ARRAY *a, int index, int value);
int get(ARRAY *a, int index);
void print(ARRAY *a);
void sort(ARRAY *a);
 
#endif

#include "array.h"
#include <stdlib.h>
#include <stdio.h>
 
#define NOT_DEF -2147483647
#define OUT_OF_BOUND -2147483648
 
void init(ARRAY *a,  int left, int right) {
    a->lb = left;
    a->rb = right;
    for(int i = 0; i < right - left + 1; ++i) {
        a->val[i] = NOT_DEF;
    }
}
 
int set(ARRAY *a, int index, int value) {
    if(a->lb <= index && index <= a->rb) {
        a->val[index - a->lb] = value;
        return 1;
    }
    return OUT_OF_BOUND;
}
 
int get(ARRAY *a, int index) {
    if(a->lb <= index && index <= a->rb) {
        return a->val[index - a->lb];
    }
    return OUT_OF_BOUND;
}
 
void print(ARRAY *a) {
    for(int i = 0; i < a->rb - a->lb + 1; ++i) {
        if(a->val[i] == NOT_DEF) {
            printf("No value\n");
        } else {
            printf("%d\n", a->val[i]);
        }
    }
}
 
int cmp(const void *p, const void *q) {
    int a = *(int*)p;
    int b = *(int*)q;
    long long ret = (long long)a - b;
    return (ret < 0) * (-1) + (ret > 0) * 1;
}
 
void sort(ARRAY *a) {
    qsort(a->val, a->rb - a->lb + 1, sizeof(int), cmp);
}