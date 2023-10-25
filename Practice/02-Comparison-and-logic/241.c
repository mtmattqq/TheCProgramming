#include <stdio.h>
#include <stdbool.h>

int main() {
    int a[4], b[4];
    for(int i = 0; i < 4; ++i) {
        scanf("%d%d", a + i, b + i);
    }

    bool isv = true;
    for(int i = 0; i < 4; ++i) {
        if(a[i] * b[(i + 1) % 4] - a[(i + 1) % 4] * b[i] < 0) {
            isv = false;
        }
    }

    printf("%d", (int)isv);
    return 0;
}