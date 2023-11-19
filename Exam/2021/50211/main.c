#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int ret;
    bool is_valid, is_exp;
} ReturnVal;

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mu(int a, int b) {
    return a * b;
}

int di(int a, int b) {
    return a / b;
}

ReturnVal solve(char *line, int *idx) {
    const static ReturnVal INVALID = {0, 0, 0};
    if(isdigit(line[*idx])) {
        int tp = *idx, num = 0;
        while(isdigit(line[tp])) {
            num = num * 10 + line[tp] - '0';
            tp++;
        }
        (*idx) = tp;

#ifdef DEBUG
        printf("idx = %d\n", *idx);
#endif

        ReturnVal ret = {num, true, false};
        return ret;
    }
    // (1+(2+3))
    const static char operator[] = "+-*/";
    const static int (*operation[4])(int, int) = {
        &add, &sub, &mu, &di
    };

    if(line[*idx] == '(') {
        (*idx)++;
        ReturnVal first = solve(line, idx);
        int a = first.ret;

        char op = line[*idx];
        (*idx)++;
        ReturnVal second = solve(line, idx);
        int b = second.ret;
        char *it = strchr(operator, op);
        if(
            line[*idx] != ')' || 
            it == NULL ||
            first.is_exp != second.is_exp ||
            !first.is_valid ||
            !second.is_valid
        ) {
            return INVALID;
        }
        (*idx)++;

        ReturnVal ret = {operation[it - operator](a, b), 1, 1};
        return ret;
    }

    return INVALID;
}

int main(void) {
    char *line = calloc(1000010, sizeof(char));
    while(scanf("%s", line) == 1) {
        int idx = 0;
        ReturnVal ans = solve(line, &idx);
        if(
            !ans.is_valid || 
            idx != strlen(line) || 
            line[0] != '(' || 
            line[strlen(line) - 1] != ')'
        ) {
            printf("invalid\n");
        } else {
            printf("%d\n", ans.ret);
        }
    }
    return 0;
}