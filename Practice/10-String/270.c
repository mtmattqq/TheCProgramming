#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROGRAM_LINE 1005
#define MAX_LINE_LENGTH 105
#define MAX_VAR_NUM 105
#define MAX_VAR_LEN 15

enum operation{GOTO, IF, ARI, PRINT, STOP};
enum comparator{EQUAL, NOT_EQL, GREATER, LESS, GRE_EQL, LES_EQL};
enum operator{ADD, SUB, MUL, DIV, MOD};

int find_var_idx(char var[MAX_VAR_NUM][MAX_VAR_LEN], int var_idx, char tar[]) {
    for(int i = 0; i < var_idx; ++i) {
        if(strcmp(var[i], tar) == 0) {
            return i;
        }
    }
}

int main(void) {
    char var[MAX_VAR_NUM][MAX_VAR_LEN] = {0};
    int code[MAX_PROGRAM_LINE][MAX_LINE_LENGTH] = {0};

    int var_idx = 0;
    int var_val[MAX_VAR_NUM] = {0};
    char input[MAX_LINE_LENGTH] = {0};
    while(scanf("%s", input) != EOF && strcmp(input, "END") != 0) {
        strcpy(var[var_idx], input);
        scanf("%s", input);
        scanf("%d", &(var_val[var_idx]));
        var_idx++;
    }

    int line_num = 1;
    while(scanf("%s", input) != EOF) {
        if(strcmp(input, "GOTO") == 0) {
            code[line_num][0] = GOTO;
            scanf("%d", &(code[line_num][1]));
        } else if(strcmp(input, "IF") == 0) {
            code[line_num][0] = IF;
            scanf("%s", input);
            code[line_num][1] = find_var_idx(var, var_idx, input);
            scanf("%s", input);
            if(strcmp(input, "==") == 0) {
                code[line_num][2] = EQUAL;
            } else if(strcmp(input, "!=") == 0) {
                code[line_num][2] = NOT_EQL;
            } else if(strcmp(input, ">") == 0) {
                code[line_num][2] = GREATER;
            } else if(strcmp(input, "<") == 0) {
                code[line_num][2] = LESS;
            } else if(strcmp(input, ">=") == 0) {
                code[line_num][2] = GRE_EQL;
            } else { // "<="
                code[line_num][2] = LES_EQL;
            }
            scanf("%s", input);
            code[line_num][3] = find_var_idx(var, var_idx, input);
            scanf("%s", input);
            scanf("%d", &(code[line_num][4]));
        } else if(strcmp(input, "PRINT") == 0) {
            code[line_num][0] = PRINT;
            scanf("%s", input);
            code[line_num][1] = find_var_idx(var, var_idx, input);
        } else if(strcmp(input, "STOP") == 0) {
            code[line_num][0] = STOP;
        } else { // ARI
            code[line_num][0] = ARI;
            code[line_num][1] = find_var_idx(var, var_idx, input);
            scanf("%s", input);
            scanf("%s", input);
            code[line_num][2] = find_var_idx(var, var_idx, input);
            scanf("%s", input);
            if(strcmp(input, "+") == 0) {
                code[line_num][3] = ADD;
            } else if(strcmp(input, "-") == 0) {
                code[line_num][3] = SUB;
            } else if(strcmp(input, "*") == 0) {
                code[line_num][3] = MUL;
            } else if(strcmp(input, "/") == 0) {
                code[line_num][3] = DIV;
            } else { // "%"
                code[line_num][3] = MOD;
            }
            scanf("%s", input);
            code[line_num][4] = find_var_idx(var, var_idx, input);
        }

        line_num++;
    }

// 0 GOTO   1 line
// 0 IF     1 var1  2 comparator    3 var2      4 line
// 0 PRINT  1 var
// 0 STOP
// 0 ARI    1 var1  2 var2          3 operator  4 var3  

    int cur_line = 1;
    while(code[cur_line][0] != STOP) {
        if(code[cur_line][0] == GOTO) {
            cur_line = code[cur_line][1];
            continue;
        } else if(code[cur_line][0] == IF) {
            int var1 = var_val[code[cur_line][1]];
            int var2 = var_val[code[cur_line][3]];
            if(code[cur_line][2] == EQUAL && var1 == var2) {
                cur_line = code[cur_line][4];
                continue;
            } else if(code[cur_line][2] == NOT_EQL && var1 != var2) {
                cur_line = code[cur_line][4];
                continue;
            } else if(code[cur_line][2] == GREATER && var1 > var2) {
                cur_line = code[cur_line][4];
                continue;
            } else if(code[cur_line][2] == LESS && var1 < var2) {
                cur_line = code[cur_line][4];
                continue;
            } else if(code[cur_line][2] == GRE_EQL && var1 >= var2) {
                cur_line = code[cur_line][4];
                continue;
            } else if(code[cur_line][2] == LES_EQL && var1 <= var2) {
                cur_line = code[cur_line][4];
                continue;
            }
        } else if(code[cur_line][0] == PRINT) {
            printf("%d\n", var_val[code[cur_line][1]]);
        } else if(code[cur_line][0] == ARI) {
            int var2 = var_val[code[cur_line][2]];
            int var3 = var_val[code[cur_line][4]];
            if(code[cur_line][3] == ADD) {
                var_val[code[cur_line][1]] = var2 + var3;
            } else if(code[cur_line][3] == SUB) {
                var_val[code[cur_line][1]] = var2 - var3;
            } else if(code[cur_line][3] == MUL) {
                var_val[code[cur_line][1]] = var2 * var3;
            } else if(code[cur_line][3] == DIV) {
                var_val[code[cur_line][1]] = var2 / var3;
            } else if(code[cur_line][3] == MOD) {
                var_val[code[cur_line][1]] = var2 % var3;
            } 
        }
        cur_line++;
    }

    return 0;
}