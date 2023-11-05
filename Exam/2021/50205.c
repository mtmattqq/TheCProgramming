#include <stdio.h>
#include <string.h>

int find(char str[], int len, char tar) {
    for(int i = 0; i < len; ++i) {
        if(str[i] == tar) {
            return i;
        }
    }
    return len;
}

int main(void) {
    const char *to_num = "!@#$%^&()";
    const int len = strlen(to_num);
    int pri[300] = {0};
    pri['+'] = 1;
    pri['*'] = 2;
    
    int stack[10005] = {0};
    char opertor[10005] = {0};

    char input;
    while(scanf("%c", input) == 1) {
        if(find(to_num, len, input) == len) {
            // This is an operator
        } else {
            // This is a number
        }
    }
    return 0;
}