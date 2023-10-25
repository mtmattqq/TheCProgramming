#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int check(char a[80], char b[80]) {
    int la = strlen(a), lb = strlen(b);
    if(abs(lb - la) > 1) return 0;
    if(la == lb) {
        int ct = 0;
        for(int i = 0; i < la; ++i) {
            if(a[i] != b[i]) {
                if(ct == 0 && a[i] == b[i + 1] && a[i + 1] == b[i]) {
                    ct++;
                    char t = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = t;
                } else {
                    return 0;
                }
            }
        }
    } else {
        int aa[26] = {0}, bb[26] = {0};
        for(int i = 0; i < la; ++i) {
            aa[a[i] - 'a']++;
        }
        for(int i = 0; i < lb; ++i) {
            bb[b[i] - 'a']++;
        }

        int dif = 0;
        for(int i = 0; i < 26; ++i) {
            dif += abs(aa[i] - bb[i]);
        }
        if(dif > 1) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int n;
    scanf("%d", &n);

    char a[90], b[90];
    char ans[2][10] = {"no", "yes"};
    for(int i = 0; i < n; ++i) {
        scanf("%s%s", a, b);
        printf("%s\n", ans[check(a, b)]);
    }
    
    return 0;
}