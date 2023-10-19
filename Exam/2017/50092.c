#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

void chasing(int **A[], int a, int *B[], int b, int C[], int c) {
    for(int i = 0; i < a; ++i) {
        A[i] = NULL;
    }

    for(int i = 0; i < b; ++i) {
        B[i] = NULL;
    }

    char buf[200] = {0};
    while(fgets(buf, 64, stdin) != NULL) {

#ifdef DEBUG
        printf("This line is : %s\n", buf);
#endif

        char input[5][70] = {0};
        int n = sscanf(
            buf, "%s%s%s%s%s", 
            input[0], input[1], input[2], input[3], input[4]
        );

        if(n != 4) {
            printf("0\n");
            continue;
        }

        int len[4] = {0};
        for(int i = 0; i < 4; ++i) {
            len[i] = strlen(input[i]);

#ifdef DEBUG
            printf("Len of input %d = %d\n", i, len[i]);
#endif

        }

        if(len[0] != 1 || len[2] != 1) {
            printf("0\n");
            continue;
        }

        bool all_digit = true;
        for(int i = 0; i < len[1]; ++i) {
            if(!isdigit(input[1][i])) {
                all_digit = false;
                break;
            }
        }

        for(int i = 0; i < len[3]; ++i) {
            if(!isdigit(input[3][i])) {
                all_digit = false;
                break;
            }
        }

#ifdef DEBUG
        printf("Alldigit = %d\n", all_digit);
#endif

        if(!all_digit) {
            printf("0\n");
            continue;
        }

        int idx1 = atoi(input[1]), idx2 = atoi(input[3]);
        if(input[0][0] == 'A' && input[2][0] == 'B' && idx1 < a && idx2 < b) {
            A[idx1] = &(B[idx2]);
            printf("1\n");
        } else if(input[0][0] == 'B' && input[2][0] == 'C' && idx1 < b && idx2 < c){
            B[idx1] = &(C[idx2]);
            printf("1\n");
        } else {
            printf("0\n");
            continue;
        }        
    }
}

int main() {
        int a = 5, b = 4, c = 3;
        int **A[5] = {}, *B[4] = {}, C[3] = {2, 1, 4};
        chasing(A, a, B, b, C, c);
 
        int **ansA[5] = {} ,*ansB[4] = {};
        for (int i = 0; i < a; i++)
                ansA[i] = NULL;
        for (int i = 0; i < b; i++)
                ansB[i] = NULL;
        ansA[2] = &B[1], ansA[3] = &B[0], ansB[1] = &C[1], ansB[2] = &C[0];
        /*Check A*/
        for (int i = 0; i < a; i++)
                if (A[i] != ansA[i] )
                        printf("A[%d] wrong answer!\n", i);
 
        /*Check B*/
        for (int i = 0; i < b; i++)
                if (B[i] != ansB[i] )
                        printf("B[%d] wrong answer!\n", i);
        return 0;
}