#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 300

void print_and_reset(
    int space[LENGTH], 
    char cur[LENGTH][LENGTH], 
    int *cur_len, 
    int *idx, int m
) {
    int idx_tp = 0;
    while(*cur_len < m) {
        space[idx_tp]++;
        idx_tp = (*idx == 1) ? 0 : (idx_tp + 1) % ((*idx) - 1);
        (*cur_len)++;
    }

    for(int i = 0; i < *idx; ++i) {
        printf("%s", cur[i]);
        for(int j = 0; j < LENGTH; ++j) {
            cur[i][j] = '\0';
        }
        for(int j = 0; j < space[i] - (i == *idx - 1); ++j) {
            printf(" ");
        }
        space[i] = 0;
    }
    printf("\n");

    *idx = 0;
    *cur_len = 0;
}

int main(void) {

#ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif

    int m;
    scanf("%d", &m);

    char buf[300] = {0}, cur[300][300] = {0};
    int idx = 0, space[300] = {0}, cur_len = 0;
    while(scanf("%s", buf) != EOF) {
        int len = strlen(buf);
        if(cur_len + len + (idx != 0) > m) {
            print_and_reset(space, cur, &cur_len, &idx, m);
        }

        strcpy(cur[idx], buf);
        space[idx] = 1;
        cur_len += len + (idx != 0);
        idx++;
    }
    print_and_reset(space, cur, &cur_len, &idx, m);

    return 0;
}