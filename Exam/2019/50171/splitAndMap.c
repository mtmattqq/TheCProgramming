#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void splitAndMap(char*** ptr, char* str) {
    int idx1 = 0;
    while(ptr[idx1] != NULL) {
        idx1++;
    }
    int *idx = calloc(idx1, sizeof(int));
    int *ct = calloc(idx1, sizeof(int));

    char *cur = strtok(str, "*");
    while(cur != NULL) {
        int mn = 2147483647, mn_idx = 0;
        for(int i = 0; i < idx1; ++i) {
            if(ct[i] < mn) {
                mn = ct[i];
                mn_idx = i;
            }
        }
        ptr[mn_idx][idx[mn_idx]] = cur;
        ct[mn_idx] += strlen(cur);
        idx[mn_idx]++;
        cur = strtok(NULL, "*");
    }
}