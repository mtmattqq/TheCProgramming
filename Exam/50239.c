#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define LEN 2005

int main(void) {
    int n, m;
    assert(scanf("%d%d", &n, &m) == 2);
    char s[LEN] = {0};

    for(int i = 0; i < m; ++i) {
        int idx;
        char cur[55] = {0};
        assert(scanf("%s%d", cur, &idx) == 2);

        int len = strlen(cur);

#ifdef DEBUG
        printf("idx = %d\n", idx);
        printf("len = %d\n", len);
#endif

        for(int j = 0; j < len; ++j) {
            if(s[j + idx] == '\0') {
                s[j + idx] = cur[j];
            } else {
                s[j + idx] = (s[j + idx] + cur[j]) / 2;
            }
        }
    }

    bool isl = true;
    int i = LEN - 1;
    while(i >= 0) {
        isl &= (s[i] == '\0');
        s[i] = (s[i] == '\0' && !isl) * ' ' + (s[i] != '\0') * s[i];
        i--;
    }

    printf("%s\n", s);
    return 0;
}