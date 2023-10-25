#include <stdio.h>
#include <stdbool.h>
int hasEOF = 0;

int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;    
        }
        p = buf;
    }
    return *p++;
}

int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}

int get(unsigned long long s, int n) {
    return (s & (255ULL << (n << 3))) >> (n << 3);
}

int main() {
    int x;
    unsigned long long book_shelf = 0;
    unsigned long long pre, nex, tp;
    while (ReadInt(&x)) {

#ifdef DEBUG
        printf("x = %d\n", x);
#endif

        bool isf = false;
        int idx = 0;
        for(int i = 7; i >= 0; --i) {
            if(get(book_shelf, i) == x) {
                isf = true;
                idx = i;
                break;
            }
        }

        if(!isf) {
            book_shelf <<= 8;
            book_shelf += x;
        } else {
            tp = get(book_shelf, idx);

#ifdef DEBUG
            printf("find x in %d, which is %d\n", idx, tp);
#endif

            if(idx == 7) {
                pre = 0ULL;
            } else {
                pre = book_shelf >> ((idx + 1ULL) << 3ULL);
            }
            
#ifdef DEBUG
            printf("The element in pre : \n");
            for(int i = 7; i >= 0; --i) {
                printf("%d ", get(pre, i));
            }
            printf("end\n");
#endif

            nex = book_shelf & ((1ULL << (idx << 3ULL)) - 1ULL);

#ifdef DEBUG
            printf("The element in nex : \n");
            for(int i = 7; i >= 0; --i) {
                printf("%d ", get(nex, i));
            }
            printf("end\n");
#endif

            book_shelf = (pre << ((idx + 1ULL) << 3ULL)) + (nex << 8ULL) + tp;
        }

#ifdef DEBUG
        for(int i = 7; i >= 0; --i) {
            printf("%d ", get(book_shelf, i));
        }
        printf("\n");
#endif

    }    
    
    for(int i = 7; i >= 0; --i) {
        printf("%d ", get(book_shelf, i));
    }
    return 0;
}