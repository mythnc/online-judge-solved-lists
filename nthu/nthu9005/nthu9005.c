#include <stdio.h>
#include <string.h>

#define MAXD 210

typedef struct bign {
    int digit[MAXD];
    int len;
} BigN;

BigN init(char *s);
BigN mul(char *x, char *y);
void output(BigN a);

int main(void)
{
    char a[MAXD], b[MAXD];

    while (scanf("%s %s", a, b) == 2) {
        output(mul(a, b));
    }
    return 0;
}

BigN init(char *s)
{
    int i, j;
    BigN a;

    for (i = strlen(s) - 1, j = 0; i >= 0; i--, j++) {
        a.digit[j] = s[i] - '0';
    }
    a.len = j;
    for (; j < MAXD; j++) {
        a.digit[j] = 0;
    }
    return a;
}

BigN mul(char *x, char *y)
{
    int i, j;
    BigN a, b, c;

    /* mul */
    a = init(x);
    b = init(y);
    c = init("0");
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

    if (a.len == 0)
        putchar('0');
    for (i = a.len - 1; i >= 0; i--) {
        printf("%d", a.digit[i]);
    }
    putchar('\n');
}

