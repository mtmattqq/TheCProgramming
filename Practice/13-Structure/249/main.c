#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int id, hash;
    char first_name[100];
    char last_name[32];
    int boss_id[8];
} Employee;

int hash(char first_name[], char last_name[]) {
    strcat(first_name, last_name);
    int len = strlen(first_name);
    const static long long N = 29, MOD = 1e9 + 7;
    long long ret = 0;
    for(int i = 0; i < len; ++i) {
        ret = (ret * N + first_name[i]) % MOD;
    }
    return (int) (ret % MOD);
}

void build(Employee employee[], int n) {
    for(int i = 1; i <= 7; ++i) {
        for(int j = 0; j < n; ++j) {
            employee[j].boss_id[i] = employee[employee[j].boss_id[i - 1]].boss_id[i - 1];
        }
    }
}

int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int employee_cmp(const void *a, const void *b) {
    Employee *ea = (Employee *) a;
    Employee *eb = (Employee *) b;
    return ea->id - eb->id;
}

int search(int a[], int n, int tar) {
    int l = 0, r = n;
    while(r - l > 1) {
        int mid = l + r >> 1;
        if(a[mid] <= tar) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int find(Employee a[], int n, int tar) {
    for(int i = 0; i < n; ++i) {
        if(a[i].hash == tar) {
            return i;
        }
    }
    return n;
}

int LCA(Employee employee[], int ita, int itb) {
    int tp = ita;
    while(tp != itb && tp != employee[tp].boss_id[0]) {
        tp = employee[tp].boss_id[0];
    }
    if(tp == itb) {
        return tp;
    }

    tp = itb;
    while(tp != ita && tp != employee[tp].boss_id[0]) {
        tp = employee[tp].boss_id[0];
    }
    return tp;
}

int main(void) {
    int n;
    scanf("%d", &n);
    Employee employee[320] = {0};
    int id_of_them[64] = {0}, id_idx = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d%s%s%d", 
            &(employee[i].id), employee[i].first_name, 
            employee[i].last_name, &(employee[i].boss_id[0])
        );

        employee[i].hash = hash(employee[i].first_name, employee[i].last_name);
        
        bool exist = false;
        for(int j = 0; j < id_idx; ++j) {
            if(id_of_them[j] == employee[i].id) {
                exist = true;
            }
        }

        if(!exist) {
            id_of_them[id_idx] = employee[i].id;
            id_idx++;
        }
    }

    qsort(id_of_them, id_idx, sizeof(int), cmp);

    for(int i = 0; i < n; ++i) {
        employee[i].id = search(id_of_them, id_idx, employee[i].id);
        employee[i].boss_id[0] = 
            search(id_of_them, id_idx, employee[i].boss_id[0]);
    }

    qsort(employee, n, sizeof(Employee), employee_cmp);

    build(employee, n);

    int m;
    scanf("%d", &m);
    Employee a, b;
    for(int i = 0; i < m; ++i) {
        scanf("%s%s%s%s", 
            a.first_name, a.last_name,
            b.first_name, b.last_name
        );
        a.hash = hash(a.first_name, a.last_name);
        b.hash = hash(b.first_name, b.last_name);
        int ita = find(employee, n, a.hash);
        int itb = find(employee, n, b.hash);
        
        if(employee[ita].boss_id[7] != employee[itb].boss_id[7]) {
            printf("unrelated\n");
            continue;
        }

        int lca = LCA(employee, ita, itb);
        if(lca == ita) {
            printf("supervisor\n");
            continue;
        }

        if(lca == itb) {
            printf("subordinate\n");
            continue;
        }

        printf("colleague\n");
    }
}