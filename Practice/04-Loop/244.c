#include <stdio.h>

int check_match(int, int);

int main(void) {
    int sp[3], fir[3];
    for(int i = 0; i < 3; ++i) {
        scanf("%d", sp + i);
    }
    for(int i = 0; i < 3; ++i) {
        scanf("%d", fir + i);
    }
    
    int lot, prize = 0;
    int p[10] = {0, 0, 0, 200, 1000, 4000, 10000, 40000, 200000};
    while(scanf("%d", &lot) != EOF) {
        for(int i = 0; i < 3; ++i) {
            if(check_match(lot, sp[i]) == 8) {
                prize += 2000000;
            }
        }
        for(int i = 0; i < 3; ++i) {
            prize += p[check_match(lot, fir[i])];
        }
    }

    printf("%d", prize);
}

int check_match(int a, int b) {
    int ret = 0;
    while(a > 0) {
        if(a % 10 == b % 10) {
            ret++;
        } else {
            break;
        }
        a /= 10;
        b /= 10;
    }
    return ret;
}