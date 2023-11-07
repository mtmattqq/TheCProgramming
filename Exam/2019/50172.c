#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 50

void print_star(int c) {
    for(int j = 0; j < c; ++j) {
        printf("*");
    }
    return;
}

int main(void) {
    char words[2][LEN] = {0};
    int len[2] = {0, 0};
    int idx = 0;

    int c = 0;
    while(scanf("%s", words[idx & 1]) == 1) {
        int cover = 0;
        if(
            len[idx ^ 1] != 0 && 
            words[idx][0] == words[idx ^ 1][len[idx ^ 1] - 1]
        ) {
            strcpy(words[idx], words[idx] + 1);
            cover = 1;
        }

        len[idx] = strlen(words[idx]);

        if(idx) {
            for(int i = 0; i < len[idx]; ++i) {
                print_star(c);
                printf("%c", words[idx][i]);
                if(i != len[idx] - 1) {
                    printf("\n");
                }
            }
        } else {
            if(cover == 0 && c != 0) {
                printf("\n");
                print_star(c);
            }
            c += cover != 0;
            printf("%s\n", words[idx & 1]);
            c += len[idx & 1] - 1;
        }
        idx ^= 1;
    }
    
    return 0;
}