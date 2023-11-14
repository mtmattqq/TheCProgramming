#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_FRIEND 64

typedef struct {
    int num;
    uint64_t s;
} Selected;

void set(uint64_t *s, int p) {
    (*s) |= 1ULL << p;
}

void print_selected(Selected s, int n) {
    for(int i = 0; i < n; ++i) {
        if(s.s & (1ULL << i)) {
            printf("%d\n", i);
        }
    }
}

bool is_covered(uint64_t friends[], int n, Selected sel) {
    for(int i = 0; i < n; ++i) {
        if(sel.s & (1ULL << i)) {
            continue;
        }

        if(friends[i] & ~(sel.s)) {
            return false;
        }
    }
    return true;
}

Selected find_min_cover(uint64_t friends[], int idx, int n, Selected sel, uint64_t hasfriend) {
    if(is_covered(friends, n, sel)) {
        return sel;
    }

    if(idx == n) {
        Selected not_found = {INT32_MAX, 0};
        return not_found;
    }

    if((hasfriend & (1ULL << idx)) == 0) {
        return find_min_cover(friends, idx + 1, n, sel, hasfriend);
    }

    Selected choose_this_one = {sel.num + 1, sel.s | (1ULL << idx)};
    choose_this_one = find_min_cover(friends, idx + 1, n, choose_this_one, hasfriend);

    Selected dont_choose_this = sel;
    dont_choose_this = find_min_cover(friends, idx + 1, n, dont_choose_this, hasfriend);

    return (dont_choose_this.num < choose_this_one.num) ? 
        dont_choose_this : choose_this_one;
}

int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);

    uint64_t friends[MAX_FRIEND] = {0ULL}, hasfriend = 0;
    for(int i = 0; i < m; ++i) {
        int f, t;
        scanf("%d%d", &f, &t);
        set(&(friends[f]), t);
        set(&(friends[t]), f);
        set(&hasfriend, f);
        set(&hasfriend, t);
    }

    Selected select_nothing = {0, 0};
    Selected ans = find_min_cover(friends, 0, n, select_nothing, hasfriend);
    print_selected(ans, n);
}