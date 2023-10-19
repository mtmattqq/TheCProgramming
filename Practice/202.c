#include <stdio.h>

enum {ADD, SUB, MUL, DIV};

typedef struct frac {
    int a, b, c;
    // repersent 
    //      b  
    // a + ---
    //      c
} Frac;

void simplify(Frac*);
void transform(Frac*);
Frac operate(Frac, Frac, int);
Frac add(Frac, Frac);
Frac sub(Frac, Frac);
Frac mul(Frac, Frac);
Frac div(Frac, Frac);
int abs(int);
int gcd(int, int);
int lcm(int, int);


int main(void) {
    Frac a, b;
    scanf("%d%d%d", &(a.a), &(a.b), &(a.c));
    int op;
    scanf("%d", &op);
    scanf("%d%d%d", &(b.a), &(b.b), &(b.c));

    Frac ans = operate(a, b, op);
    printf("%d\n%d\n%d\n", ans.a, ans.b, ans.c);
    return 0;
}

int abs(int a) {
    return a < 0  ?  -a  :  a;
}

int gcd(int a, int b) {
    return a % b == 0  ?  b  :  gcd(b, a % b);
}

int lcm(int a, int b) {
    int g = gcd(a, b);
    // simplified version from (a / g) * (b / g) * g
    return a * b / g;
}

void simplify(Frac *f) {
    int g = gcd(abs(f -> b), f -> c);
    // printf("\n\n%d\n\n", g);
    f -> b  /=  g;
    f -> c  /=  g;
    if(f -> b > 0) {
        f -> a  +=  f -> b  /  f -> c;
        f -> b  %=  f -> c;
    } else {
        f -> b = abs(f -> b);
        f -> a  +=  f -> b  /  f -> c;
        f -> b  %=  f -> c;
        f -> a = -(f -> a);
    }
    return;
}

void transform(Frac *f) {
    f -> b  =  f -> a > 0  ?  
        f -> b + f -> a * f -> c  :  
        -f -> b + f -> a * f -> c;
    f -> a  =  0;
    return;
}

Frac add(Frac a, Frac b) {
    transform(&a);
    transform(&b);
    int multiplier = lcm(a.c, b.c);
    a.b *= multiplier / a.c;
    b.b *= multiplier / b.c;
    a.b += b.b;
    a.c = multiplier;
    // printf("\n\n%d\n\n", b.b);
    // printf("\n\n%d %d %d \n\n", a.a, a.b, a.c);
    simplify(&a);
    return a;
}

Frac sub(Frac a, Frac b) {
    transform(&a);
    transform(&b);
    int multiplier = lcm(a.c, b.c);
    a.b *= multiplier / a.c;
    b.b *= multiplier / b.c;
    a.b -= b.b;
    a.c = multiplier;
    simplify(&a);
    return a;
}

Frac mul(Frac a, Frac b) {
    transform(&a);
    transform(&b);
    a.c *= b.c;
    a.b *= b.b;
    simplify(&a);
    return a;
}

Frac div(Frac a, Frac b) {
    transform(&a);
    transform(&b);
    a.c *= b.b;
    a.b *= b.c;
    simplify(&a);
    return a;
}

Frac operate(Frac a, Frac b, int op) {
    switch(op) {
        case ADD :
            return add(a, b);
        case SUB :
            return sub(a, b);
        case MUL :
            return mul(a, b);
        case DIV :
            return div(a, b);
    }
}