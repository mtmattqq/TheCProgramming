#include <stdio.h>

int main() {
    int n, score = 0;
    scanf("%d", &n);
    score += (n % 3 == 0) * 3 + (n % 5 == 0) * 5;

    if(n <= 0) {
        score = -100;
    } else if(n >= 100 && n <= 200) {
        score += 50;
    } else {
        score -= 50;
    }
    printf("%d", score);
    return 0;
}