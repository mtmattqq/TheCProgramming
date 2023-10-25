#include <stdio.h>
#include <assert.h>
 
void snake(const int *ptr_array[100][100], int m);

void snake(const int *ptr_array[100][100], int m) {
    for(int i = 0; i < m * m; ++i) {
        for(int j = 0; j < m * m; ++j) {
            int r1 = i / m;
            int c1 = (r1&1) ? (m - i%m - 1) : (i%m);
            int r2 = j / m;
            int c2 = (r2&1) ? (m - j%m - 1) : (j%m);

#ifdef DEBUG
            printf("%d %d %d %d\n", r1, c1, r2, c2);
            // printf("%d %d\n", *(ptr_array[r1][c1]), *(ptr_array[r2][c2]));
#endif
        
            if(*(ptr_array[r1][c1]) < *(ptr_array[r2][c2])) {
                int *t = ptr_array[r1][c1];
                ptr_array[r1][c1] = ptr_array[r2][c2];
                ptr_array[r2][c2] = t;
            }
        }
    }
}

int main(){
  int array[100][100], check[100][100];
  const int *ptr_array[100][100];
  int i, j, m;
 
  scanf("%d", &m);
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++) {
      ptr_array[i][j] = &(array[i][j]);
      scanf("%d", &(array[i][j]));
      check[i][j] = array[i][j];
    }
 
  snake(ptr_array, m);
 
  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
      assert(check[i][j] == array[i][j]);
      assert((ptr_array[i][j] >= &array[0][0]) && (ptr_array[i][j] <= &array[99][99]));
      printf("%d ", *(ptr_array[i][j]));
    }
    printf("\n");
  }
 
  return 0;
}