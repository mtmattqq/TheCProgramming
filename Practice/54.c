#include <stdio.h>
#include <string.h>

int main(void) {
    char n[4], m[10];
    scanf("%s%s", n, m);

    int ans = 0;
    int ln = strlen(n), lm = strlen(m);
    // printf("%d", ln);
    for(int i = 0; i < lm - ln + 1; ++i) {
        int isv = 1;
        for(int j = 0; j < ln; ++j) {
            if(n[j] != m[i + j]) {
                isv = 0;
            }
        }
        ans += isv;
    }

    printf("%d\n", ans);
}