#include <stdio.h>

#define MAXX 1010
#define MIN(x, y) (((x) <= (y)) ? (x) : (y))
#define MAX(x, y) (((x) >= (y)) ? (x) : (y))

typedef struct poly {
    int x[MAXX];
    int degree;
} Poly;

Poly init(int n);
Poly add(Poly a, Poly b);
void output(Poly a);

int main(void)
{
    int t, m, n;
    Poly a, b, c;

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &m, &n);
        a = init(m);
        b = init(n);
        c = add(a, b);
        output(c);
    }
    return 0;
}

Poly init(int n)
{
    int i;
    Poly a;

    a.degree = n;
    for (i = n; i >= 0; i--) {
        scanf("%d", &a.x[i]);
    }
    return a;
}

Poly add(Poly a, Poly b)
{
    int i, min, max;
    Poly c;

    min = MIN(a.degree, b.degree);
    max = MAX(a.degree, b.degree);
    for (i = 0; i <= min; i++) {
        c.x[i] = a.x[i] + b.x[i];
    }
    for (; i <= max; i++) {
        if (a.degree == max)
            c.x[i] = a.x[i];
        else
            c.x[i] = b.x[i];
    }
    c.degree = i - 1;

    return c;
}

void output(Poly a)
{
    int i = a.degree;

    printf("%d", a.x[i]);
    for (i-- ; i >= 0; i--) {
        printf(" %d", a.x[i]);
    }
    putchar('\n');
}

