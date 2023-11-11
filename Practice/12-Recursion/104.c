#include <stdio.h>
#include <stdbool.h>

bool check(
    int a, int b, int c,
    int da, int db, int dc,
    int ea, int eb, int ec,
    int fa, int fb, int fc
) {
    if(a == 0 && b == 0 && c == 0) {
        return true;
    } else if(a < 0 || b < 0 || c < 0) {
        return false;
    }

    bool ret = false;
    ret |= check(a - da, b - db, c - dc, da, db, dc, ea, eb, ec, fa, fb, fc);
    ret |= check(a - ea, b - eb, c - ec, da, db, dc, ea, eb, ec, fa, fb, fc);
    ret |= check(a - fa, b - fb, c - fc, da, db, dc, ea, eb, ec, fa, fb, fc);

    return ret;
}

void solve(
    int n, 
    int da, int db, int dc,
    int ea, int eb, int ec,
    int fa, int fb, int fc
) {
    if(n == 0) {
        return;
    }

    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if(check(a, b, c, da, db, dc, ea, eb, ec, fa, fb, fc)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    solve(n - 1, da, db, dc, ea, eb, ec, fa, fb, fc);
    return;
}

int main(void) {

    int da, db, dc, ea, eb, ec, fa, fb, fc;

    scanf("%d%d%d", &da, &db, &dc);
    scanf("%d%d%d", &ea, &eb, &ec);
    scanf("%d%d%d", &fa, &fb, &fc);

    int n;
    scanf("%d", &n);
    solve(n, da, db, dc, ea, eb, ec, fa, fb, fc);
    return 0;
}