#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int min(int a, int b) {
    return a < b  ?  a  :  b;
}

int main(void) {
    char s[150] = {0}, buf[150] = {0};
    while(scanf("%s", buf) != EOF) {

#ifdef DEBUG
        printf("%s ", buf);
        printf("%d\n", strlen(s));
#endif

        int len = strlen(buf), total_len = strlen(s);
        int r = min(len, total_len);
        for(; r >= 0; --r) {
            bool same = true;
            // 0123456789
            // aabaaaa
            // aaabb
            
#ifdef DEBUG
            printf("%d", r);
#endif

            for(int i = 0; i < r; ++i) {
                if(s[total_len - r + i] != buf[i]) {
                    same = false;
                    break;
                }
            }

            if(same) {
                break;
            }
        }

#ifdef DEBUG
        printf("\n%d\n", r);
#endif

        for(int i = ((total_len == 0) ? (0) : (r)); i < len; ++i) {
            s[total_len] = buf[i];

#ifdef DEBUG
            printf("%c ", buf[i]);
#endif

            total_len++;
        }
        s[total_len] = '\0';

#ifdef DEBUG
        printf("%s\n\n", s);
#endif

    }

    printf("%s", s);
    return 0;
}