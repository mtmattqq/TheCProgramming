#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 20

int elements[N];
int path[N];
bool used[N];

bool find_balance(int n, int cur) {
    if(cur + 1 == n) {
        int n2 = n >> 1;
        
        int l = 0;
        for(int i = 0, j = 1; i < n2; ++i, ++j) {
            l += path[i] * j;
        }
        
        int r = 0;
        for(int i = n2, j = 1; i < (n2 << 1); ++i, ++j) {
            r += path[i] * j;
        }

        if(l == r) {
            for(int i = n2 - 1; i >= 0; --i) {
                printf("%d ", path[i]);
            }
            printf("_^_ ");
            for(int i = n2; i < (n2 << 1); ++i) {
                printf("%d%c", path[i], " \n"[i == (n2 << 1) - 1]);
            }
            return true;
        }
        return false;
    }

    for(int i = 0; i < n; ++i) if(!used[i]) {
        path[cur] = elements[i];
        used[i] = true;
        if(find_balance(n, cur + 1)) {
            return true;
        }
        used[i] = false;
    }
    return false;
}

int main(void) {
    int n;
    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", elements + i);
            used[i] = 0;
        }
        if(!find_balance(n, 0)) {
            printf("N\n");
        }
    }
}