#include <stdio.h>
#include <stdlib.h>

int mx(int a, int b) {
    return a > b  ?  a  :  b;
}

int max(int array[5][5]) {
    int ret = -2147483647;
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            ret = mx(ret, array[i][j]);
        }
    }
    return ret;
}
 
int main() {
    int i, j;
    int array[5][5];
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            scanf("%d", &(array[i][j]));
    printf("%d\n", max(array));
    return 0;
}