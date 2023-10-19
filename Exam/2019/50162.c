#include <stdio.h>

#define SIZE 5002
#define MOD 5001

void push(int a[SIZE], int val, int *rear) {
    a[*rear] = val;
    *rear = (*rear + 1) % MOD;
}

int pop(int a[SIZE], int *first) {
    int ret = a[*first];
    *first = (*first + 1) % MOD;
    return ret;
}

int size(int a, int b) {
    return (b - a + MOD * 2) % MOD;
}

int main(void) {
    int q[3][5002] = {0}, first[3] = {0}, rear[3] = {0};
    int now;
    while(scanf("%d", &now) != EOF) {
        push(q[now % 3], now, &(rear[now % 3]));
        if(
            size(first[0], rear[0]) >= 3 && 
            size(first[1], rear[1]) >= 1 && 
            size(first[2], rear[2]) >= 1
        ) {
            printf("%d ", pop(q[0], &(first[0])));
            printf("%d ", pop(q[0], &(first[0])));
            printf("%d ", pop(q[0], &(first[0])));
            printf("%d ", pop(q[1], &(first[1])));
            printf("%d\n", pop(q[2], &(first[2])));
        }
    }
}