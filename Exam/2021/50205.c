#include <stdio.h>
#include <string.h>

#define N 100010

int find(char str[], int len, char tar) {
    for(int i = 0; i < len; ++i) {
        if(str[i] == tar) {
            return i;
        }
    }
    return len;
}

int add(int a, int b) {
    return a + b;
}

int mul(int a, int b) {
    return a * b;
}

int main(void) {
    char to_num[10] = ")!@#$%^& (";
    const int len = strlen(to_num);
    int pri[300] = {0};
    memset(pri, -1, sizeof(int) * 300);
    pri['+'] = 0;
    pri['*'] = 1;
    
    int st_idx = -1;
    int stack[N] = {0};
    char operator[N] = {0};

    char input;
    int num = 0;
    int (*operations[2])(int, int) = {&add, &mul};
    while((input = getchar()) != EOF) {
        int it = find(to_num, len, input);
        if(it == len) {
            while(st_idx >= 0 && pri[operator[st_idx]] >= pri[input]) {
                num = operations[pri[operator[st_idx]]](
                    stack[st_idx], num
                );
                st_idx--;
            }

            st_idx++;
            stack[st_idx] = num;
            operator[st_idx] = input;
            num = 0;
        } else {
            num = num * 10 + it;
        }
    }
    st_idx++;
    stack[st_idx] = num;
    operator[st_idx] = ' ';

    int sum = stack[st_idx];
    for(int i = st_idx - 1; i >= 0; --i) {
        sum = operations[pri[operator[i]]](sum, stack[i]);
    }

    printf("%d\n", sum);
    
    return 0;
}