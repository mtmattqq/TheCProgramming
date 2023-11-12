#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>

typedef struct data {
    char lastname[100];
    char firstname[100];
    char ID[100];
    char salary[100];
    char age[100];
} Data;

const char *get_last(Data *a) {
    return (*a).lastname;
}

const char *get_first(Data *a) {
    return (*a).firstname;
}

const char *get_ID(Data *a) {
    return (*a).ID;
}

const char *get_salary(Data *a) {
    return (*a).salary;
}

const char *get_age(Data *a) {
    return (*a).age;
}


bool str_equal(char s1[], char s2[]) {
    return strcmp(s1, s2) == 0;
}

bool str_nequal(char s1[], char s2[]) {
    return !str_equal(s1, s2);
}

bool int_equal(char a[], char b[]) {
    return atoi(a) == atoi(b);
}

bool int_greater(char a[], char b[]) {
    return atoi(a) > atoi(b);
}

bool int_less(char a[], char b[]) {
    return atoi(a) < atoi(b);
}

int find(const char dict[][100], char tar[100], int n) {
    for(int i = 0; i < n; ++i) {
        if(strcmp(dict[i], tar) == 0) {
            return i;
        }
    }
    return n;
}

int main(void) {

#ifdef DEBUG
    FILE *fo = fopen("debug", "w");
#endif

    int n;
    scanf("%d", &n);

    Data db[100] = {0};
    for(int i = 0; i < n; ++i) {
        int input_num = scanf("%s%s%s%s%s", 
            db[i].lastname, db[i].firstname, db[i].ID,
            db[i].salary, db[i].age
        );
        assert(input_num == 5);
    }

#ifdef DEBUG
    for(int i = 0; i < n; ++i) {
        fprintf(fo, "%s ", db[i].lastname);
        fprintf(fo, "%s ", db[i].firstname);
        fprintf(fo, "%s ", db[i].ID);
        fprintf(fo, "%s ", db[i].salary);
        fprintf(fo, "%s\n", db[i].age);
    }
#endif

    int m;
    scanf("%d", &m);

#ifdef DEBUG
    fprintf(fo, "m = %d\n", m);
    fclose(fo);
#endif 

    static const bool (*cmps[2][4]) (char *, char *) = {
        {&str_equal, &str_nequal},
        {&int_equal, &int_greater, &int_less}
    };

    static const char oops[2][4][100] = {
        {"==", "!=", " "}, {"==", ">", "<", " "}
    };

    static const char* (*dt[5])(Data *) = {
        &get_last, &get_first,
        &get_ID,
        &get_salary, &get_age
    };

    static const char get[][100] = {
        "lastname", "firstname", "ID",
        "salary", "age", " "
    };

    int field_num = 0;
    char tp[100] = {0};
    char field[10][100] = {0};
    int field_inint[10] = {0};
    char var[100] = {0}, op[100] = {0}, constant[100] = {0};
    for(int i = 0; i < m; ++i) {
        field_num = 0;
        scanf("%s", field[field_num]);
        while(
            scanf("%s", field[field_num]) == 1 && 
            strcmp(field[field_num], "where") != 0
        ) {
            field_inint[field_num] = find(get, field[field_num], 5);
            field_num++;
        }
        scanf("%s%s%s", var, op, constant);

#ifdef DEBUG
        fo = fopen("debug", "a");
        for(int k = 0; k < field_num; ++k) {
            fprintf(fo, "%s ", field[k]);
        }
        fprintf(fo, "%s ", var);
        fprintf(fo, "%s ", op);
        fprintf(fo, "%s ", constant);
        fprintf(fo, "\n");

        fclose(fo);
#endif

        for(int didx = 0; didx < n; ++didx) {
            int it = find(get, var, 5);
            int is_num = 1;
            for(int l = 0, len = strlen(constant); l < len; ++l) {
                if(!isdigit(constant[l])) {
                    is_num = 0;
                }
            }

#ifdef DEBUG
            fo = fopen("debug", "a");
            fprintf(fo, "is_num = %d ", is_num);
            fprintf(fo, "find = %d ", find(oops[is_num], op, 2 + is_num));
            fprintf(fo, "%s comp to %s ", dt[it](&db[didx]), constant);
            fprintf(fo, "\n");
            fclose(fo);
#endif

            if(
                cmps[is_num]
                    [find(oops[is_num], op, 2 + is_num)]
                (dt[it](&db[didx]), constant)
            ) {
                for(int j = 0; j < field_num; ++j) {
                    printf("%s ", dt[field_inint[j]](&db[didx]));
                }
                printf("\n");
            }

#ifdef DEBUG
            fo = fopen("debug", "a");
            fprintf(fo, "Successfully deal with didx = %d\n", didx);;
            fclose(fo);
#endif

        }
    }
    return 0;
}