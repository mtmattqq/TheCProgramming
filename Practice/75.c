#include <stdio.h>
#include <string.h>

int main(void) {
    char s[105];
    scanf("%s", s);

    int ct[26] = {0};
    int len = strlen(s);
    for(int i = 0; i < len; ++i) {
        if('a' <= s[i] && s[i] <= 'z') {
            ct[s[i] - 'a']++;
        } else if('A' <= s[i] && s[i] <= 'Z') {
            ct[s[i] - 'A']++;
        }
    }

    for(int i = 0; i < 26; ++i) {
        printf("%d\n", ct[i]);
    }
    return 0;
}