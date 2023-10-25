#include <stdio.h>

void check(int, int*);

int main(void) {
    int year, ori;
    int day_per_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d%d", &year, &ori);
    check(year, day_per_month);

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int month, date;
        scanf("%d%d", &month, &date);
        if(month > 12 || month < 1) {
            printf("-1\n");
            continue;
        } else if(date < 1 || date > day_per_month[month]) {
            printf("-2\n");
            continue;
        }

        int curm = 1, day = ori;
        while(curm < month) {
            day = (day + day_per_month[curm]) % 7;
            curm++;
        }
        day = (day + date - 1) % 7;
        printf("%d\n", day);
    }
}

void check(int y, int *dpm) {
    if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
        dpm[2] = 29;
    } else {
        dpm[2] = 28;
    }
}