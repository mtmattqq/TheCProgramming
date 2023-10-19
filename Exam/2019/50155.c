#include <stdio.h>

int min(int, int);
int max(int, int);

int main(void) {
    int a, b, c, d, e, f, g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);

#ifdef DEBUG
    printf("%d %d %d %d %d %d %d", a, b, c, d, e, f, g);
#endif

    int volume1 = a * b * d, volume2 = e * f * g;
    int area1 = a * b, area2 = (a * b) - e * f;
    if(volume1 == 0 || (volume2 >= (a * b * c) && area2 == 0)) {
        printf("0\n");
    } else if(area2 != 0 && volume1 / area2 >= g) {
        volume1 += volume2;
        printf("%d\n", min(c, volume1 / area1));
    } else if(area2 != 0){
        printf("%d\n", min(c, volume1 / max(1, area2)));
    } else {
        printf("%d\n", min(c, volume1 / area1 + g));
    }
}

int min(int a, int b) {
    return a < b  ?  a  :  b;
}

int max(int a, int b) {
    return a > b  ?  a  :  b;
}