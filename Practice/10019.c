#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void) {
    char s[105];
    while(gets(s)) {
        int l = 0, r = strlen(s);
        while(isspace(s[l])) l++;
        while(isspace(s[r - 1])) r--;
        for(int i = l; i < r; ++i) {
            printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}