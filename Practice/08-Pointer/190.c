#include <stdio.h>

int evaluate_f(int *iptr[], int n, int *index);

int f(int x, int y) {
    return 4 * x - 6 * y;
}

int evaluate_f(int *iptr[], int n, int *index) {
    int ret = -2147483648;
    for(int i = 0; i < n; ++i) {
        int k = f(iptr[i][0], iptr[i][1]);
        if(ret < k) {
            ret = k;
            *index = i;
        }
    }
    return ret;
}

int main(){
  int a[] = { 9, 7 };
  int b[] = { 3, 2 };
  int c[] = { 3, 2 };
  int d[] = { 9, 7 };
  int *iptr[] = { a, b, c, d };
  int max, index;
  max = evaluate_f(iptr, 4, &index);
  printf("%d %d\n", max, index);
}