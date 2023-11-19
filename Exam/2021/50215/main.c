#include <stdio.h>
#include <stdint.h>

#define ALL ((1U << 26) - 1)

int min(int a, int b) {
    return (a < b) * a + (a >= b) * b;
}

int solve(
    uint32_t set, int cur, 
    int n, int sum, 
    uint32_t strs[], uint32_t cost[]
) {
    if(set == ALL) {
        return sum;
    }

    if(cur == n) {
        return INT32_MAX;
    }

    int choose_this = solve(
        set | strs[cur], cur + 1, n, 
        sum + cost[cur], strs, cost
    );
    int dont_choose = solve(
        set, cur + 1, n, sum, strs, cost
    );

    return min(choose_this, dont_choose);
}

int main(void) {
    int n;
    char str[1010] = {0};

    while (scanf("%d", &n) == 1) {
        uint32_t v[20] = {0}, cost[20] = {0};
        for(int i = 0; i < n; ++i) {
            scanf("%s", str);
            int len = strlen(str);
            for(int j = 0; j < len; ++j) {
                v[i] |= (1U << str[j] - 'a');
                cost[i] += str[j] - 'a' + 1;
            }
        }

        printf("%d\n", solve(0, 0, n, 0, v, cost));
    }
    return 0;
}