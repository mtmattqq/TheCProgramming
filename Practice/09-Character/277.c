#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//    <--w-->
// ^   0000  
// |  1    2
// |  1    2
// |  1    2
// h   3333
// |  4    5
// |  4    5
// |  4    5
// ^   6666

// 0 : 0 1 2 4 5 6
// 1 : 2 5
// 2 : 0 2 3 4 6
// 3 : 0 2 3 5 6
// 4 : 1 2 3 5
// 5 : 0 1 3 5 6
// 6 : 0 1 3 4 5 6
// 7 : 0 1 2 5
// 8 : 0 1 2 3 4 5 6
// 9 : 0 1 2 3 5

const int number[10][10] = {
    {0, 1, 2, 4, 5, 6, -1},
    {2, 5, -1},
    {0, 2, 3, 4, 6, -1},
    {0, 2, 3, 5, 6, -1},
    {1, 2, 3, 5, -1},
    {0, 1, 3, 5, 6, -1},
    {0, 1, 3, 4, 5, 6, -1},
    {0, 1, 2, 5, -1},
    {0, 1, 2, 3, 4, 5, 6, -1},
    {0, 1, 2, 3, 5, -1}
};

void print_line(char display[15][105], int col, int w, int h, int id, int n) {
    switch(id) {
      case 0 :
        for(int i = 1; i < w - 2; ++i) {
            display[0][col * w + i] = n + '0';
        }
        break;
      case 1 :
        for(int i = 1; i < h / 2; ++i) {
            display[i][col * w] = n + '0';
        }
        break;
      case 2 :
        for(int i = 1; i < h / 2; ++i) {
            display[i][col * w + w - 2] = n + '0';
        }
        break;
      case 3 :
        for(int i = 1; i < w - 2; ++i) {
            display[h / 2][col * w + i] = n + '0';
        }
        break;
      case 4 :
        for(int i = 1; i < h / 2; ++i) {
            display[i + h / 2][col * w] = n + '0';
        }
        break;
      case 5 :
        for(int i = 1; i < h / 2; ++i) {
            display[i + h / 2][col * w + w - 2] = n + '0';
        }
        break;
      case 6 :
        for(int i = 1; i < w - 2; ++i) {
            display[h - 1][col * w + i] = n + '0';
        }
        break;
    }
}

void print_number(char display[15][105], int col, int w, int h, int n) {
    for(int i = 0; number[n][i] >= 0; ++i) {
        print_line(display, col, w, h, number[n][i], n);
    }
}

int main(void) {
    char s[15];
    int w, h;
    while(scanf("%s%d%d", s, &w, &h) != EOF) {
        char display[15][105] = {1};
        for(int i = 0; i < 15 * 105; ++i) {
            display[i / 105][i % 105] = ' ';
        }
        int len = strlen(s);
        for(int i = 0; i < len; ++i){
            print_number(display, i, w, h, s[i] - '0');
        }

        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w * len; ++j) {
                printf("%c", display[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}