#include <stdio.h>

int max(int, int);

int main(void) {
    int M, N;
    int x1, y1, e1, n1, f1;
    int x2, y2, e2, n2, f2;
    scanf("%d%d", &M, &N);
    scanf("%d%d%d%d%d", &x1, &y1, &e1, &n1, &f1);
    scanf("%d%d%d%d%d", &x2, &y2, &e2, &n2, &f2);

    int t = max(f1, f2);
    int st1 = 0, st2 = 1;
    int rn1 = n1, re1 = 0, rn2 = 0, re2 = e2;
    for(int i = 1; i <= t; ++i) {
        if(f1 > 0) {
            if(st1 == 0) {
                rn1--;
                y1 = (y1 + 1) % N;
                if(rn1 <= 0) {
                    st1 = 1;
                    re1 = e1;
                }
            } else {
                re1--;
                x1 = (x1 + 1) % M;
                if(re1 <= 0) {
                    st1 = 0;
                    rn1 = n1;
                }
            }
        }
        if(f2 > 0) {
            if(st2 == 0) {
                rn2--;
                y2 = (y2 + 1) % N;
                if(rn2 <= 0) {
                    st2 = 1;
                    re2 = e2;
                }
            } else {
                re2--;
                x2 = (x2 + 1) % M;
                if(re2 <= 0) {
                    st2 = 0;
                    rn2 = n2;
                }
            }
        }

        if(x1 == x2 && y1 == y2) {
            printf("robots explode at time %d\n", i);
            return 0;
        }
        f1--;
        f2--;
    }

    printf("robots will not explode\n");
    return 0;
}

int max(int a, int b) {
    return a > b  ?  a  :  b;
}