#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 105
#define MOD 10000
#define C 15

typedef struct info {
    char s[10];
    int r, c;
} Info;

int min(int a, int b) {
    return (a < b) * a + (a >= b) * b;
}

int max(int a, int b) {
    return (a > b) * a + (a <= b) * b;
}

int f(char *str) {
    int ret = 0;
    for(int idx = 0; str[idx] != '\0'; ++idx) {
        ret = (ret + (str[idx] - 'a' + 1)) * 29 % MOD;
    }
    return ret;
}

int find(Info ht[SIZE * SIZE][C], char *str, int *r, int *c) {
    int h = f(str);
    for(int i = 0; i < C; ++i) {

#ifdef DEBUG
        printf("Want to find \"%s\", and this is \"%s\"\n", str, ht[h][i].s);
#endif

        if(strcmp(ht[h][i].s, str) == 0) {
            *r = ht[h][i].r;
            *c = ht[h][i].c;
            return i;
        }
    }
    *r = *c = -1;
    return -1;
}

void insert(Info ht[SIZE * SIZE][C], char *str, int r, int c) {
    int h = f(str);
    for(int i = 0; i < C; ++i) {
        if(ht[h][i].s[0] == '\0') {
            strcpy(ht[h][i].s, str);
            ht[h][i].r = r;
            ht[h][i].c = c;
            return;
        }
    }
    return;
}

void delete(Info ht[SIZE * SIZE][C], char *str, int idx) {
    int h = f(str);
    ht[h][idx].r = ht[h][idx].c = 0;
    for(int i = 0; i < 10; ++i) {
        ht[h][idx].s[i] = '\0';
    }
}

int try_insert(
    Info ht[SIZE * SIZE][C], 
    char *str,
    int nr, int nc,
    int *fr, int *fc,
    int *sr, int *sc
) {
    int r, c;
    int ret = find(ht, str, &r, &c);

#ifdef DEBUG
    printf("ret = %d\n", ret);
#endif

    if(ret == -1) {
        insert(ht, str, nr, nc);
        return 0;
    } else {
        *fr = r; *fc = c;
        *sr = nr; *sc = nc;
        delete(ht, str, ret);
        return 1;
    }
}

Info ht[SIZE * SIZE][C] = {0};
char bd[SIZE][SIZE][SIZE][10] = {0};
int top[SIZE][SIZE] = {0};

int main(void) {

#ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif

    int N;
    scanf("%d", &N);

    int fr, fc, sr, sc;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j <= i; ++j) {
            for(int k = 0; k <= i; ++k) {
                scanf("%s", bd[i][j][k]);
                if(j == i || k == i) {
                    // int r, c;
                    // int ret = find(ht, bd[i][j][k], &r, &c);
                    // if(ret == -1) {
                    //     insert(ht, bd[i][j][k], j, k);
                    // } else {
                    //     fr = r; fc = c;
                    //     sr = j; sc = k;
                    //     delete(ht, bd[i][j][k], ret);
                    // }
                    try_insert(
                        ht, bd[i][j][k], j, k, &fr, &fc, &sr, &sc);
                    top[j][k] = i;
                }
            }
        }
    }

    int in_loop = 1;
    while(in_loop) {
        printf("%s\n", bd[top[fr][fc]][fr][fc]);

        top[fr][fc] = min(top[fr][fc] + 1, N);
        top[sr][sc] = min(top[sr][sc] + 1, N);
        
#ifdef DEBUG
        printf(
            "next str is \"%s\" and \"%s\"\n", 
            bd[top[fr][fc]][fr][fc],
            bd[top[sr][sc]][sr][sc]
        );
#endif

        int nfr, nfc, nsr, nsc;
        int a = (
            top[fr][fc] < N && 
            try_insert(
                ht, bd[top[fr][fc]][fr][fc], fr, fc, &nfr, &nfc, &nsr, &nsc)
        );

        int b = (
            top[sr][sc] < N && 
            try_insert(
                ht, bd[top[sr][sc]][sr][sc], sr, sc, &nfr, &nfc, &nsr, &nsc)
        );
        
        fr = nfr; fc = nfc;
        sr = nsr; sc = nsc;
        in_loop = a | b;
    }

    return 0;
}