#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEN 1280

int main(void) {
    char str[LEN] = {0}, com[LEN] = {0}, tp[LEN] = {0};
    scanf("%s", str);
    while(scanf("%s", com) == 1) {
        if(com[0] == 'p') {
            printf("%s\n", str);
        } else {
            char del[2] = {com[1], '\0'};
            char *a, *b;
            a = strtok(com + 1, del);
            b = strtok(NULL, del);

#ifdef DEBUG
            printf("a = %s\nb = %s\n", a, b);
#endif

            int lena = strlen(a), lenb = strlen(b);
            int len = strlen(str);
            char *cur = strstr(str, a);
            if(cur != NULL) {
                for(int i = 0; i < lena; ++i) {
                    *(cur + i) = ' ';
                }
                *(cur + lena - 1) = '\t';
            }

            int idx = 0;
            for(int i = 0; i < len; ++i) {
                if(str[i] == '\t') {
                    strcpy(tp + idx, b);
                    idx += lenb;
                } else if(str[i] != ' ') {
                    tp[idx++] = str[i];
                    tp[idx] = '\0';
                }
            }
            strcpy(str, tp);
        }
    }
    return 0;
}