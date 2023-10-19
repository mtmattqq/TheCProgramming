#include <stdio.h>
#include <string.h>

int **fi[200];
int *se[100000];

int ***constructTable(int A[], int B[]) {
    int fidx = 0, sidx = 0, bidx = 0;
    for(int i = 0; A[i] != 0; ++i) {
        fi[fidx] = se + sidx;
        fidx++;
        for(int j = 0; j < A[i]; ++j) {
            se[sidx] = B + bidx;
            while(B[bidx] != 0) {
                bidx++;
            }
            sidx++;
            bidx++;
        }
        se[sidx] = NULL;
        sidx++;
    }
    fi[fidx] = NULL;
    return fi;
}

 
int main(){
    int N, M;
    int A[100] = {}, B[500] = {};
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for(int i = 0; i < M; i++)
        scanf("%d", &B[i]);
 
    int ***ptr;
    ptr = constructTable(A, B);
    for(int i = 0; *(ptr+i) != NULL; i++)
        for(int j = 0; j < A[i]; j++)
            for(int k = 0; *(*(*(ptr+i)+j)+k) != 0; k++)
                printf("%d ", *(*(*(ptr+i)+j)+k));
    return 0;
}