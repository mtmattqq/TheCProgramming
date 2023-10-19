#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int d, ct = 0, esum = 0, osum = 0, last = 0, zct = 0;
    while(scanf("%d", &d) != EOF) {
        ct++;
        if(ct % 2 == 0) {
            esum += d;
        } else {
            osum += d;
        }
        zct += (d == 0);
        last = d;
    }
    printf("%d\n%d\n%d\n%d", ct, (last % 2 == 0), zct, (abs(esum - osum) % 11 == 0));
    return 0;
}