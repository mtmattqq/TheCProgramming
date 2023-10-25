#include <stdio.h>

int area(int a[4]);
void intersection(int a[4], int b[4], int ret[4]);

#ifdef DEBUG
void print(int a[4]);
#endif

int main(void) {
    int a[4], b[4], c[4];
    for(int i = 0; i < 4; ++i) {
        scanf("%d", a + i);
    }
    for(int i = 0; i < 4; ++i) {
        scanf("%d", b + i);
    }
    for(int i = 0; i < 4; ++i) {
        scanf("%d", c + i);
    }

    int ans = area(a) + area(b) + area(c);

    int ab[4], bc[4], ca[4], abc[4];
    intersection(a, b, ab);
    intersection(b, c, bc);
    intersection(c, a, ca);
    intersection(ab, bc, abc);

#ifdef DEBUG
    print(ab);
    print(bc);
    print(ca);
    print(abc);
#endif

    ans -= area(ab) + area(bc) + area(ca);
    ans += area(abc);

    printf("%d", ans);

    return 0;
}

#ifdef DEBUG
void print(int a[4]) {
    for(int i = 0; i < 4; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
#endif

int area(int a[4]) {
    if(a[0] == 2147483647 || a[1] == 2147483647) {
        return 0;
    }
    return (a[2] - a[0]) * (a[3] - a[1]);
}

void intersection(int a[4], int b[4], int ret[4]) {
    ret[0] = ret[1] = 2147483647;
    if(a[0] <= b[0] && b[0] <= a[2] && a[2] <= b[2]) {
        ret[0] = b[0];
        ret[2] = a[2];
    } else if(b[0] <= a[0] && a[0] <= b[2] && b[2] <= a[2]) {
        ret[0] = a[0];
        ret[2] = b[2];
    } else if(b[0] <= a[0] && a[0] <= a[2] && a[2] <= b[2]) {
        ret[0] = a[0];
        ret[2] = a[2];
    } else if(a[0] <= b[0] && b[0] <= b[2] && b[2] <= a[2]) {
        ret[0] = b[0];
        ret[2] = b[2];
    }

    if(a[1] <= b[1] && b[1] <= a[3] && a[3] <= b[3]) {
        ret[1] = b[1];
        ret[3] = a[3];
    } else if(b[1] <= a[1] && a[1] <= b[3] && b[3] <= a[3]) {
        ret[1] = a[1];
        ret[3] = b[3];
    } else if(b[1] <= a[1] && a[1] <= a[3] && a[3] <= b[3]) {
        ret[1] = a[1];
        ret[3] = a[3];
    } else if(a[1] <= b[1] && b[1] <= b[3] && b[3] <= a[3]) {
        ret[1] = b[1];
        ret[3] = b[3];
    }
    return;
}