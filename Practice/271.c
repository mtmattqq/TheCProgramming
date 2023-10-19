#include <stdio.h>

int main(void) {
    int n, m;
    int a[105] = {0}, b[105] = {0};

    scanf("%d", &n);
    for(int i = n - 1; i >= 0; --i) {
        scanf("%d", a + i);
    }

    scanf("%d", &m);
    for(int i = m - 1; i >= 0; --i) {
        scanf("%d", b + i);
    }

    int ans[205] = {0};
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            ans[i + j] += a[i] * b[j];
        }
    }

    for(int i = n + m - 2; i >= 0; --i) {
        printf("%d%c", ans[i], " \n"[i == 0]);
    }

    return 0;
}