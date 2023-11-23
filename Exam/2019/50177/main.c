#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void set(uint16_t *a, int p) {
    (*a) |= ((uint16_t)1 << p);
}

void reset(uint16_t *a, int p) {
    (*a) = ~(*a);
    set(a, p);
    (*a) = ~(*a);
}

void flip(uint16_t *a, int p) {
    (*a) ^= ((uint16_t)1 << p);
}

void modify(uint16_t *a, int p, bool val) {
    if(val) {
        set(a, p);
        return;
    }
    reset(a, p);
}

bool in(int n, int p, int cur) {
    return p >= 0 && p < n * n && 
        !(p % n == 0 && (cur + 1) % n == 0) &&
        !(p % n == n - 1 && (cur - 1) % n == n - 1);
}

bool solve(
    const int n, const uint16_t board, 
    const int cur, const uint16_t indice, 
    const int dp[], int *min, uint16_t *sol
) {

#ifdef DEBUG
    printf("We have choosed : ");
    for(int i = 0; i < n * n; ++i) {
        if(indice & ((uint16_t)1 << i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    printf("But the board look like : ");
    for(int i = 0; i < n * n; ++i) {
        if(board & ((uint16_t)1 << i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
#endif

    if(board == 0) {
        int ct = 0;
        for(int i = 0; i < n * n; ++i) {
            if(indice & ((uint16_t)1 << i)) {
                ct++;
            }
        }
        if(ct < *min) {
            *min = ct;
            *sol = indice;
        }
        return true;
    }

    if(cur == n * n) {
        return false;
    }

    uint16_t choose_this = board;
    for(int i = 0; i < 5; ++i) {
        if(in(n, cur + dp[i], cur)) {
            flip(&choose_this, cur + dp[i]);
        }
    }

    return solve(n, choose_this, cur + 1, indice | ((uint16_t)1 << cur), dp, min, sol) |
        solve(n, board, cur + 1, indice, dp, min, sol);
}

int main(void) {

#ifdef DEBUG
    uint16_t test = 0;
    set(&test, 10);
    printf("test should be 1024, and it is : %u\n", test);
    flip(&test, 10);
    printf("test should be 0, and it is : %u\n", test);
    flip(&test, 10);
    printf("test should be 1024, and it is : %u\n", test);
#endif

    int n;
    scanf("%d", &n);
    uint16_t board = 0;
    int light_up;
    while(scanf("%d", &light_up) == 1) {
        set(&board, light_up);
    }

    int min = 100001;
    uint16_t sol = 0;
    const int dp[] = {0,  n, -n, 1, -1};
    solve(n, board, 0, 0, dp, &min, &sol);

    for(int i = 0; i < n * n; ++i) {
        if(sol & ((uint16_t)1 << i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}