#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool find(char *first, char *end, int target) {
    for(char *i = first; i != end; ++i) {
        if(target == *i) return true;
    }
    return false;
}

int main(void) {
    char s[105], *v = "aeiouAEIOU";
    scanf("%s", s);

    int len = strlen(s), ct[4] = {0};
    for(int i = 0; i < len; ++i) {
        if(isdigit(s[i])) {
            ct[0]++;
        } else if(find(v, v + 10, s[i])) {
            ct[1]++;
        } else if(isalpha(s[i])) {
            ct[2]++;
        }
    }

    printf("%d %d %d %d\n", ct[0], ct[1] + ct[2], ct[1], ct[2]);

    return 0;
}