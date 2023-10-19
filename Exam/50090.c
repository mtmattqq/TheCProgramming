#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#ifndef COUNT_H_INCLUDED
#define COUNT_H_INCLUDED
void count(int **p[]);
#endif

#define SIZE 1000
void count(int **p[]) {
    int idx = 0, idxa = 0;
    int *a[SIZE], ct[SIZE] = {0};
    
    for(int i = 0; i < SIZE; ++i) {
        a[i] = NULL;
    }

    for(int i = 0; p[i] != NULL; ++i) {
        bool isv = false;
        for(int j = 0; j < idxa; ++j) {
            if(a[j] == *p[i]) {
                ct[j]++;
                isv = true;
            }
        }

        if(!isv) {
            a[idxa] = *p[i];
            ct[idxa] = 1;
            idxa++;
        }
    }

    for(int i = 0; i < idxa; ++i) {
        for(int j = 0; j < idxa - 1; ++j) {
            if(
                ct[j] > ct[j + 1] || 
                (ct[j] == ct[j + 1] && *a[j] > *a[j + 1])
            ) {
                int *tpp = a[j], tpn = ct[j];
                a[j] = a[j + 1], ct[j] = ct[j + 1];
                a[j + 1] = tpp, ct[j + 1] = tpn;
            }
        }
    }

    for(int i = 0; i < idxa; ++i) {
        printf("%d %d\n", *a[i], ct[i]);
    }
}

 
#define MAX_SIZE_PTRARRAY 512
#define MAX_NUM_PTR 512
#define MAX_NUM_INTVAR 512
 
int main(){
  int **ptrArray[MAX_SIZE_PTRARRAY] = {};
  int  *intPtr[MAX_NUM_PTR];
  int   intVar[MAX_NUM_INTVAR];
 
  intVar[0] = 7;
  intVar[1] = 7;
  intVar[2] = 6;
  ptrArray[0] = &intPtr[0];
  ptrArray[1] = &intPtr[1];
  ptrArray[2] = &intPtr[2];
  ptrArray[3] = &intPtr[2];
  ptrArray[4] = &intPtr[3];
  ptrArray[5] = &intPtr[4];
  ptrArray[6] = NULL;
  intPtr[0] = &intVar[0];
  intPtr[1] = &intVar[1];
  intPtr[2] = &intVar[2];
  intPtr[3] = &intVar[2];
  intPtr[4] = &intVar[1];
 
  count(ptrArray);
 
  return 0;
}