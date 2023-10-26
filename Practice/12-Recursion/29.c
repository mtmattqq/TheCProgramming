#include <stdio.h>

int find_way(int r, int c) {
    if(r == 1 || c == 1) {
        return 1;
    }
    return find_way(r, c - 1) + find_way(r - 1, c);
}

int main(void) {
    int r, c;
    scanf("%d%d", &r, &c);
    printf("%d\n", find_way(r, c));
    return 0;
}