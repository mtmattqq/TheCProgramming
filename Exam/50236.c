#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void mergeString(char** P, char L[26], char* A) {
    int str_num = 0;
    for(int idx = 0; P[idx] != NULL; ++idx) {
        str_num++;
    }

    int pri[26] = {0};
    for(int i = 0; i < 26; ++i) {
        pri[L[i] - 'a'] = i;
    }

#ifdef DEBUG
    for(int i = 0; i < 26; ++i) {
        printf("%d ", pri[i]);
    }
    printf("\n");
#endif

    int idx[205] = {0}, a_idx = 0;
    int in_loop = 1;
    while(in_loop) {
        int mn = 100, mx_pos = -1;
        for(int i = 0; i < str_num; ++i) {
            if(P[i][idx[i]] != '\0' && pri[P[i][idx[i]] - 'a'] < mn) {
                mn = pri[P[i][idx[i]] - 'a'];
                mx_pos = i;
            }
        }

#ifdef DEBUG
        printf(
            "use string : %d, %d th char, for its pri is %d\n", 
            mx_pos, idx[mx_pos], mn
        );
#endif

        if(mx_pos != -1) {
            A[a_idx] = P[mx_pos][idx[mx_pos]];
            a_idx++;
            idx[mx_pos]++;
            A[a_idx] = '\0';
        }
        in_loop = (mx_pos != -1);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    char* P[n + 1];
    char* freeP[n];
    int lengthA = 0;
    for(int i = 0; i < n; i++){
        int m;
        scanf("%d", &m);
        P[i] = (char*)malloc((m + 1) * sizeof(char));
        scanf("%s", P[i]);
        // We may change the pointers in P in mergeString,
        // so we make a copy of P to free them in the last step.
        freeP[i] = P[i];
        lengthA += m;
    }
    P[n] = NULL;
 
    char L[26], buffer[30];
    scanf("%s", buffer);
    strncpy(L, buffer, 26);
 
    char* A = (char *)malloc((lengthA + 1) * sizeof(char));
    mergeString(P, L, A);
    A[lengthA] = '\0';
    printf("%s\n", A);
 
    // free the memory
    for(int i = 0; i < n; i++){
        free(freeP[i]);
    }
    free(A);
}