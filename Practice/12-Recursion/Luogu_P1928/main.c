#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 20010

// b[2[2a]sd]
// 0123456789
// b
// ba
// baa
// baas
// baasd
// baasdaasd

int decompress(int len, char input[], int *idx, char ans[], int *ans_idx) {
    if(len <= *idx || input[*idx] == ']') {
        return 0;
    }

    if(input[*idx] == '[') {
        (*idx)++;
        int time = 0;
        while(isdigit(input[*idx])) {
            time = (time << 1) + (time << 3) + (input[*idx] - '0');
            (*idx)++;
        }

        int tp = *ans_idx, cur_len = 0;
        while(*idx < len && input[*idx] != ']') {
            cur_len += decompress(len, input, idx, ans, ans_idx);
        }
        (*idx)++;

        for(int i = 1; i < time; ++i) {
            for(int j = 0; j < cur_len; ++j) {
                ans[tp + i * cur_len + j] = ans[tp + j];
            }
        }
        *ans_idx = tp + time * cur_len;
        ans[*ans_idx] = '\0';
        return time * cur_len;
    }

    ans[*ans_idx] = input[*idx];
    (*idx)++;
    (*ans_idx)++;
    ans[*ans_idx] = '\0';
    return decompress(len, input, idx, ans, ans_idx) + 1;
}

int main(void) {
    char input[LEN] = {0}, ans[LEN] = {0};
    scanf("%s", input);
    int idx = 0, ans_idx = 0;
    int len = strlen(input);
    while(idx < len) {
        decompress(len, input, &idx, ans, &ans_idx);
    }
    printf("%s\n", ans);
    return 0;
}