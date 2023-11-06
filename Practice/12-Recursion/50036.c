#include <stdio.h>

int find_solution_num(
    int k, int n, int m, int a[], int idx, int cur
) {
    if(cur > m || idx == n) {
        return cur <= m && k <= 0;
    }

    int ret = 0;

    ret += find_solution_num(k - 1, n, m, a, idx + 1, cur + a[idx]);
    ret += find_solution_num(k, n, m, a, idx + 1, cur);

    return ret;
}

int main(void) {
    int k, n, m;
    int a[32] = {0};
    scanf("%d%d%d", &k, &n, &m);

    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    printf("%d\n", find_solution_num(k, n, m, a, 0, 0));
    return 0;
}