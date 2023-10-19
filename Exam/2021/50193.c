#include <stdio.h>

int abs(int);

int main(void) {
    int now, pre, mn = -1;
    scanf("%d", &pre);
    while(scanf("%d", &now) != EOF) {
        int n = now, p = pre;

        int h1, m1, s1, h2, m2, s2;
        s1 = n % 100;
        n /= 100;
        m1 = n % 100;
        n /= 100;
        h1 = n % 100;

#ifdef DEBUG
        printf("Time after = %d:%d:%d\n", h1, m1, s1);
#endif

        s2 = p % 100;
        p /= 100;
        m2 = p % 100;
        p /= 100;
        h2 = p % 100;

#ifdef DEBUG
        printf("Time before = %d:%d:%d\n", h2, m2, s2);
#endif

        h1 -= h2;
        m1 -= m2;
        s1 -= s2;

        int dif = abs(h1 * 3600 + m1 * 60 + s1);
        if(mn == -1 || mn > dif) {
            mn = dif;
        }
        pre = now;
    }
    printf("%d\n", mn);
}

int abs(int a) {
    return a > 0  ?  a  :  -a;
}