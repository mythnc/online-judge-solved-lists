#include <stdio.h>
#include <string.h>

#define MAXD 220
#define MAXF 1000
#define MAX(a, b) ((a) >= (b) ? (a) : (b))

typedef struct bign {
    int digit[MAXD];
    int len;
} BigN;

void init(BigN *f);
void cal(BigN *a);
BigN add(BigN a, BigN b);
void output(BigN a);

int main(void)
{
    int n;
    BigN f[MAXF + 1];

    cal(f);
    while (scanf("%d", &n) == 1) {
        output(f[n]);
    }
    return 0;
}

void init(BigN *a)
{
    int i;

    for (i = a->len = 0; i < MAXD; i++) {
        a->digit[i] = 0;
    }
}

void cal(BigN *f)
{
    int i;

    for (i = 1; i < MAXF + 1; i++) {
        init(&f[i]);
    }
    f[1].digit[0] = f[2].digit[0] = 1;
    f[1].len = f[2].len = 1;

    for (i = 3; i < MAXF + 1; i++) {
        f[i] = add(f[i - 1], f[i - 2]);
    }
}

BigN add(BigN a, BigN b)
{
    int i;
    BigN c;

    init(&c);
    /* add */
    c.len = MAX(a.len, b.len) + 1;
    for (i = 0; i < c.len; i++) {
        c.digit[i] = a.digit[i] + b.digit[i];
    }

    /* carry */
    for (i = 0; i < c.len; i++) {
        if (c.digit[i] > 9) {
            c.digit[i + 1]++;
            c.digit[i] %= 10;
        }
    }
    
    while (c.digit[c.len] == 0)
        c.len--;
    c.len++;

    return c;
}

void output(BigN a)
{
    int i;

    for (i = a.len - 1; i >= 0; i--) {
        printf("%d", a.digit[i]);
    }
    putchar('\n');
}

