#include <stdio.h>

int min(int, int);

int main(void) {
    char s[10], t[10];
    scanf("%s%s", s, t);

    int a = 0, cts[10] = {0}, ctt[10] = {0};
    for(int i = 0; i < 4; ++i) {
        if(s[i] == t[i]) {
            a++;
        } else {
            cts[s[i] - '0']++;
            ctt[t[i] - '0']++;
        }
    }

    int b = 0;
    for(int i = 0; i < 10; ++i) {
        b += min(cts[i], ctt[i]);
    }

    printf("%dA%dB\n", a, b);
}

int min(int a, int b) {
    if(a < b)
        return a;
    return b;
}