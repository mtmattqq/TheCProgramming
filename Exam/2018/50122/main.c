#include <stdio.h>
#include <stdbool.h>

#define N 105

typedef struct {
    int r, c;
} Position;

typedef struct {
    int step;
    Position pos;
    bool can_move;
} Knight;

typedef struct {
    int id, step;
    bool visit;
} Block;

bool in(Position pos, int n) {
    return pos.r >= 0 && pos.c >= 0 && pos.r < n && pos.c < n;
}

Position add(Position a, Position b) {
    Position ret = {a.r + b.r, a.c + b.c};
    return ret;
}

Block *get(Block board[N][N], Position pos) {
    return &(board[pos.r][pos.c]);
}

int count_available_move(Block board[N][N], Position pos, int n, Position delta[]) {
    int ret = 0;
    for(int k = 1; k <= 8; ++k) {
        Position option = add(pos, delta[k]);
        if(in(option, n) && !get(board, option)->visit) {
            ret++;
        }
    }
    return ret;
}

bool find_next_move(Knight *now, Block board[N][N], int n, int id) {
    Position delta[] = {
        {}, 
        {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, 
        {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
    };
    
    Position next = {-1, -1};
    for(int k = 1; k <= 8; ++k) {
        Position option = add(now->pos, delta[k]);
        if(in(option, n) && !get(board, option)->visit && 
            (next.r == -1 || 
                count_available_move(board, option, n, delta) < 
                count_available_move(board, next, n, delta)
            )
        ) {
            next = option;
        }
    }
    now->pos = next;
    now->can_move = next.r != -1;
    now->step++;

    if(!now->can_move) {
        return false;
    }

    get(board, now->pos)->id = id;
    get(board, now->pos)->step = now->step;
    get(board, now->pos)->visit = true;
    return true;
}

int main(void) {
    Block board[N][N] = {0};

    int n, m;
    scanf("%d%d", &n, &m);
    
    Knight knight[N * N] = {0};
    for(int i = 1; i <= m; ++i) {
        knight[i].can_move = true;
        knight[i].step = 0;
        scanf("%d%d", &(knight[i].pos.r), &(knight[i].pos.c));
        get(board, knight[i].pos)->visit = true;
        get(board, knight[i].pos)->step = 0;
        get(board, knight[i].pos)->id = i;
    }

    bool in_loop = true;
    while(in_loop) {
        in_loop = false;
        for(int i = 1; i <= m; ++i) {
            if(!knight[i].can_move) {
                continue;
            }

            in_loop |= find_next_move(&knight[i], board, n, i);
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            Position now = {i, j};
            printf("%d%c", 
                get(board, now)->id * 10000 + get(board, now)->step, 
                " \n"[j == n - 1]
            );
        }
    }
    
    return 0;
}