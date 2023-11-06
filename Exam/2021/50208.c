#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LEN 15

int main(void) {
    int key_word_num = 6;
    char key_words[100][LEN] = {
        "for",
        "while",
        "if",
        "else if",
        "case"
    };

    int cc = 0;
    char input[10005] = {0}, *sub, *split = " ()\t:";
    while(fgets(input, 10005, stdin) != NULL) {
        sub = strtok(input, split);
        while(sub != NULL) {
            for(int i = 0; i < key_word_num; ++i) {
                if(strcmp(sub, key_words[i]) == 0) {
                    cc++;
                    break;
                }
            }

            cc += (strchr(sub, '?') != NULL);
            sub = strtok(NULL, split);
        }
    }

    printf("%d\n", cc);

    return 0;
}