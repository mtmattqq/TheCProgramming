#include <stdio.h>
#include <assert.h>
// #include "myint.h"
 
int madd(int a, int b) {
    return a + b;
}
int msub(int a, int b) {
    return a - b; 
}

#ifndef MYINT_H
#define MYINT_H
 
int getmyheart(int (*FUNC[])(int, int));
// static int madd(int a, int b);
// static int msub(int a, int b);
#endif

#include <stdio.h>
#include <assert.h>
// #include "myint.h"
 
static void test_heart() {
    printf("run test heart\n");
    // Morris' secret block, don't care about this.
}
 
static void secret() {
     // Morris' secret block, don't care about this.
}

// #include "myint.h"
// #include "singletest.c"
 
static int madd(int a, int b) {
    return a + b;
}
static int msub(int a, int b) {
    return a - b;
}
int getmyheart(int (*FUNC[])(int, int)) {
    secret();
    test_heart();
    FUNC[0] = madd;
    FUNC[1] = msub;
    return 2;
}
 
int main() {
    int (*FUNC[8])(int, int);
    int ret = getmyheart(FUNC);
    int a, b;
    scanf("%d %d", &a, &b);
    printf("#function = %d\n", ret);
 
    printf("test function add\n");
    assert(FUNC[0](a, b) == madd(a, b));
    printf("test function sub\n");
    assert(FUNC[1](a, b) == msub(a, b));
 
    return 0;
}