#include <stdio.h>
#include <stdbool.h>

int da, db, dc;
int ea, eb, ec;
int fa, fb, fc;

bool check(int a, int b, int c) {
    if(a == 0 && b == 0 && c == 0) {
        return true;
    } else if(a < 0 || b < 0 || c < 0) {
        return false;
    }

    bool ret = false;
    ret |= check(a - da, b - db, c - dc);
    ret |= check(a - ea, b - eb, c - ec);
    ret |= check(a - fa, b - fb, c - fc);

    return ret;
}

void solve(int n) {
    if(n == 0) {
        return;
    }

    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if(check(a, b, c)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    solve(n - 1);
    return;
}

int main(void) {

    scanf("%d%d%d", &da, &db, &dc);
    scanf("%d%d%d", &ea, &eb, &ec);
    scanf("%d%d%d", &fa, &fb, &fc);

    int n;
    scanf("%d", &n);
    solve(n);
    return 0;
}