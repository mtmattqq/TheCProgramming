#include <stdio.h>
#include <stdbool.h>

void print_permutation(int a[], int n, int t[], int cur) {
    if(cur == n) {
        for(int i = 0; i < n; ++i) {
            printf("%d ", t[i]);
        }
        printf("\n");
    }

    for(int i = 0; i < n; ++i) {
        bool isf = false;
        for(int j = 0; j < cur; ++j) {
            if(t[j] == a[i]) {
                isf = true;
                break;
            }
        }

        if(!isf) {
            t[cur] = a[i];
            print_permutation(a, n, t, cur + 1);
            t[cur] = 0;
        }
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    int a[20] = {0}, t[20] = {0};
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n - 1; ++j) {
            if(a[j] > a[j + 1]) {
                int tp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tp;
            }
        }
    }

    print_permutation(a, n, t, 0);
}