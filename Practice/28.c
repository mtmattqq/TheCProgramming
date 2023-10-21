#include <stdio.h>

int sum(int n) {
    if(n == 0) {
        return 0;
    }
    return sum(n - 1) + n * n;
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", sum(n));
    return 0;
}