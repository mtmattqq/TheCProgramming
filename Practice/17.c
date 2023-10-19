#include <stdio.h>

int main(void) {
    int r, c;
    scanf("%d%d", &r, &c);

    int sum[105] = {0};
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            int tp;
            scanf("%d", &tp);
            sum[j] += tp;
        }
    }

    for(int i = 0; i < c; ++i) {
        printf("%d\n", sum[i] / r);
    }
    
    return 0;
}