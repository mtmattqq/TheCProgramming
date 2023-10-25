#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

#define SIDE 4
#define PI 3.14159265359879626433

typedef struct pt {
    int x, y;
} Pt;

int square(int);
int dis(Pt, Pt);
bool check(Pt, Pt);
void solve();

int main(void) {
    // freopen("1.in", "r", stdin);
    // freopen("1my.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        solve();
    }
    return 0;
}

void solve() {
    // input
    Pt p[4], center = {10000, 10000};
    for(int i = 0; i < SIDE; ++i) {
        scanf("%d%d", &(p[i].x), &(p[i].y));
        // center.x += p[i].x;
        // center.y += p[i].y;
        if(p[i].x + p[i].y < center.x + center.y) {
            center = p[i];
        }
    }

    // center.x /= SIDE;
    // center.y /= SIDE;
    // center = p[0];

    // printf("After shifting : ");
    for(int i = 0; i < SIDE; ++i) {
        p[i].x -= center.x;
        p[i].y -= center.y;
        // printf("%d %d ", p[i].x, p[i].y);
    }

    // printf("\nAngle : ");
    // for(int i = 0; i < SIDE; ++i) {
    //     printf("%.2f ", atan2(p[i].y, p[i].x));
    // }

    // sort by angle from origin
    for(int i = 0; i < SIDE; ++i) {
        for(int j = i + 1; j < SIDE; ++j) {
            if(check(p[i], p[j])) {
                Pt t = p[j];
                p[j] = p[i];
                p[i] = t;
            }
        }
    }

    // printf("\nAfter sorting : ");
    // for(int i = 0; i < SIDE; ++i) {
    //     printf("%d %d ", p[i].x, p[i].y);
    // }

    // determine whether the four angles are all right angle
    bool all_right = true;
    for(int i = 0; i < SIDE; ++i) {
        if(
            dis(p[i], p[(i + 1) % SIDE]) + 
            dis(p[(i + 1) % SIDE], p[(i + 2) % SIDE]) !=
            dis(p[i], p[(i + 2) % SIDE])
        ) {
            all_right = false;
        }
    }

    // determine whether the four edges are all in same length
    bool all_same = true;
    int d = dis(p[0], p[1]);
    for(int i = 1; i < SIDE; ++i) {
        if(dis(p[i], p[(i + 1) % SIDE]) != d) {
            all_same = false;
        }
    }

    if(all_same && all_right) {
        printf("square\n");
    } else if(all_same) {
        printf("diamond\n");
    } else if(all_right) {
        printf("rectangle\n");
    } else {
        printf("other\n");
    }

    return;
}

int square(int x) {
    return x * x;
}

int dis(Pt p1, Pt p2) {
    return square(p1.x - p2.x) + square(p1.y - p2.y);
}

int cross(Pt p1, Pt p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

bool check(Pt p1, Pt p2) {
    bool oa = (p1.x == 0 && p1.y == 0);
    bool ob = (p2.x == 0 && p2.y == 0);
    if(oa != ob) {
        return oa < ob;
    }
    // sort by cross product
    oa = p1.y < 0;
    ob = p2.y < 0;
    if(oa != ob) {
        return oa < ob;
    }
    return cross(p1, p2) < 0;

    // // sort by atan2
    // double a1 = atan2(p1.y, p1.x), a2 = atan2(p2.y, p2.x);
    // if(a1 < 0) {
    //     a1 += 2 * PI;
    // }
    // if(a2 < 0) {
    //     a2 += 2 * PI;
    // }
    // return a1 < a2;
}