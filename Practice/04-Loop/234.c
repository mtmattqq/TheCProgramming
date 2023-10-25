#include <stdio.h>

long long POW(long long, int);

int main(void) {
    long long co[5] = {0, 0, 0, 1, 0};
    for(int i = 2; i >= 0; --i) {
        scanf("%lld", co + i);
    }

    // int i = -1;
    // printf("%d", POW(-i, 3) * co[3] + POW(-i, 2) * co[2] + (-i) * co[1] + co[0]);

    int ct = 0;
    for(long long i = -100000; i <= 100000; ++i) {
        long long rem = (POW(-i, 3) * co[3] + POW(-i, 2) * co[2] + (-i) * co[1] + co[0]);

        // if(i == -1) {
        //     printf("%d", rem);
        // }
        while(rem == 0) {
            printf("%lld%c", i, " \n"[ct == 2]);
            ct++;
            for(int j = 3; j >= 0; --j) {
                co[j] += co[j + 1] * (-i);
            }
            for(int j = 0; j <= 3; ++j) {
                co[j] = co[j + 1];
            }
            rem = (POW(-i, 3) * co[3] + POW(-i, 2) * co[2] + (-i) * co[1] + co[0]);
        }
    }
}

long long POW(long long a, int x) {
    long long ret = 1;
    for(int i = 0; i < x; ++i) {
        ret *= a;
    }
    return ret;
}