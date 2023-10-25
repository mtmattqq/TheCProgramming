#include <stdio.h>

int day_per_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void) {
    int year, month, day;
    scanf("%d%d%d", &year, &month, &day);
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        day_per_month[2] = 29;
    }

    if(month < 1 || month > 12 || day < 0 || day > 6) {
        printf("invalid\n");
        return 0;
    }

    printf(" Su Mo Tu We Th Fr Sa\n");
    printf("=====================\n");
    for(int i = 0; i < day; ++i) {
        printf("   ");
    }
    for(int i = 1; i <= day_per_month[month]; ++i) {
        day++;
        printf("%3d", i);
        if(day == 7) {
            day = 0;
            printf("\n");
        }
    }
    if(day != 0) printf("\n");
    printf("=====================\n");

    return 0;
}