#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

int max(int a, int b) {
    return (a > b) * a + (a <= b) * b;
}

int min(int a, int b) {
    return (a < b) * a + (a >= b) * b;
}

int find_loop(int *A, int *B[], bool isv[], int idx, int *mx_now, int *mn_now) {
    int ret = 0;
    do {
        *mx_now = max(*mx_now, A[idx]);
        *mn_now = min(*mn_now, A[idx]);
        isv[idx] = true;
        idx = B[idx] - A;
        ret++;
    } while(!isv[idx]);
    return ret;
}

void loops(int N, int *A, int *B[], int ans[4]) {
    int mx = INT_MIN, mn = INT_MAX, mxe = INT_MIN, mne = INT_MAX;
    bool *isv = calloc(N, sizeof(bool));

    for(int i = 0; i < N; ++i) {
        if(!isv[i]) {
            isv[i] = true;
            int mx_now = INT_MIN, mn_now = INT_MAX;
            int len = find_loop(A, B, isv, i, &mx_now, &mn_now);
            if(len > mx) {
                mx = len;
                mxe = mx_now;
            } else if(len == mx) {
                mxe = max(mxe, mx_now);
            }

            if(len < mn) {
                mn = len;
                mne = mn_now;
            } else if(len == mn) {
                mne = min(mne, mn_now);
            }
        }
    }

    ans[0] = mx;
    ans[1] = mn;
    ans[2] = mxe;
    ans[3] = mne;

    free(isv);
}

#include <stdio.h>
#include <stdlib.h>
// #include "loops.h"
#define MAXN 1000000
int main(){
    int N;
    int *A = (int *)malloc(sizeof(int) * MAXN);
    int **B = (int **)malloc(sizeof(int *) * MAXN);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", A + i);
    for(int i = 0, ptr; i < N; i++){
        scanf("%d", &ptr);
        B[i] = A + ptr;
    }
    int ans[4];
    loops(N, A, B, ans);
    for(int i = 0; i < 4; i++)
        printf("%d\n", ans[i]);
    return 0;
}