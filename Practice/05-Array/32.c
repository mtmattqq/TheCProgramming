#include <stdio.h>

int main(void) {
    int n = 0;
    int a[105];
    while(scanf("%d", a + n) != EOF) {
        n++;
    }

    int idx = 0, begin[10005], end[10005];
    for(int i = 0; i < n; ++i) {
        begin[idx] = i;
        end[idx] = i;
        idx++;
        // 0 1 2 1 0
        int l = i - 1, r = i + 1;
        while(l >= 0 && r < n && a[l] == a[r]) {
            begin[idx] = l;
            end[idx] = r;
            idx++;
            l--; r++;
        }
        // 0 1 1 0
        l = i, r = i + 1;
        while(l >= 0 && r < n && a[l] == a[r]) {
            begin[idx] = l;
            end[idx] = r;
            idx++;
            l--; r++;
        }
    }

#ifdef DEBUG
    for(int i = 0; i < idx; ++i) {
        printf("%d %d\n", begin[i], end[i]);
    }
    printf("\n");
#endif

    int mx_len = 0, mx_begin, mx_end;
    for(int i = 0; i < idx - 1; ++i) {
        for(int j = i + 1; j < idx; ++j) {
            if(
                end[i] + 1 == begin[j] && (
                    end[j] - begin[i] + 1 > mx_len || 
                    (end[j] - begin[i] + 1 == mx_len && end[j] > mx_end)
                )
            ) {
                mx_len = end[j] - begin[i] + 1;
                mx_begin = begin[i];
                mx_end = end[j];
            }
        }
    }

#ifdef DEBUG
    printf("%d\n\n", mx_len);
#endif

    for(int i = mx_begin; i <= mx_end; ++i) {
        printf("%d%c", a[i], " \n"[i == mx_end]);
    }

    return 0;
}