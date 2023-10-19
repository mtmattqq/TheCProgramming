#include <stdio.h>

int max(int, int);
int min(int, int);

int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);

    int sum[1005], mx[1005], mn[1005];

    for(int i = 0; i < 1005; ++i) {
        mx[i] = 0;
        mn[i] = 1e9 + 7;
    }

    for(int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        sum[a % m] += a;
        mx[a % m] = max(mx[a % m], a);
        mn[a % m] = min(mn[a % m], a);
    }

    for(int i = 0; i < m; ++i) {
        printf("%d %d %d\n", sum[i], mx[i], mn[i]);
    }
    return 0;
}

int max(int a, int b) {
    return a > b  ?  a  :  b;
}

int min(int a, int b) {
    return a < b  ?  a  :  b;
}