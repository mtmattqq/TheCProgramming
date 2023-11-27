#include <stdio.h>
#include <string.h>

#define W 40

int main(void) {
    int ans = 0;
    char *vowal = "aeiou";
    char word[W] = {0}, previous_consonant = 'z' + 1;

    while(scanf("%s", word) == 1) {
        char tp[W] = {0};
        int idx = 0;
        for(int i = 0, len = strlen(word); i < len; ++i) {
            if(strchr(vowal, word[i]) == NULL) {
                tp[idx++] = word[i];
            }
        }
        tp[idx] = '\0';

        if(previous_consonant < tp[0]) {
            ans++;
        }

        for(int i = 1; i < idx; ++i) {
            if(tp[i - 1] < tp[i]) {
                ans++;
            }
        }

        if(idx > 0) {
            previous_consonant = tp[idx - 1];
        }
    }

    printf("%d\n", ans);
    return 0;
}