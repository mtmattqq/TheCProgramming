#include <stdio.h>

int get_len(int);
void print(int, int);

int main(void) {
    int k, L, n, cur = 0;
    scanf("%d%d", &k, &L);
    while(scanf("%d", &n) != EOF && n > 0) {
        int len = get_len(n);
        if(cur + len * (n % k) <= L) {
            print(n, k);
            cur += len * (n % k);
        } else if(len * (n % k) <= L) {
            printf("\n");
            print(n, k);
            cur = len * (n % k);
        }

        if(cur == L) {
            cur = 0;
            printf("\n");
        }
    }
    return 0;
}

int get_len(int a) {
    int ct = 0;
    while(a > 0) {
        ct++;
        a /= 10;
    }
    return ct;
}

void print(int a, int k) {
    for(int i = 0; i < a % k; ++i) {
        printf("%d", a);
    }
    return;
}