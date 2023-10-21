#include <stdio.h>
#include <stdbool.h>

bool check(int D, int a, int b, int c, int A, int B, int C) {
    if(D == 0) {
        return true;
    }

    if(D < 0) {
        return false;
    }

    if(a > 0 && check(D - A, a - 1, b, c, A, B, C)) {
        return true;
    }

    if(b > 0 && check(D - B, a, b - 1, c, A, B, C)) {
        return true;
    }

    if(c > 0 && check(D - C, a, b, c - 1, A, B, C)) {
        return true;
    }

    return false;
}

int main(void) {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        int a, b, c, A, B, C, D;
        scanf("%d%d%d%d%d%d%d", &D, &a, &b, &c, &A, &B, &C);
        if(check(D, a, b, c, A, B, C)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
}