#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N 100010

void replace(char str[], char tar, char val) {
    int len = strlen(str);
    for(int i = 0; i < len; ++i) {
        str[i] = (str[i] == tar) * val + (str[i] != tar) * str[i];
    }
}

void rm(char str[], char tar, char val) {
    static char tp[N] = {0};
    int idx = 0;
    int len = strlen(str);
    for(int i = 0; i < len; ++i) {
        if(str[i] != tar) {
            tp[idx] = str[i];
            idx++;
        }
    }
    tp[idx] = '\0';
    strcpy(str, tp);
}

void addhead(char str[], char val, char tar) {
    static char tp[N] = {0};
    strcpy(tp, str);
    str[0] = val;
    strcpy(str + 1, tp);
}

void addtail(char str[], char val, char tar) {
    int len = strlen(str);
    str[len] = val;
    str[len + 1] = '\0';
}

int main(void) {
    char str[N] = {0};
    scanf("%s", str);

    char valid_command[5][10] = {
        "replace",
        "remove",
        "addhead",
        "addtail",
        "end"
    };

    char input[N] = {0}, a[N] = {0};
    void (*operation[10])(char str[], char, char) = {
        &replace, &rm, &addhead, &addtail
    };

    while(scanf("%s", a) && strcmp(a, "end") != 0) {
        int com = -1;
        char b[2] = {'\0'}, c[2] = {'\0'};

        scanf("%s", b);
        if(strcmp(a, "replace") == 0) {
            scanf("%s", c);
        }

        for(int i = 0; i < 5; ++i) {
            if(strcmp(a, valid_command[i]) == 0) {
                com = i;
            }
        }

        if(com != -1) {
            operation[com](str, b[0], c[0]);
        } else {
            printf("invalid command %s\n", a);
            return 0;
        }
    }

    printf("%s\n", str);
    return 0;
}