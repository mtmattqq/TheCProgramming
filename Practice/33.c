#include <stdio.h>
#include <stdbool.h>

#define DIRECTIONS 4

int main(void) {
    int n;
    scanf("%d", &n);

    bool bd[105][105] = {0};
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            scanf("%d", &(bd[i][j]));
        }
    }

    const int dr[DIRECTIONS] = {0, 1, 0, -1};
    const int dc[DIRECTIONS] = {1, 0, -1, 0};

    int ct[5] = {0};

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            int sum = 0;
            for(int k = 0; k < DIRECTIONS; ++k) {
                sum += bd[i][j] & bd[i + dr[k]][j + dc[k]];
            }

            if(sum != 2) {
                ct[sum]++;
            } else if(bd[i + 1][j] ^ bd[i - 1][j]){
                ct[2]++;
            }
        }
    }

    printf("%d\n%d\n%d\n%d\n", ct[4], ct[3], ct[2], ct[1]);
    
    return 0;
}