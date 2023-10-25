#include <stdio.h>

int abs(int);

int main(void) {
    int n, x[15], y[15], c[15], ct[15] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d%d%d", x + i, y + i, c + i);
    }
    int m;
    scanf("%d", &m);

    for(int i = 0; i < m; ++i) {
        int xi, yi, mn = 1e9 + 7, cur = 0;
        scanf("%d%d", &xi, &yi);
        for(int j = 0; j < n; ++j) {
            if(ct[j] >= c[j]) {
                continue;
            }

            int dis = abs(xi - x[j]) + abs(yi - y[j]);
            if(dis < mn) {
                mn = dis;
                cur = j;
            } else if(dis == mn && x[j] < x[cur]) {
                cur = j;
            } else if(dis == mn && x[j] == x[cur] && y[j] < y[cur]) {
                cur = j;
            }
        }
        ct[cur]++;
    }

    for(int i = 0; i < n; ++i) {
        printf("%d\n", ct[i]);
    }
}

int abs(int a) {
    return a > 0  ?  a  :  -a;
}