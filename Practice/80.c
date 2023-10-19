#include<stdio.h>

int square(int);
int dis(int, int, int, int);
void solve();

int main(void) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        solve();
    }
    return 0;
}

void solve() {
    int x[3], y[3];
    for(int i = 0; i < 3; ++i) {
        scanf("%d%d", x + i, y + i);
    }

    int d[3];
    for(int i = 0; i < 3; ++i) {
        d[i] = dis(x[i], y[i], x[(i + 1) % 3], y[(i + 1) % 3]);
    }

    for(int i = 0; i < 3; ++i) {
        for(int j = i; j < 2; ++j) {
            if(d[j] > d[j + 1]) {
                int t = d[j];
                d[j] = d[j + 1];
                d[j + 1] = t;
            }
        }
    }

    if(d[0] == d[1] || d[1] == d[2]) {
        printf("isosceles\n");
    } else if(d[0] + d[1] == d[2]) {
        printf("right\n");
    } else if(d[0] + d[1] > d[2]) {
        printf("acute\n");
    } else {
        printf("obtuse\n");
    }

    return;
}

int square(int x) {
    return x * x;
}

int dis(int x1, int y1, int x2, int y2) {
    return square(x1 - x2) + square(y1 - y2);
}