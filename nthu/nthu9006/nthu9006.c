#include <stdio.h>
#include <string.h>

#define MAXD 110
#define MAX(a, b) ((a) >= (b) ? (a) : (b))

typedef struct bign {
    int digit[MAXD];
    int len;
} BigN;

BigN init(char *s);
int add(char *x, char *y);

int main(void)
{
    char a[MAXD], b[MAXD];

    while (scanf("%s %s", a, b) == 2) {
        printf("%d\n", add(a, b));
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

/* return carry */
int add(char *x, char *y)
{
    int i, carry;
    BigN a, b, c;

    a = init(x);
    b = init(y);
    c = init("0");
    /* add */
    c.len = MAX(a.len, b.len) + 1;
    for (i = 0; i < c.len; i++) {
        c.digit[i] = a.digit[i] + b.digit[i];
    }

    /* carry */
    for (i = carry = 0; i < c.len; i++) {
        if (c.digit[i] > 9) {
            carry++;
            c.digit[i + 1]++;
            c.digit[i] %= 10;
        }
    }

    /*
     *while (c.digit[c.len] == 0)
     *    c.len--;
     *c.len++;
     */

    return carry;
}

