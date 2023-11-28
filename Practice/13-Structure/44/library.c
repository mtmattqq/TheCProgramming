#include "book.h"
#include "date.h"
#include <stdbool.h>

#ifdef DEBUG
#include <stdio.h>
#endif

unsigned int count_fine_per_day(unsigned int importance) {
    int idx = 0, p[2] = {0};
    for(int i = 0; i < 32; ++i) {
        if(importance & 1) {
            p[idx++] = i;
        }
        importance >>= 1;
    }
    return p[1] - p[0] - 1;
}

bool check(int y, int dpm[]) {
    if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
        dpm[2] = 29;
        return true;
    }
    dpm[2] = 28;
    return false;
}

int count_day_from_jone(struct Date date, int day_per_month[]) {
    check(date.year, day_per_month);
    int curm = 1, day = 0;
    while(curm < date.month) {
        day += day_per_month[curm];
        curm++;
    }
    day += date.day - 1;
    return day;
}

unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned) {
    int fine_per_day = count_fine_per_day(book.importance);

#ifdef DEBUG
    printf("Fine per day is : %d\n", fine_per_day);
#endif

    int day_per_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int db = count_day_from_jone(date_borrowed, day_per_month);
    int dr = count_day_from_jone(date_returned, day_per_month);

    int ret = 0;
    while(date_borrowed.year < date_returned.year) {
        ret += 365 + check(date_borrowed.year, day_per_month);
        date_borrowed.year++;
    }

    return (ret + (dr - db)) * fine_per_day;
}