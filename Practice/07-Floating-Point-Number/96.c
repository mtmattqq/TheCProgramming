#include <stdio.h>

#define PI 3.1415926

int main(void) {
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);

#ifdef DEBUG
    printf("\n\n%f %f %f\n\n", a, b, c);
#endif

    double ans = (c * c * PI * 3) / 4.0;

    if(c > a) {
        ans += ((c - a) * (c - a) * PI) / 4.0;
    }

    if(c > b) {
        ans += ((c - b) * (c - b) * PI) / 4.0;
    }

    printf("%f", ans);
    return 0;
}