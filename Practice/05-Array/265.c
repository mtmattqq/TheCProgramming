#include <stdio.h>

#define INF 0x3f3f3f3f

int max(int, int);
int min(int, int);

int main(void) {
    int x, y, mxx = -INF, mxy = -INF, mnx = INF, mny = INF;
    
    while(scanf("%d%d", &x, &y) != EOF) {
        mxx = max(mxx, x);
        mnx = min(mnx, x);
        mxy = max(mxy, y);
        mny = min(mny, y);
    }

    printf("%d", (mxx - mnx) * (mxy - mny));

    return 0;
}

int max(int a, int b) {
    return a > b  ?  a  :  b;
}

int min(int a, int b) {
    return a < b  ?  a  :  b;
}