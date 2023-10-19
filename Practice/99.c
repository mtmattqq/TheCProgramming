#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct player {
    char name[70];
    int r[(1 << 16) + 10], c[(1 << 16) + 10];
    int a[300], b[300], d1, d2;
} Player;

Player ps[15] = {0};

int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 0; i < n; ++i) {
        scanf("%s", ps[i].name);
        for(int j = 0; j < m; ++j) {
            for(int k = 0; k < m; ++k) {
                int tp;
                scanf("%d", &tp);
                ps[i].r[tp] = j;
                ps[i].c[tp] = k;
            }
        }
    }

    bool in_game = true;
    int idx = 0, ending = 0;
    char ans[15][70];
    for(int i = 0; i < m * m; ++i) {
        int tar;
        scanf("%d", &tar);
        for(int j = 0; j < n; ++j) {
            ps[j].a[ps[j].r[tar]]++;
            if(ps[j].a[ps[j].r[tar]] >= m) {
                in_game = false;
                strcpy(ans[idx], ps[j].name);
                idx++;
                ending = tar;
                continue;
            }

            ps[j].b[ps[j].c[tar]]++;
            if(ps[j].b[ps[j].c[tar]] >= m) {
                in_game = false;
                strcpy(ans[idx], ps[j].name);
                idx++;
                ending = tar;
                continue;
            }

            if(ps[j].r[tar] == ps[j].c[tar]) {
                ps[j].d1++;
                if(ps[j].d1 >= m) {
                    in_game = false;
                    strcpy(ans[idx], ps[j].name);
                    idx++;
                    ending = tar;
                    continue;
                }
            }

            if(ps[j].r[tar] + ps[j].c[tar] == m - 1) {
                ps[j].d2++;
                if(ps[j].d2 >= m) {
                    in_game = false;
                    strcpy(ans[idx], ps[j].name);
                    idx++;
                    ending = tar;
                    continue;
                }
            }

        }

        if(!in_game) {
            break;
        }
    }

    printf("%d%c", ending, " \n"[ending == 0]);
    for(int i = 0; i < idx; ++i) {
        printf("%s%c", ans[i], " \n"[i == idx - 1]);
    }

    return 0;
}