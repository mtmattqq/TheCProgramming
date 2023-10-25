#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int a[1005] = {0};
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    for(int i = n - 1; i >= 0; --i) {

#ifdef DEBUG
        printf("%d\n", i);
#endif

        printf("%d%c", a[i], " \n"[i == 0]);
    }
    return 0;
}