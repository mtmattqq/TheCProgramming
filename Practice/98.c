#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INGE_NUM 105
#define LENGTH 105

typedef struct rec{
    char name[LENGTH];
    int num;
    char inge[INGE_NUM][LENGTH];
} Rec;

int cmp(const void *a, const void *b);
int cmp2(const void *a, const void *b);
int find(char a[INGE_NUM][LENGTH], char tar[LENGTH], int n);
int find2(Rec a[LENGTH], char tar[LENGTH], int n);

int main(void) {

#ifdef DEBUG
    freopen("input.in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    Rec rec[LENGTH] = {0};
    for(int i = 0; i < n; ++i) {
        scanf("%s", rec[i].name);
        scanf("%d", &(rec[i].num));
        for(int j = 0; j < rec[i].num; ++j) {
            scanf("%s", rec[i].inge[j]);
        }
        qsort(rec[i].inge, rec[i].num, sizeof(char) * LENGTH, cmp);
    }
    qsort(rec, n, sizeof(Rec), cmp2);

#ifdef DEBUG
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < rec[i].num; ++j) {
            printf("%s ", rec[i].inge[j]);
        }
    }
    printf("\n");
#endif

    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
        char a[LENGTH] = {0}, b[LENGTH] = {0};
        char ans[INGE_NUM][LENGTH] = {0};
        int idx = 0;

        scanf("%s%s", a, b);
        int ia = find2(rec, a, n);
        int ib = find2(rec, b, n);
        for(int j = 0; j < rec[ia].num; ++j) {
            int iia = find(rec[ib].inge, rec[ia].inge[j], rec[ib].num);
            if(iia != -1) {
                strcpy(ans[idx], rec[ia].inge[j]);
                idx++;
            }
        }

        if(idx == 0) {
            printf("nothing\n");
            continue;
        }

        for(int j = 0; j < idx; ++j) {
            printf("%s%c", ans[j], " \n\0"[j == idx - 1]);
        }
    }
    return 0;
}

int cmp(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int cmp2(const void *a, const void *b) {
    Rec *aa = (Rec *)a;
    Rec *bb = (Rec *)b;
    return cmp(&(aa -> name), &(bb -> name));
}

int find(char a[INGE_NUM][LENGTH], char tar[LENGTH], int n) {
    int l = -1, r = n;
    while(r - l > 1) {
        int mid = l + r >> 1;
        int ret = strcmp(a[mid], tar);
        if(ret == 0) {
            return mid;
        } else if(ret == 1) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return -1;
}

int find2(Rec a[LENGTH], char tar[LENGTH], int n) {
    int l = -1, r = n;
    while(r - l > 1) {
        int mid = l + r >> 1;
        int ret = strcmp(a[mid].name, tar);
        if(ret == 0) {
            return mid;
        } else if(ret == 1) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return -1;
}