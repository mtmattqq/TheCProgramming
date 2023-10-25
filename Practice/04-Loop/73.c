#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int ct[3] = {0};
    for(int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        ct[a % 3]++;
    }

    for(int i = 0; i < 3; ++i) {
        printf("%d", ct[i]);
        printf("%c", " \n"[i == 2]);
    }
}