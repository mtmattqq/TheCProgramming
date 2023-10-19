#include <stdio.h>

int main(void) {
    int n, mx = -1, mn = -1, ans = -1;

    while(scanf("%d", &n) != EOF) {
        int ct = 0, sum = 0;
        int tp = n;
        while(tp > 0) {
            ct++;
            sum += tp % 10;
            tp /= 10;
        }
        if(ans == -1 || mx < sum || 
            (mx == sum && mn > ct) || 
            (mx == sum && mn == ct && n > ans)
        ) {
            ans = n;
            mx = sum;
            mn = ct;
        }
    }

    printf("%d", ans);
}