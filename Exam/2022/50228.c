#include <stdio.h>

int main(void) {
    int n;
    int pre, now;
    int dif = 0, sum = 0, cur = 0, len = 0;
    scanf("%d", &n);
    scanf("%d", &pre);
    int mx_sum = pre, mx_first = pre, mx_len = 1;

    for(int i = 1; i <= n; ++i) {
        if(i != n) scanf("%d", &now);
        int d = (now - pre) * (i != n);
        if(d != dif) {
            if((sum > mx_sum) || 
               (sum == mx_sum && len > mx_len) ||
               (sum == mx_sum && len == mx_len && cur > mx_first)
            ) {
                mx_sum = sum;
                mx_len = len;
                mx_first = cur;
            }
            dif = d;
            sum = now + pre;
            cur = pre;
            len = 2;
        } else {
            sum += now;
            len++;
        }
        pre = now;
    }

    printf("%d %d %d\n", mx_sum, mx_len, mx_first);
    return 0;
}