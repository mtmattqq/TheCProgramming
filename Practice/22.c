#include <stdio.h>

void posneg(int array[5][5], int result[2]) {
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            if(array[i][j] > 0) {
                result[1]++;
            } else if(array[i][j] < 0) {
                result[0]++;
            }
        }
    }
    return;
}

int main() {
  int i, j;
  int array[5][5];
  int result[2];
  for (i = 0; i < 5; i++)
    for (j = 0; j < 5; j++)
      scanf("%d", &array[i][j]);
 
  posneg(array, result);
  printf("%d\n", result[0]);
  printf("%d\n", result[1]);
  return 0;
}