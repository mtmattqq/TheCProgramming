#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define N 55
#define LEN 15

int find_dis(char s1[], char s2[], int l) {
    int ret = 0;
    for(int i = 0; i < l; ++i) {
        ret += abs(s1[i] - s2[i]);
    }
    return ret;
}

void swap(char s1[], char s2[]) {
    char tp[LEN] = {0};
    strcpy(tp, s1);
    strcpy(s1, s2);
    strcpy(s2, tp);
}

void seperate_group(
    int n, int l, 
    char info[N][LEN], 
    char group[3][N][LEN], int group_idx[3]
) {
    for(int i = 0; i < n; ++i) {
        int mn = INT_MAX, mn_idx = 0;
        for(int j = 0; j < 3; ++j) {
            int dis = find_dis(info[i], info[j], l);
            if(dis < mn || (dis == mn && strcmp(info[j], info[mn_idx]) < 0)) {
                mn = dis;
                mn_idx = j;
            }
        }

        strcpy(group[mn_idx][group_idx[mn_idx]], info[i]);
        group_idx[mn_idx]++;
    }
}

void find_mean_value(
    int l, 
    int sum[3][LEN], char mean[3][LEN],
    char group[3][N][LEN], int group_idx[3]
) {
    
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < group_idx[i]; ++j) {
            for(int k = 0; k < l; ++k) {
                sum[i][k] += group[i][j][k];
            }
        }

        for(int k = 0; k < l; ++k) {
            mean[i][k] = sum[i][k] / group_idx[i];
        }
        mean[i][l] = '\0';
    }
}

void assign_leader(
    int l, 
    char group[3][N][LEN], int group_idx[3],
    char mean[3][LEN]
) {
    for(int i = 0; i < 3; ++i) {
        int mn = INT_MAX, mn_idx = 0;
        for(int j = 0; j < group_idx[i]; ++j) {
            int dis = find_dis(mean[i], group[i][j], l);
            if(dis < mn || (dis == mn && strcmp(group[i][j], group[i][mn_idx]) < 0)) {
                mn = dis;
                mn_idx = j;
            }
        }
        swap(group[i][mn_idx], group[i][0]);
    }
}

void fill_back(char info[N][LEN], char group[3][N][LEN], int group_idx[3]) {
    int idx = 3;
    strcpy(info[0], group[0][0]);
    strcpy(info[1], group[1][0]);
    strcpy(info[2], group[2][0]);
    
    for(int i = 0; i < 3; ++i) {
        for(int j = 1; j < group_idx[i]; ++j) {
            strcpy(info[idx], group[i][j]);
            idx++;
        }
    }
}

void simulate_round(int n, int l, char info[N][LEN]) {
    char group[3][N][LEN] = {0};
    int group_idx[3] = {0};

    seperate_group(n, l, info, group, group_idx);

    int sum[3][LEN] = {0};
    char mean[3][LEN] = {0};

    find_mean_value(l, sum, mean, group, group_idx);

    assign_leader(l, group, group_idx, mean);

    fill_back(info, group, group_idx);
}

int main(void) {
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    char info[N][LEN] = {0};

    for(int i = 0; i < n; ++i) {
        scanf("%s", info[i]);
    }

    for(int i = 0; i < r; ++i) {
        simulate_round(n, l, info);
    }

    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 2; ++j) {
            if(strcmp(info[j], info[j + 1]) > 0) {
                swap(info[j], info[j + 1]);
            }
        }
    }

    for(int i = 0; i < 3; ++i) {
        printf("%s\n", info[i]);
    }
    return 0;
}