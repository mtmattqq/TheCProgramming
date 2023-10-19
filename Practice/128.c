#include <stdio.h>
#include <stdbool.h>

#define DIRECTIONS 4

void intersection(int map[100][100], int result[4]) {
    const int dr[4] = {0, 1, 0, -1};
    const int dc[4] = {1, 0, -1, 0};

    int ct[4] = {0};

    for(int i = 0; i < 100; ++i) {
        for(int j = 0; j < 100; ++j) {
            int sum = 0;

            if(!map[i][j]) {
                continue;
            }
            
            for(int k = 0; k < 4; ++k) {
                if(
                    i + dr[k] >= 0 && 
                    i + dr[k] < 100 && 
                    j + dc[k] >= 0 && 
                    j + dc[k] < 100
                ) {
                    sum += map[i + dr[k]][j + dc[k]];
                }
            }

#ifdef DEBUG
            if(i < 3 && j < 3) {
                printf("%d\n", sum);
            }
#endif

            if(sum != 2 && sum > 0) {
                ct[sum - 1]++;
            } else if(
                sum == 2 && (
                (i + 1 < 100 && map[i + 1][j] && j + 1 < 100 && map[i][j + 1]) ||
                (i + 1 < 100 && map[i + 1][j] && j - 1 >= 0 && map[i][j - 1]) ||
                (i - 1 >= 0 && map[i - 1][j] && j + 1 < 100 && map[i][j + 1]) ||
                (i - 1 >= 0 && map[i - 1][j] && j - 1 >= 0 && map[i][j - 1]))
            ) {
                ct[2 - 1]++;
            }
        }
    }

    result[0] = ct[3];
    result[1] = ct[2];
    result[2] = ct[1];
    result[3] = ct[0];

    return;
}

int main(void) {

#ifdef DEBUG
    freopen("3.in", "r", stdin);
#endif

    int n = 100;

    int bd[100][100] = {0};
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &(bd[i][j]));
        }
    }

    int result[4] = {0};
    intersection(bd, result);

    printf("%d %d %d %d", result[0], result[1], result[2], result[3]);

    return 0;
}