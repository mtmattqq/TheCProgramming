#include <stdio.h>

int main(void) {
    double A[20][20], y[20];
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%lf", &(A[i][j]));
        }
    }

    for(int i = 0; i < n; ++i) {
        scanf("%lf", &(y[i]));
    }

    double ans[20] = {0.0};
    for(int i = n - 1; i >= 0; --i) {
        ans[i] = y[i] / A[i][i];
        for(int j = i - 1; j >=0; --j) {
            y[j] -= ans[i] * A[j][i];
        }
    }

    for(int i = 0; i < n; ++i) {
        printf("%f\n", ans[i]);
    }
    return 0;
}