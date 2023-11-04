#include <stdio.h>
#include <string.h>

#define LEN 10005
#define N 32

int to_int(char c) {
    return c - 'a';
}

int main(void) {
    char input[LEN] = {0};
    int fre[N][N][N] = {0};

    while(scanf("%s", input) == 1) {
        int len = strlen(input);
        for(int i = 0; i < len - 2; ++i) {
            fre[to_int(input[i])][to_int(input[i + 1])][to_int(input[i + 2])]++;
        }
    }

    int mx[3] = {-1, -1, -1}, mxi[3], mxj[3], mxk[3];
    for(int idx = 0; idx < 3; ++idx) {
        for(int i = 0; i < 26; ++i) {
            for(int j = 0; j < 26; ++j) {
                for(int k = 0; k < 26; ++k) {
                    if(mx[idx] == -1 || mx[idx] < fre[i][j][k]) {
                        mx[idx] = fre[i][j][k];
                        mxi[idx] = i;
                        mxj[idx] = j;
                        mxk[idx] = k;
                    }
                }
            }
        }
        fre[mxi[idx]][mxj[idx]][mxk[idx]] = 0;
    }

    for(int i = 0; i < 3; ++i) {
        printf("%c%c%c\n", mxi[i] + 'a', mxj[i] + 'a', mxk[i] + 'a');
    }
    
    return 0;
}