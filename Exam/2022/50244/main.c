#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100

typedef struct {
    int n;
    int info[N][N][N];
    bool is_visit[N][N][N];
} Tower;

typedef struct {
    int depth, row, colume;
} Position;

typedef struct {
    int num, size;
} Component;

Component max(Component a, Component b) {
    if(a.size != b.size) {
        return a.size > b.size ? a : b;
    }
    return a.num > b.num ? a : b;
}

Position add(const Position a, const Position b) {
    Position ret = {a.depth + b.depth, a.row + b.row, a.colume + b.colume};
    return ret;
}

bool is_visit(Tower *tower, Position now) {
    return tower->is_visit[now.depth][now.row][now.colume];
}

void set(Tower *tower, Position now) {
    tower->is_visit[now.depth][now.row][now.colume] = true;
}

bool in(Tower *tower, Position pos) {
    return pos.depth >= 0 && pos.row >= 0 && 
        pos.colume >= 0 && pos.depth < tower->n && 
        pos.row <= pos.depth && pos.colume <= pos.depth;
}

int get(Tower *tower, Position now) {
    return tower->info[now.depth][now.row][now.colume];
}

bool same(Tower *tower, Position a, Position b) {
    return get(tower, a) == get(tower, b);
}

Component find_component(Tower *tower, Position now) {
    const static Component ZERO = {0, 0};
    if(is_visit(tower, now)) {
        return ZERO;
    }
    set(tower, now);

    const static int DIRECTION = 6;
    const static Position delta[] = {
        {-1, 0, 0}, {1, 0, 0}, {0, 0, 1},
        {0, 1, 0}, {0, 0, -1}, {0, -1, 0}
    };
    
    Component ret = {get(tower, now), 1};
    for(int i = 0; i < DIRECTION; ++i) {
        Position next = add(now, delta[i]);
        
        if(
            in(tower, next) && 
            !is_visit(tower, next) && 
            same(tower, now, next)
        ) {
            ret.size += find_component(tower, next).size;
        }
    }

    return ret;
}

int main(void) {
    int n;
    scanf("%d", &n);
    
    Tower tower;
    tower.n = n;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            for(int k = 0; k <= i; ++k) {
                scanf("%d", &(tower.info[i][j][k]));
            }
        }
    }

    Component largest = {0, 0};
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            for(int k = 0; k <= i; ++k) {
                if(!tower.is_visit[i][j][k]) {
                    Position now = {i, j, k};
                    largest = max(largest, find_component(&tower, now));
                }
            }
        }
    }

    printf("%d %d\n", largest.num, largest.size);

    return 0;
}