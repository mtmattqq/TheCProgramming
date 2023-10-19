#include <stdio.h>

typedef struct frac{
    int a, b;
    // repersent a over b
    //    a
    //  -----
    //    b
} Frac;

int gcd(int, int);
void simplify(Frac *);
Frac add(Frac, Frac);
Frac mul(Frac, Frac);

int main(void) {

#ifdef DEBUG
    int x = 15, y = 6;
    printf("%d\n", gcd(x, y));
    Frac a, b;
    a.a = 3; a.b = 5;
    b.a = 4; b.b = 7;
    Frac r = add(a, b);
    printf("%d %d\n", r.a, r.b);
    r = mul(a, b);
    printf("%d %d\n", r.a, r.b);
    printf("\n");
#endif

    int n;
    scanf("%d", &n);

    Frac pin[400];
    for(int i = 0; i < n * (n + 1) / 2 ; ++i) {
        scanf("%d%d", &(pin[i].a), &(pin[i].b));
    }

#ifdef DEBUG
    for(int i = 0; i < n * (n + 1) / 2 ; ++i) {
        printf("%d %d\n", pin[i].a, pin[i].b);
    }
    printf("\n");
#endif

    Frac ans[20] = {0};
    for(int i = 0; i < 20; ++i) {
        simplify(ans + i);
    }
    for(int i = 0; i < (1 << n); ++i) {
        int idx = 0, k = 0;
        Frac ad = {1, 1};
        for(int j = 0; j < n; ++j) {
            idx = (j * (j + 1)) / 2 + k;
            if(i & (1 << j)) {
                Frac p = {pin[idx].b, pin[idx].a + pin[idx].b};
                simplify(&p);

#ifdef DEBUG
                printf("%d %d\n\n", p.a, p.b);
#endif

                k++;
                ad = mul(ad, p);
            } else {
                Frac p = {pin[idx].a, pin[idx].a + pin[idx].b};
                simplify(&p);

#ifdef DEBUG
                printf("%d %d\n\n", p.a, p.b);
#endif

                ad = mul(ad, p);
            }
        }
        
#ifdef DEBUG
        printf("%d %d\n", ad.a, ad.b);
        printf("%d %d\n\n", ans[k].a, ans[k].b);
#endif

        ans[k] = add(ad, ans[k]);
    }

    for(int i = 0; i <= n; ++i) {
        printf("%d/%d\n", ans[i].a, ans[i].b);
    }

    return 0;
}

int gcd(int a, int b) {
    return a % b == 0  ?  b  :  gcd(b, a % b);
}

void simplify(Frac *a) {
    if(a -> a == 0){
        a -> b = 1;
        return;
    }

    int g = gcd(a -> a, a -> b);
    a -> a  /=  g;
    a -> b  /=  g;
    return;
}

Frac add(Frac a, Frac b) {
    int g = gcd(a.b, b.b);
    int lcm = (a.b / g) * (b.b / g) * g;
    a.a *= lcm / a.b;
    b.a *= lcm / b.b;
    a.a += b.a;
    a.b = lcm;
    simplify(&a);
    return a;
}

Frac mul(Frac a, Frac b) {
    a.a *= b.a;
    a.b *= b.b;
    simplify(&a);
    return a;
}