#include <stdio.h>

int min(int a, int b) {
    return (a > b) * b + (a <= b) * a;
}

int main(void) {
    int k;
    scanf("%d", &k);

    int cap[20005] = {0}, vol[20005] = {0};
    for(int i = 0; i < k; ++i) {
        scanf("%d", cap + i);
    }
    for(int i = 0; i < k; ++i) {
        scanf("%d", vol + i);
    }

    int i, j;
    while(scanf("%d%d", &i, &j) != EOF) {
        if(i == k) {
            vol[j] = cap[j];
        } else if(j == k) {
            vol[i] = 0;
        } else {
            int m = min(vol[i], cap[j] - vol[j]);
            vol[i] -= m;
            vol[j] += m;
        }
    }

    for(int i = 0; i < k; ++i) {
        printf("%d%c", vol[i], " \n"[i == k - 1]);
    }

    return 0;
}