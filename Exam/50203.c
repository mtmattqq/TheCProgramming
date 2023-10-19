#include <stdio.h>
#include <stdbool.h>

#ifdef DEBUG
#define N 1005
#else 
#define N 100010
#endif

const int piece[10][10] = {
    {1, 0, 0},
    {0, 0, 1},
    {0, 0, 0},
    {1, 0, 1}
};

const int ph[10][10] = {
    {1, 1, 0},
    {0, 1, 1},
    {0, 1, 0},
    {1, 1, 1}
};

int max(int a, int b) {
    return (a > b) * a + (a <= b) * b;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int hight[N] = {0};

    int a, type;
    while(scanf("%d%d", &a, &type) != EOF) {
        int h = max(max(hight[a], hight[a + 1]), hight[a + 2]);
        bool isv = true;
        while(isv) {
            for(int i = 0; i < 3; ++i) {
                if(h + piece[type][i] <= hight[a + i]) {
                    isv = false;
                    h++;
                }
            }
            h--;
        }

        for(int i = 0; i < 3; ++i) {
            hight[a + i] = h + ph[type][i] + 1;
        }
    }

    for(int i = 0; i < n; ++i) {
        printf("%d ", hight[i]);
    }
    printf("\n");

    return 0;
}