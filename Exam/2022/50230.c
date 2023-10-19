#include <stdio.h>
#include <stdbool.h>

int f(int k, int s) {
    return (77 * k + 2222) % s;
}

int ht[100010][15] = {0};

int main(void) {
    int s, c;
    scanf("%d%d", &s, &c);
    
    int k;
    
    while(scanf("%d", &k) != EOF) {
        int p = f(k, s);
        bool is_find = false;
        for(int i = 0; i <= c; ++i) {
            if(ht[p][i] == k) {
                ht[p][i] = 0;
                printf("%d %d\n", k, p);
                is_find = true;
            }
        }

        if(!is_find) {
            for(int i = 0; i <= c; ++i) {
                if(ht[p][i] == 0) {
                    ht[p][i] = k;
                    break;
                }
            }
        }
    }
    return 0;
}