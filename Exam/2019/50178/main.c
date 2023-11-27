#include <stdio.h>
#include <stdbool.h>

#define N 10

void find_longest_cycle(
    int now, int dis,
    int n, bool graph[N][N], bool visit[N], 
    int cur_path[N], int answer[N], int *max_length
) {
    if(now == 0) {
        if(dis > *max_length) {
            (*max_length) = dis;
            for(int i = 0; i < n; ++i) {
                answer[i] = cur_path[i];
            }
        }
        return;
    }

    if(now == -1) {
        now = 0;
    }

    cur_path[dis] = now;
    for(int i = 0; i < n; ++i) {
        if(graph[now][i] && !visit[i]) {
            visit[i] = true;
            find_longest_cycle(
                i, dis + 1, n, graph, visit, 
                cur_path, answer, max_length
            );
            visit[i] = false;
        }
    }
    return;
}

int main(void) {
    int n;
    scanf("%d", &n);

    bool graph[N][N] = {0};
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &(graph[i][j]));
        }
    }

    int max_length = 0;
    bool visit[N] = {0};
    int answer[N] = {0}, cur_path[N] = {0};
    find_longest_cycle(-1, 0, n, graph, visit, cur_path, answer, &max_length);

    for(int i = 1; i < max_length; ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");
    return 0;
}