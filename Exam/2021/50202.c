#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifdef DEBUG
#define SIZE 55
#else 
#define SIZE 205
#endif

int main(void) {
    int h, w, k;
    scanf("%d%d%d", &h, &w, &k);

    int bd[SIZE][SIZE] = {0};
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            scanf("%d", &(bd[i][j]));
        }
    }

    int ans = INT_MIN;
    for(int i = k - 1; i < h - k + 1; ++i) {
        for(int j = k - 1; j < w - k + 1; ++j) {
            int sum = 0;
            for(int x = i - k + 1; x < i + k; ++x) {
                for(int y = j - k + 1; y < j + k; ++y) {
                    if(abs(x - i) + abs(y - j) == k - 1) {
                        sum += bd[x][y];
                    }
                }
            }

#ifdef DEBUG
            printf("%d\n", sum);
#endif

            ans = (ans > sum) * ans + (ans <= sum) * sum;
        }
    }

    printf("%d", ans);

    return 0;
}