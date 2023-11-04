#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define N 32
#define LEN 64
#define COST 30

int min(int a, int b) {
    return (a < b) * a + (a >= b) * b;
}

int min_cost(int fre[N][N], int sum[N], int n, int idx, int cost) { 
    bool full = true;
    for(int i = 0; i < 26; ++i) {
        if(sum[i] <= 0) {
            full = false;
        }
    }

    if(full) {
        return cost;
    }

    if(idx == n) {
        return INT_MAX;
    }

    int ret = INT_MAX;
    for(int i = 0; i < 26; ++i) {
        sum[i] += fre[idx][i];
    }
    ret = min(ret, min_cost(fre, sum, n, idx + 1, cost + fre[idx][COST]));

    for(int i = 0; i < 26; ++i) {
        sum[i] -= fre[idx][i];
    }
    ret = min(ret, min_cost(fre, sum, n, idx + 1, cost));
    return ret;
}

int main(void) {

#ifdef DEBUG
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
#endif

    int n;
    scanf("%d", &n);

    char word[LEN] = {0};
    int fre[N][N] = {0};
    for(int i = 0; i < n; ++i) {
        scanf("%s%d", word, &(fre[i][COST]));
        int len = strlen(word);
        for(int j = 0; j < len; ++j) {
            fre[i][word[j] - 'a']++;
        }
    }

    int sum[N] = {0};
    printf("%d", min_cost(fre, sum, n, 0, 0));
    return 0;
}