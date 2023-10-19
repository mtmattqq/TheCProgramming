#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int idxE = 0, idxO = 0;
    int even[1005] = {0}, odd[1005] = {0};
    for(int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        if(a % 2 == 0) {
            even[idxE++] = a;
        } else {
            odd[idxO++] = a;
        }
    }

    for(int i = 0; i < idxO; ++i) {
        printf("%d%c", odd[i], " \n"[i == idxO - 1]);
    }

    for(int i = 0; i < idxE; ++i) {
        printf("%d%c", even[i], " \n"[i == idxE - 1]);
    }
    
    return 0;
}