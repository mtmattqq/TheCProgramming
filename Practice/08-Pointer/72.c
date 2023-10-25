#include <stdio.h>

void fill_array(int *ptr[], int n);

void fill_array(int *ptr[], int n) {
    int *front = ptr[0];
    int *end = ptr[n - 1];
    for(int *i = front; i != end; ++i) {
        *i = -1;
    }

    for(int i = 0; i < n; ++i) {
        *(ptr[i]) = i;
    }

    int len = end - front;

#ifdef DEBUG
    printf("%d\n", len);
#endif

    int *left = front;
    for(int *i = front + 1; i - front < len; ++i) {
        int *t = i;
        while(t - front < len && *t < 0) {
            t++;
        }

        for(int *j = i; j != t; ++j) {
            *j = *left + *t;
        }
        left = t;
        i = t;
    }
    
    return;
}

int main() {
    int arr[100] = {};
    int *ptr[100];
    int n = 6, m = 0;
    int A[100] = {0, 5, 6, 9, 3, 12};
    for (int i = 0; i < n; i++) {
        ptr[i] = &arr[A[i]];
        if (A[i] > m) m = A[i];
    }
    fill_array(ptr, n);
    for (int i = 0; i <= m; i++)
        printf("%d%c", arr[i], " \n"[i==m]);
    return 0;
}