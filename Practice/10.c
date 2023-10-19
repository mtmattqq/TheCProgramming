#include <stdio.h>

int POW(int, int);

int main(void) {
    int n, i;
    scanf("%d%d", &n, &i);
    printf("%d", POW(n, i));
    return 0;
}

int POW(int n, int x) {
    int ret = 1;
    for(int i = 0; i < x; ++i) {
        ret *= n;
    }
    return ret;
}