#include <stdio.h>
#include <string.h>

#define MAXD 110
#define MAX(a, b) ((a) >= (b) ? (a) : (b))

typedef struct bign {
    int digit[MAXD];
    int len;
} BigN;

BigN init(char *s, int base);
BigN add(char *x, char *y, int base);
void output(BigN a);

int main(void)
{
    char a[MAXD], b[MAXD];
    int base;
    BigN c;

    while (scanf("%d %s %s", &base, a, b) == 3) {
        c = add(a, b, base);
        output(c);
    }
    return 0;
}

BigN init(char *s, int base)
{
    int i, j;
    BigN a;

    for (i = strlen(s) - 1, j = 0; i >= 0; i--, j++) {
        switch (s[i]) {
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
                a.digit[j] = s[i] - 'A' + 10;
                break;
            default:
                a.digit[j] = s[i] - '0';
        }
    }
    a.len = j;
    for (; j < MAXD; j++) {
        a.digit[j] = 0;
    }
    return a;
}

BigN add(char *x, char *y, int base)
{
    int i;
    BigN a, b, c;

    a = init(x, base);
    b = init(y, base);
    c = init("0", base);
    /* add */
    c.len = MAX(a.len, b.len) + 1;
    for (i = 0; i < c.len; i++) {
        c.digit[i] = a.digit[i] + b.digit[i];
    }

    /* carry */
    for (i = 0; i < c.len; i++) {
        if (c.digit[i] > base - 1) {
            c.digit[i + 1]++;
            c.digit[i] %= base;
        }
    }

    /* cal length of c */
    while (c.digit[c.len] == 0)
        c.len--;
    c.len++;
    
    return c;
}

void output(BigN a)
{
    int i;

    for (i = a.len - 1; i >= 0; i--) {
        switch (a.digit[i]) {
            case 15:
                printf("F");
                break;
            case 14:
                printf("E");
                break;
            case 13:
                printf("D");
                break;
            case 12:
                printf("C");
                break;
            case 11:
                printf("B");
                break;
            case 10:
                printf("A");
                break;
            default:
                printf("%d", a.digit[i]);
        }
    }
    putchar('\n');
}

