#include <stdio.h>
#include <stdint.h>

#define N (16384 + 10)

void solve(int a[], int n, int l) {
    if(n < 3) {
        return;
    }

    // 2 1 5 5 = 13
    // 2 2 15 20 = 39
    // 3

    int64_t center_of_mass = 0, total_mass = 0;
    for(int i = 0; i < n; ++i) {
        center_of_mass += (i + 1) * a[i];
        total_mass += a[i];
    }

    if(center_of_mass % total_mass != 0) {
        return;
    }

    center_of_mass /= total_mass;

    solve(a, center_of_mass - 1, l);
    printf("%d\n", center_of_mass + l - 1);
    solve(a + center_of_mass, n - center_of_mass, center_of_mass + l);
    return;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int a[N] = {0};

    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    solve(a, n, 0);
}