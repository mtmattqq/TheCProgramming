#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int ct = 0, idx = 0;
    char *s, buf;
    s = malloc(1000005 * sizeof(char));
    while((buf = getchar()) != EOF) {
        s[idx++] = buf;
    }

#ifdef DEBUG
    printf("%s", s);
#endif

    int len = strlen(s);
    char last = '\0';
    for(int i = 0; i < len; ++i) {
        if(s[i] == '.' && (
                (i < len - 2 && s[i + 1] == ' ' && s[i + 2] == ' ') || 
                (i < len - 1 && s[i + 1] == '\n') ||
                s[i + 1] == '\0'
            )
        ) {
            ct++;
        }
        if(s[i] != ' ' && s[i] != '\n' && s[i] != '\t') {
            last = s[i];
        }
    }
    
    printf("%d\n", ct);

    free(s);
    return 0;
}