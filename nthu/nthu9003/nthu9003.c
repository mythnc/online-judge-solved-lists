#include <stdio.h>

#define MAXD 1000

typedef struct bign {
    int digit[MAXD];
    int len;
} BigN;

BigN init(int a);
BigN mul(const BigN a, const BigN b);
BigN power(int a, int b);
void output(BigN a);

int main(void)
{
    int n, a, b;

    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &a, &b);
        output(power(a, b));
    }
    return 0;
}

BigN init(int a)
{
    int i = 0;
    BigN c;

    while (a != 0) {
        c.digit[i++] = a % 10;
        a /= 10;
    }
    c.len = i;
    for (; i < MAXD; i++) {
        c.digit[i] = 0;
    }

    return c;
}

BigN power(int a, int b)
{
    int i = 0;
    BigN c, temp;

    c = init(1);
    temp = init(a);
    while (b != 0) {
        if (b % 2 == 1) {
            c = mul(c, temp);
        }
        b /= 2;
        temp = mul(temp, temp);
    }

    return c;
}

BigN mul(const BigN a, const BigN b)
{
    int i, j;
    BigN c;

    /* mul */
    c = init(0);
    for (i = 0; i < a.len; i++) {
        for (j = 0; j < b.len; j++) {
            c.digit[i + j] += a.digit[i] * b.digit[j];
        }
    }

    /* cal length of c */
    c.len = a.len + b.len;

    /* carry */
    for (i = 0; i < c.len; i++) {
        if (c.digit[i] > 9) {
            c.digit[i + 1] += c.digit[i] / 10;
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

