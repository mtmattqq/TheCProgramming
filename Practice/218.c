#include <stdio.h>

void init(int C[20][20]) {
    C[0][0] = 1;
    for(int i = 1; i < 20; ++i) {
        C[i][0] = 1;
        for(int j = 1; j < 20; ++j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    return;
}

int main(void) {
    int C[20][20] = {0};
    init(C);

    int n, m, sum = 0;
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= m; ++i) {
        sum += C[n][i];
    }

    printf("%d\n", sum);
    
    return 0;
}