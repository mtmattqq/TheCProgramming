#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 105

int main(void) {
    int n;
    scanf("%d", &n);

    int idx[SIZE] = {0}, a;
    memset(idx, -1, SIZE * sizeof(int));
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        if(idx[a] >= 0) {
            printf("%d %d %d\n", i, idx[a], a);
            idx[a] = -1;
        } else {
            printf("%d\n", i);
            idx[a] = i;
        }
    }

    return 0;
}