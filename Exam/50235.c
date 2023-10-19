#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define LEN 30
#define MOD 1000
#define SIZE 5

typedef struct info {
    char str[LEN];
    int ct;
} Info;

int f(char s[LEN], int len) {
    int ret = 0;
    for(int i = 0; i < len; ++i) {
        ret += s[i];
    }
    return ret % MOD;
}

int insert(
    Info ht[MOD + SIZE][SIZE], 
    char tp[LEN]
) {
    int cur_len = strlen(tp);
    int h = f(tp, cur_len);
    for(int i = 0; i < SIZE; ++i) {
        if(strcmp(ht[h][i].str, tp) == 0) {
            ht[h][i].ct++;
            return ht[h][i].ct;
        }

        if(ht[h][i].str[0] == '\0') {
            strcpy(ht[h][i].str, tp);
            ht[h][i].ct++;
            return ht[h][i].ct;
        }
    }
}

int main(void) {
    char tp[LEN] = {0};
    Info ht[MOD + SIZE][SIZE] = {0};

    while(scanf("%s", tp) != EOF) {
        int cur_len = strlen(tp);
        if(tp[0] != '_' && !isalpha(tp[0])) {
            continue;
        }

        bool isv = true;
        for(int i = 1; i < cur_len; ++i) {
            if(tp[i] != '_' && !isdigit(tp[i]) && !isalpha(tp[i])) {
                isv = false;
                break;
            }
        }

        if(isv) {
            int num = insert(ht, tp);
            printf("%s %d\n", tp, num);
        }
    }
    return 0;
}