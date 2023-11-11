#include "set.h"
#include <stdio.h>

void init(Set *set) {
    (*set) = 0ULL;
}

void add(Set *set, int i) {
    (*set) ^= (1ULL << i);
}

void has(Set set, int i) {
    if(set & (1ULL << i)) {
        printf("set has %d\n", i);
        return;
    }
    printf("set does not have %d\n", i);
}

Set setUnion(Set a, Set b) {
    return a | b;
}

Set setIntersect(Set a, Set b) {
    return a & b;
}

Set setDifference(Set a, Set b) {
    return a ^ b;
}