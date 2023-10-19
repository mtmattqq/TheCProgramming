#include <stdio.h>

int POW(int a, int n) {
    return n > 1  ?  a * POW(a, n - 1)  :  a;
}

int main(void) {
    int a_b_c_d, a2_b2_c2_d2, a3_b3_c3_d3, a4_b4_c4_d4;
    scanf("%d%d%d%d", &a_b_c_d, &a2_b2_c2_d2, &a3_b3_c3_d3, &a4_b4_c4_d4);
    // int ab_bc__X2 = a2_b2_c2_d2 - POW(a_b_c_d, 2);

    for(int i = 1; i <= 500; ++i) {
        for(int j = 1; j <= 500; ++j) {
            for(int k = 1; k <= 500; ++k) {
                int l = a_b_c_d - i - j - k;
                if(l > 0 &&
                   POW(i, 2) + POW(j, 2) + POW(k, 2) + POW(l, 2) == a2_b2_c2_d2 &&
                   POW(i, 3) + POW(j, 3) + POW(k, 3) + POW(l, 3) == a3_b3_c3_d3 &&
                   POW(i, 4) + POW(j, 4) + POW(k, 4) + POW(l, 4) == a4_b4_c4_d4
                ) {
                    printf("%d\n%d\n%d\n%d\n", l, k, j, i);
                    return 0;
                }
            }
        }
    }
    
    printf("-1\n");

    return 0;
}