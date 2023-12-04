#include <stdlib.h>
#include "subset.h"

int cmp(const void *a, const void *b) {
    Element *ea = (Element *) a;
    Element *eb = (Element *) b;
    if(ea->sum != eb->sum) {
        return ea->sum - eb->sum;
    }
    return ea->sz - eb->sz;
}

void find_subset(int num[], int n, int cur, int choosed, int sum, Element ret[], int *idx, int S) {
    if(cur == n) {
        ret[*idx].sum = sum;
        ret[*idx].sz = choosed;
        (*idx)++;
        return;
    }

    if(choosed > S) {
        return;
    }
    
    find_subset(num, n, cur + 1, choosed + 1, sum + num[cur], ret, idx, S);
    find_subset(num, n, cur + 1, choosed, sum, ret, idx, S);
}

int subset(int numbers[], int n, int K, int S) {
    Element s1[N] = {0}, s2[N] = {0};
    int mid = n >> 1;
    int idx1 = 0, idx2 = 0;
    find_subset(numbers, mid, 0, 0, 0, s1, &idx1, S);
    find_subset(numbers, n, mid, 0, 0, s2, &idx2, S);
    
    qsort(s1, idx1, sizeof(Element), cmp);
    qsort(s2, idx2, sizeof(Element), cmp);

    for(int i = 0; i < idx1; ++i) {
        if(s1[i].sum == K && s1[i].sz == S) {
            return 1;
        }
    }

    for(int i = 0; i < idx2; ++i) {
        if(s2[i].sum == K && s2[i].sz == S) {
            return 1;
        }
    }

    for(int i = 0; i < idx1; ++i) {
        int l = 0, r = idx2;
        while(r - l > 1) {
            int mid = l + r >> 1;
            if(s2[mid].sum + s1[i].sum < K) {
                l = mid;
            } else {
                r = mid;
            }
        }

        for(int j = r; j < idx2 && s1[i].sum + s2[j].sum == K; ++j) {
            if(s1[i].sz + s2[j].sz == S) {
                return 1;
            }
        }
    }
    return 0;
}