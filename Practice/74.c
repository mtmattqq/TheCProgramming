#include <stdio.h>

int main(void) {
    int n, m;
    scanf("%d", &n);

    int a[200010], ct[200010] = {0};
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    scanf("%d", &m);

    for(int i = 0; i < n; ++i) {
        ct[a[i] % m]++;
    }

    for(int i = 0; i < m; ++i) {
        printf("%d\n", ct[i]);
    }

    return 0;
}