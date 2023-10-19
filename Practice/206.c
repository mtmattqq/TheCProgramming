#include <stdio.h>
#include <stdlib.h>
void shuffle(int *deck[]);
void print(int *deck[]);

void shuffle(int *deck[]) {
    int n = 0;
    while(deck[n] != NULL) {
        n++;
    }
    int half = (n + 1) / 2;
    int buf[10000];
    for(int i = 0; i < half; ++i) {
        buf[i * 2] = *(deck[i]);
        if(deck[i + half] != NULL) {
            buf[i * 2 + 1] = *(deck[i + half]);
        }
    }
    for(int i = 0; i < n; ++i) {
        *(deck[i]) = buf[i];
    }
    return;
}

void print(int *deck[]) {
    int idx = 0;
    while(deck[idx] != NULL) {
        printf("%d%c", *(deck[idx]), " \n"[deck[idx + 1] == NULL]);
        idx++;
    }
    return;
}
 
int main() {
  int card[10000];
  int *deck[10000];
  int index = 0;
 
  while (scanf("%d", &(card[index])) != EOF) {
    deck[index] = &(card[index]);
    index++;
  }
  deck[index] = NULL;
  shuffle(deck);
  print(deck);  
  return 0;
}