#include <stdio.h>
#include <string.h>
#include <limits.h>

#define N 15
#define M 105

int min(int a, int b) {
    return (a < b) * a + (a >= b) * b;
}

int find_edit_dis(char a[], char b[]) {
    if(a[0] == '\0') {
        return strlen(b);
    }

    if(b[0] == '\0') {
        return strlen(a);
    }

    if(a[0] == b[0]) {
        return find_edit_dis(a + 1, b + 1);
    }

    return min(find_edit_dis(a, b + 1), find_edit_dis(a + 1, b)) + 1;
}

int main(void) {
    int idx = 0;
    char s[M][N] = {0};

    while(scanf("%s", s[idx]) != EOF) {
        idx++;
    }

    int ans_num = INT_MAX, ans_idx1 = 0, ans_idx2 = 0;
    for(int i = 0; i < idx - 1; ++i) {
        for(int j = i + 1; j < idx; ++j) {
            int dis = find_edit_dis(s[i], s[j]);
            if(dis < ans_num) {
                ans_num = dis;
                ans_idx1 = i + 1;
                ans_idx2 = j + 1;
            }
        }
    }

    printf("%d %d %d\n", ans_num, ans_idx1, ans_idx2);
    return 0;
}