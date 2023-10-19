#include <stdio.h>

int min(int, int);

int main(void) {
    int N, M, k;
    scanf("%d%d%d", &N, &M, &k);
    int L = min(N, M);

    int idx = 0;
    for(int layer = 0; layer < L; ++layer) {
        if(idx + M - layer >= k) {
            printf("%d %d", layer + 1, layer + k - idx);
            return 0;
        }
        idx += M - layer;

        if(idx + N - layer - 1 >= k) {
            printf("%d %d", layer + 1 + k - idx, layer + 1);
            return 0;
        }
        idx += N - layer - 1;
    }
    return 0;
}

int min(int a, int b) {
    return a < b  ?  a  :  b;
}