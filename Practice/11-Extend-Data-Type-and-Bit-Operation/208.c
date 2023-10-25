#include <stdio.h>

int main(void) {
    unsigned n;
    int r, c;
    scanf("%d%d", &c, &r);
    char z, o;
    scanf(" %c %c", &z, &o);

    int i = 0, j = 0;
    while(scanf("%u", &n) != EOF) {
        for(int t = 31; t >= 0; --t) {
            if(n & (1 << t)) {
                printf("%c", z);
            } else {
                printf("%c", o);
            }

            j++;
            if(j >= c) {
                i++;
                j = 0;
                printf("\n");
            }

            if(i >= r) {
                break;
            }
        }

        if(i >= r) {
            break;
        }
    }
}