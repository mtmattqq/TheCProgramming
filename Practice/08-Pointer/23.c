#include <stdio.h>

int max(int *iptr[], int n);
int max(int *iptr[], int n) {
    int ret = -2147483648;
    for(int i = 0; i < n; ++i) {
        if(*(iptr[i]) > ret) {
            ret = *(iptr[i]);
        }
    }
    return ret;
}
 
int main() {
    int n, i;
    int array[100];
    int *iptr[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &(array[(i + 3) % n]));
        iptr[i] = &(array[(i + 3) % n]);
    }
    printf("%d\n", max(iptr, n));
    return 0;
}