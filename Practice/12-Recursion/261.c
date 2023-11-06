#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define N 10

void insert(int *sz, char set[], char val) {
    if(isdigit(val)){
        return;
    }

    for(int i = 0; i < *sz; ++i) {
        if(set[i] == val) {
            return;
        }
    }
    set[*sz] = val;
    (*sz)++;
}

void insert_string(int *sz, char set[], char val[]) {
    int len = strlen(val);
    for(int i = 0; i < len; ++i) {
        insert(sz, set, val[i]);
    }
}

int find(char str[], char tar) {
    int len = strlen(str);
    for(int i = 0; i < len; ++i) {
        if(str[i] == tar) {
            return i;
        }
    }
    return len;
}

int convert(char str[], char set[], int s[]) {
    int ret = 0, len = strlen(str);
    for(int i = 0; i < len; ++i) {
        if(isdigit(str[i])) {
            ret = ret * 10 + (str[i] - '0');
        } else {
            ret = ret * 10 + s[find(set, str[i])];
        }
    }
    return ret;
}

void print(char str[], char set[], int s[]) {
    int len = strlen(str);
    for(int i = 0; i < len; ++i) {
        if(isdigit(str[i])) {
            printf("%c", str[i]);
        } else {
            printf("%c", s[find(set, str[i])] + '0');
        }
        
    }
}

bool find_solution(
    int n, int sz, 
    char n1[], char n2[], 
    char ans[],
    char set[], int s[]
) {
    if(n == sz) {
        int num1 = convert(n1, set, s), num2 = convert(n2, set, s);
        int an = convert(ans, set, s);

        if(num1 * num2 == an) {
            print(n1, set, s);
            printf(" x ");
            print(n2, set, s);
            printf(" = ");
            print(ans, set, s);
            printf("\n");
            return true;
        }
        return false;
    }

    for(int i = 0; i < N; ++i) {
        s[n] = i;
        if(find_solution(n + 1, sz, n1, n2, ans, set, s)) {
            return true;
        }
    }
    return false;
}

int main(void) {
    char n1[N] = {0}, n2[N] = {0}, ans[N] = {0};
    scanf("%s%s%s", n1, n2, ans);
    int sz_s = 0;
    char set[N * 3] = {0};
    insert_string(&sz_s, set, n1);
    insert_string(&sz_s, set, n2);
    insert_string(&sz_s, set, ans);
    
    int s[N * 3] = {0};
    find_solution(0, sz_s, n1, n2, ans, set, s);
    return 0;
}