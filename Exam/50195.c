#include <stdio.h>

int main(void) {
    int n, mx[3] = {0}, smx[3] = {0};
    int mxF[3] = {0}, mxS[3] = {0};
    int smxF[3] = {0}, smxS[3] = {0};
    int pre[3] = {-1, -1, -1}, idx = 0;
    while(scanf("%d", &n) != EOF) {
        if(pre[n - 1] == -1) {
            pre[n - 1] = idx;
        } else {
            int dis = idx - pre[n - 1];
            if(mx[n - 1] <= dis) {
                if(mx[n - 1] < dis) {
                    smx[n - 1] = mx[n - 1];
                    smxF[n - 1] = mxF[n - 1];
                    smxS[n - 1] = mxS[n - 1];
                }
                
                mx[n - 1] = dis;
                mxF[n - 1] = pre[n - 1];
                mxS[n - 1] = idx;
            } else if(smx[n - 1] <= dis) {
                smx[n - 1] = dis;
                smxF[n - 1] = pre[n - 1];
                smxS[n - 1] = idx;
            }
            pre[n - 1] = idx;
        }
        idx++;
    }

    for(int i = 0; i < 3; ++i) {
        printf("%d %d %d\n", smx[i], smxF[i], smxS[i]);
    }
    
    return 0;
}