#include <stdio.h>
#include <stdint.h>
#include <string.h>

// #define DEBUG

int find_chr(char s[], char tar) {
    int len = strlen(s);
    for(int i = 0; i < len; ++i) {
        if(s[i] == tar) {
            return i + 1;
        }
    }
    return len + 1;
}

int max(int a, int b) {
    return (a > b) * a + (a <= b) * b;
}

int isfind(char a[], char b[], char tar) {
    return 
        find_chr(a, tar) != strlen(a) + 1 &&
        find_chr(b, tar) != strlen(b) + 1;
}

int LCS(char s1[], char s2[], char s3[]) {
    if(s1[0] == '\0' || s2[0] == '\0' || s3[0] == '\0') {
        return 0;
    }

#ifdef DEBUG
    printf("s1 = \"%s\"\n", s1);
    printf("s2 = \"%s\"\n", s2);
    printf("s3 = \"%s\"\n\n", s3);
#endif

    if(s1[0] == s2[0] && s2[0] == s3[0]) {
        return LCS(s1 + 1, s2 + 1, s3 + 1) + 1;
    }

    int a[3] = {0};
    
    if(isfind(s2, s3, s1[0])) {
        a[0] = LCS(
            s1 + 1, 
            s2 + find_chr(s2, s1[0]), 
            s3 + find_chr(s3, s1[0])
        ) + 1;
    }
    
    if(isfind(s1, s3, s2[0])) {
        a[1] = LCS(
            s1 + find_chr(s1, s2[0]), 
            s2 + 1, 
            s3 + find_chr(s3, s2[0])
        ) + 1;
    }

    if(isfind(s1, s2, s3[0])) {
        a[2] = LCS(
            s1 + find_chr(s1, s3[0]), 
            s2 + find_chr(s2, s3[0]), 
            s3 + 1
        ) + 1;
    }

    int dont_choose = LCS(s1 + 1, s2 + 1, s3 + 1);
    return max(max(a[0], max(a[1], a[2])), dont_choose);
}

int main(void) {

#ifdef DEBUG
    char *t = "123456789";
    printf("find chr \'5\' in \"123456789\" = %d\n", find_chr(t, '5'));
#endif

    char str[3][100] = {0};
    while(scanf("%s%s%s", str[0], str[1], str[2]) == 3) {
        printf("%d\n", LCS(str[0], str[1], str[2]));
    }
    return 0;
}