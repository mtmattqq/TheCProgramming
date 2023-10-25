#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n ; ++i) {
        printf("%d\n", i);
    }
    for(int i = n - 1; i > 0; --i) {
        printf("%d\n", i);
    }
}