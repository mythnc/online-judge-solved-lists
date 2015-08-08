#include <stdio.h>
#include <string.h>

/* #define DEBUG */
#define MAXN 110
#define MAX(a, b) (((a) >= (b)) ? (a) : (b))

typedef struct bign {
    int digit[MAXN];
    char sigh;
    int len;
} BigN;


void trans(char *s, BigN *a);
void init(BigN *a);
void operate(const BigN a, const BigN b, BigN *c);
int compare(const BigN a, const BigN b);
void add(const BigN a, const BigN b, BigN *c);
void sub(const BigN a, const BigN b, BigN *c);
void output(BigN a);

int main(void)
{
    char x[MAXN], y[MAXN];
    BigN a, b, c;

    while (scanf("%s %s", x, y) != EOF) {
#ifdef DEBUG
        printf("%s %s\n", x, y);
#endif
        init(&a);
        init(&b);
        init(&c);
        trans(x, &a);
#ifdef DEBUG
        putchar('\n');
        output(a);
#endif
        trans(y, &b);
#ifdef DEBUG
        putchar('\n');
        output(b);
#endif
        operate(a, b, &c);
        output(c);
    }
    return 0;
}

void init(BigN *a)
{
    int i;

    a->sigh = '+';
    a->len = 0;
    for (i = 0; i < MAXN; i++) {
        a->digit[i] = 0;
    }
}

void trans(char *s, BigN *a)
{
    int i, j;

    for (i = strlen(s) - 1, j = 0; i >= 1; i--, j++) {
#ifdef DEBUG
        putchar(s[i]);
#endif
        a->digit[j] = s[i] - '0';
    }
    if (s[0] == '-') {
        a->sigh = '-';
        a->len = j;
    }
    else {
#ifdef DEBUG
        putchar(s[i]);
#endif
        a->sigh = '+';
        a->digit[j] = s[0] - '0';
        a->len = j + 1;
    }
}

void operate(const BigN a, const BigN b, BigN *c)
{
    int diff;

    if (a.sigh == '-' && b.sigh == '-') {
        c->sigh = '-';
        add(a, b, c);
    }
    else if (a.sigh != '-' && b.sigh != '-') {
        add(a, b, c);
    }
    else if (a.sigh == '-') {
        diff = compare(a, b);
        if (diff < 0)
            sub(b, a, c);
        else if (diff > 0) {
            c->sigh = '-';
            sub(a, b, c);
        }
    }
    else if (b.sigh == '-') {
        diff = compare(a, b);
        if (diff < 0) {
            c->sigh = '-';
            sub(b, a, c);
        }
        else if (diff > 0)
            sub(a, b, c);
    }
}

int compare(const BigN a, const BigN b)
{
    int diff, i;

    diff = a.len - b.len;
    if (diff > 0)
        return 1;
    if (diff < 0)
        return -1;

    for (i = a.len - 1; i >= 0; i--) {
        diff = a.digit[i] - b.digit[i];
        if (diff > 0)
            return 1;
        if (diff < 0)
            return -1;
    }
    return 0;
}

void add(const BigN a, const BigN b, BigN *c)
{
    int i, max;

    max = MAX(a.len, b.len);
    for (i = 0; i < max; i++) {
        c->digit[i] = a.digit[i] + b.digit[i];
    }

    /* carry */
    for (i = 0; i < max + 1; i++) {
        if (c->digit[i] > 9) {
            c->digit[i + 1]++;
            c->digit[i] -= 10;
        }
    }

    while (c->digit[i] == 0)
        i--;
    c->len = i + 1;
}

void sub(const BigN a, const BigN b, BigN *c)
{
    int i, max;

    max = MAX(a.len, b.len);
    for (i = 0; i < max; i++) {
        c->digit[i] = a.digit[i] - b.digit[i];
    }

    /* borrow */
    for (i = 0; i < max; i++) {
        if (c->digit[i] < 0) {
            c->digit[i + 1]--;
            c->digit[i] += 10;
        }
    }

    while (c->digit[i] == 0)
        i--;
    c->len = i + 1;
}

void output(BigN a)
{
    int i;

#ifdef DEBUG
    printf("len: %d\n", a.len);
#endif
    if (a.len != 0 && a.sigh == '-')
        printf("-");
    if (a.len == 0)
        putchar('0');
    for (i = a.len - 1; i >= 0; i--) {
        printf("%d", a.digit[i]);
    }
    putchar('\n');
}

