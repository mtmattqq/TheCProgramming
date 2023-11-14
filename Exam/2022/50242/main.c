#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 2005
#define MAX_TOK_NUM 505

typedef struct {
    int tok_num;
    char *toks[MAX_TOK_NUM];
} Expression;



int decode(Expression exp, int *idx) {
    if(*idx >= exp.tok_num) {
        return 2;
    }

    if(strcmp(exp.toks[*idx], "true") == 0) {
        return 1;
    }

    if(strcmp(exp.toks[*idx], "false") == 0) {
        return 0;
    }

    if(strcmp(exp.toks[*idx], "!") == 0) {
        (*idx)++;
        int ret = decode(exp, idx);
        return ret == 2 ? 2 : !ret;
    }

    if(strcmp(exp.toks[*idx], "(") == 0) {
        int ret[2] = {0};
        (*idx)++;
        ret[0] = decode(exp, idx);
        
        (*idx)++;
        if(*idx >= exp.tok_num) {
            return 2;
        }
        char *op_now = exp.toks[*idx];

        (*idx)++;
        ret[1] = decode(exp, idx);

        (*idx)++;
        if(*idx >= exp.tok_num || strcmp(exp.toks[*idx], ")") != 0) {
            return 2;
        }
        

        if(strcmp(op_now, "&&") == 0) {
            return (ret[0] == 2 || ret[1] == 2) ? 
                2 : ret[0] && ret[1];
        } else if(strcmp(op_now, "||") == 0) {
            return (ret[0] == 2 || ret[1] == 2) ? 
                2 : ret[0] || ret[1];
        }
    }

    return 2;
}

int main(void) {
    const char output[][10] = {"false", "true", "invalid"};
    char line[MAX_LINE_LENGTH] = {0};
    while(fgets(line, 2005, stdin) != NULL) {
        char *cur;
        Expression exp = {0, {0}};
        cur = strtok(line, " \n");
        while(cur != NULL) {
            exp.toks[exp.tok_num++] = cur;
            cur = strtok(NULL, " \n");
        }
        
        int idx = 0;
        int ret = decode(exp, &idx);
        if(idx != exp.tok_num - 1) 
            ret = 2;
        printf("%s\n", output[ret]);
    }
    return 0;
}