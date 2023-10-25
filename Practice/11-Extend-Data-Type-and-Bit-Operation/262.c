#include <stdio.h>

int max(int a, int b) {
    return (a > b) * a + (a <= b) * b;
}

int main(void) {
    int n;
    while(scanf("%d", &n) != EOF) {
        int con = 0, mx = 0;
        while(n > 0) {
            if(n & 1) {
                con++;
                mx = max(con, mx);
            } else {
                con = 0;
            }
            n >>= 1;
        }
        printf("%d\n", mx);
    }
}