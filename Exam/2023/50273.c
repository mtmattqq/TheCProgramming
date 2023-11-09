#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define int long long
/*
Thousand	103
Million	106
Billion	109
Trillion	1012
Quadrillion	1015
Quintillion	1018
*/

int print_zero() {
    printf("zero\n");
    exit(0);
}

int decompose(long long n, int ret[], int *idx) {
    ret[*idx] = n % 1000;
    (*idx)++;
    n /= 1000;
    return (n > 0 && decompose(n, ret, idx));
}

int print_hundred(int h) {
    static char oneTo19[30][20] = {
        "zero", 
        "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen",
        "sixteen", "seventeen", "eighteen", "nineteen"
    };
    printf("%s hundred ", oneTo19[h]);
}

int print_ten(int re) {
    char twentyTo90[20][20] = {
        "", "", 
        "twenty", "thirty", "forty", "fifty", 
        "sixty", "seventy", "eighty", "ninety"
    };
    printf("%s", twentyTo90[re / 10]);
    (re % 10 != 0 && printf("-"));
    return re % 10;
}

int print_one(int re) {
    static char oneTo19[30][20] = {
        "zero", 
        "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen",
        "sixteen", "seventeen", "eighteen", "nineteen"
    };
    printf("%s ", oneTo19[re % 10]);
}

int print_remain(int re) {
    static char oneTo19[30][20] = {
        "zero", 
        "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen",
        "sixteen", "seventeen", "eighteen", "nineteen"
    };

    (re < 20 && printf("%s ", oneTo19[re]));
    (re >= 20 && print_ten(re) && print_one(re));
    return 0;
}

int print(int decomposed_num[], int idx) {
    int h = decomposed_num[idx] / 100;
    int re = decomposed_num[idx] % 100;

    char hundredAndAbove[20][20] = {
        "", "thousand", "million", "billion",
        "trillion", "quadrillion", "quintillion"
    };

    (h > 0 && print_hundred(h));
    (re > 0 && print_remain(re));
    (idx > 0 && printf("%s ", hundredAndAbove[idx]));

#ifdef DEBUG
    printf("%d ", decomposed_num[idx]);
#endif

    return (idx > 0 && print(decomposed_num, idx - 1));
}

int32_t main(void) {
    long long n;
    scanf("%lld", &n);

    (n == 0 && print_zero());

    int decomposed_num[10] = {0};
    int idx = 0;

    decompose(n, decomposed_num, &idx);

#ifdef DEBUG
    for(int i = 0; i < idx; ++i) {
        printf("%d", decomposed_num[i]);
    }
    printf("\n");
#endif

    print(decomposed_num, idx - 1);

    return 0;
}