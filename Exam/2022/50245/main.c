#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8

typedef struct {
    int left, top, right, buttom;
    bool is_selected;
} Box;

typedef struct {
    int n;
    int box[N][N];
} Matrix;

typedef struct {
    int r, c;
} Position;

bool finished(Matrix *mat, Position now) {
    return now.r == mat->n;
}

int get(Matrix *mat, Position now) {
    return mat->box[now.r][now.c];
}

int set(Matrix *mat, Position now, int val) {
    mat->box[now.r][now.c] = val;
}

/*
        1           1
    0       2   0       2
        1           1
*/

bool conflict(Box boxes[], Matrix *mat, Position now) {
    bool ret = false;
    if(now.r > 0) {
        Position t = {now.r - 1, now.c};
        ret |= boxes[get(mat, t)].buttom != boxes[get(mat, now)].top;
    }

    if(now.c > 0) {
        Position t = {now.r, now.c - 1};
        ret |= boxes[get(mat, t)].right != boxes[get(mat, now)].left;
    }

    return ret;
}

Position next(Matrix *mat, Position now) {
    now.c = (now.c + 1) % mat->n;
    now.r += now.c == 0;
    return now;
}

bool place_boxes(Box boxes[], Matrix *mat, Position now) { 
    if(finished(mat, now)) {
        for(int i = 0; i < mat->n; ++i) {
            for(int j = 0; j < mat->n; ++j) {
                printf("%d ", mat->box[i][j]);
            }
            printf("\n");
        }
        return true;
    }

    for(int i = 0; i < mat->n * mat->n; ++i) {
        if(!boxes[i].is_selected) {
            set(mat, now, i);
            if(conflict(boxes, mat, now)) {
                continue;
            }

            boxes[i].is_selected = true;
            if(place_boxes(boxes, mat, next(mat, now))) {
                return true;
            }
            boxes[i].is_selected = false;
        }
    }
    return false;
}

void solve(int n) {
    Box boxes[N * N] = {0};
    for(int i = 0; i < n * n; ++i) {
        scanf("%d", &(boxes[i].left));
        scanf("%d", &(boxes[i].top));
        scanf("%d", &(boxes[i].right));
        scanf("%d", &(boxes[i].buttom));
    }

    Position origin = {0, 0};
    Matrix mat = {0};
    mat.n = n;
    if(!place_boxes(boxes, &mat, origin)) {
        printf("no solution\n");
    }
    return;
}

int main(void) {
    int n;
    while(scanf("%d", &n) == 1) {
        solve(n);
    }
    return 0;
}