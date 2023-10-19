#include <stdio.h>

#define SIZE 25002
#define MOD 25001
#define R 20
#define C 5

void push(int a[SIZE][3], int val[3], int *rear) {
    a[*rear][0] = val[0];
    a[*rear][1] = val[1];
    a[*rear][2] = val[2];
    *rear = (*rear + 1) % MOD;
}

int *pop(int a[SIZE][3], int *first) {
    int *ret = a[*first];
    *first = (*first + 1) % MOD;
    return ret;
}

int size(int a, int b) {
    return (b - a + MOD * 2) % MOD;
}

void next(int *curn, int *curr, int *curc) {
    *curn += (*curr == R && *curc == C);
    *curr = (*curr % R + 1) * (*curc == C) + (*curr) * (*curc != C);
    *curc = (*curc % C) + 1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    
    int q[SIZE][3] = {0}, first = 0, rear = 0;
    int now, curn = 1, curr = 1, curc = 1;

    while(scanf("%d", &now) != EOF) {
        if(now == 1) {
            if(size(first, rear) == 0) {
                printf("%d %d %d\n", curn, curr, curc);
                next(&curn, &curr, &curc);
            } else {
                int *ret = pop(q, &first);
                printf("%d %d %d\n", ret[0], ret[1], ret[2]);
            }
        } else { // now == 2
            if(curc == 3 || curc == 5) {
                int val[3] = {curn, curr, curc};
                push(q, val, &rear);
                next(&curn, &curr, &curc);
            }

            if(curn > n) {
                int *ret = pop(q, &first);
                printf("%d %d %d ", ret[0], ret[1], ret[2]);
                ret = pop(q, &first);
                printf("%d %d %d\n", ret[0], ret[1], ret[2]);
                continue;
            }

            printf("%d %d %d ", curn, curr, curc);
            next(&curn, &curr, &curc);
            printf("%d %d %d\n", curn, curr, curc);
            next(&curn, &curr, &curc);
        }
    }

    return 0;
}