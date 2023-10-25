#include <stdio.h>
#include <stdlib.h>

int gcd(int, int);
int value(int type, int width, int height, int length);

int main(void) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d", value(a, b, c, d));
    return 0;
}

int gcd(int a, int b) {
    return a % b == 0  ?  b  :  gcd(b, a % b);
}

int value(int type, int width, int height, int length) {
    if(width <= 0 || height <= 0 || length <= 0) {
        return -2;
    }

    int g = gcd(width, gcd(height, length));
    int val = width * height * length * g * g * g;

    switch(type) {
      case 79 :
        return 30 * val;
      case 47 :
        return 10 * val;
      case 29 :
        return 4 * val;
      case 82 :
        return 5 * val;
      case 26 :
        return 3 * val;
      case 22 :
        return 9 * val;
      default :
        return -1;
    }
}