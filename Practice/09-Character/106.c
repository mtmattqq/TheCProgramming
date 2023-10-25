#include <stdio.h>
#include <string.h>

int main(void) {
    char n[1005];
    while(scanf("%s", n) != EOF && n[0] != '-') {
        int len = strlen(n);
        int os = 0, es = 0;
        for(int i = 0; i < len; ++i) {
            os += (n[i] - '0') * (i & 1);
            es += (n[i] - '0') * (i & 1 ^ 1);
        }

        char ans[2][5] = {"no", "yes"};

        printf("%s %s %s %s\n", 
            ans[(n[len - 1] - '0') & 1 ^ 1], 
            ans[(os + es) % 3 == 0], 
            ans[(n[len - 1] - '0') % 5 == 0], 
            ans[((os - es) % 11 + 22) % 11 == 0]
        );
    }
}