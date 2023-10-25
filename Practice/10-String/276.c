#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    char ignore[8][8] = {"of", "and", "the", "at", "of.", "and.", "the.", "at."};
    char s[150] = {0}, a[150] = {0};
    int len = 0;
    while(scanf("%s", s) != EOF) {
        int slen = strlen(s);
        bool isignored = false;
        for(int i = 0; i < 8; ++i) {            
            if(strcmp(s, ignore[i]) == 0) {
                isignored = true;
                break;
            }
        }

        if(!isignored) {
            a[len++] = ((s[0] - 'a') + 'A');
        }
        
        if(s[slen - 1] == '.') {
            printf("%s\n", a);
            for(int i = 0; i <= 127; ++i) {
                a[i] = 0;
            }
            len = 0;
        }
    }
    return 0;
}