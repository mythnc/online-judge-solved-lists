#include <stdio.h>

/* #define DEBUG */
#define MAXN 114
#define MAXD 200

typedef struct bign {
    int digit[MAXD];
    int len;
} BigN;

void init(BigN *a);
void factorial(BigN *a, int n);
void mul(const BigN a, int b, BigN *c);
void output(BigN a);

int main(void)
{
    int n;
    BigN a[MAXN + 1];

    init(a);
    factorial(a, MAXN);
    while (scanf("%d", &n) && n != 0) {
        output(a[n]);
    }
    return 0;
}

void init(BigN *a)
{
    int i, j;

    for (i = 1; i <= MAXN; i++) {
        for (j = a[i].len = 0; j < MAXD; j++) {
            a[i].digit[j] = 0;
        }
    }
    a[1].digit[0] = a[1].len = 1;
}

void factorial(BigN *a, int n)
{
    int i;

    for (i = 2; i <= n; i++) {
        mul(a[i - 1], i, &a[i]);
    }
}

void mul(const BigN a, int b, BigN *c)
{
    int i;

    /* cal length of c */
    if (b / 10 > 9) {
        c->len = a.len + 2;
    }
    else if (b / 10 > 0) {
        c->len = a.len + 1;
    }
    else {
        c->len = a.len;
    }

    /* mul */
    for (i = c->len - 1; i >= 0; i--) {
        c->digit[i] = a.digit[i] * b;
    }

    /* carry */
    for (i = 0; i < c->len; i++) {
        if (c->digit[i] > 9) {
            c->digit[i + 1] += c->digit[i] / 10;
            c->digit[i] %= 10;
        }
    }

    while (c->digit[c->len] == 0)
        c->len--;
    c->len++;
}

void output(BigN a)
{
    int i;

    for (i = a.len - 1; i >= 0; i--) {
        printf("%d", a.digit[i]);
    }
    putchar('\n');
}

