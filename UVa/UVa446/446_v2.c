/* ACM 446 Kibbles `n' Bits `n' Bits `n' Bits
 * mythc
 * 2011/11/28 10:07:08   
 * run time: 0.004
 */
#include <stdio.h>
#include <string.h>

#define MAXB  14
#define MAXH  4
#define OPR   2

int hextodec(char *);
int atod(char);
void dectobin(int, char *);
int result(int, int, char *);

int main(void)
{
    char opd[2][MAXH];
    char opr[OPR];
    char b[2][MAXB];
    int d[2];
    int i;

    scanf("%*d");
    while (scanf("%s %s %s", opd[0], opr, opd[1]) == 3) {
        for (i = 0; i < 2; i++) {
            d[i] = hextodec(opd[i]);
            dectobin(d[i], b[i]);
        }
        printf("%s %s %s = %d\n", b[0], opr, b[1], result(d[0], d[1], opr));
    }

    return 0;
}

/* hextodec: hex number change to decimal number */
int hextodec(char *s)
{
    int i, n, mul;

    mul = 1;
    for (n = 0, i = strlen(s) - 1; i > -1; i--) {
        n += mul * atod(s[i]);
        mul *= 16;
    }

    return n;
}

/* atoh: convert ascii code to decimal number */
int atod(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';

    return c - 'A' + 10;
}

/* dectobin: decimal number change to binary form */
void dectobin(int d, char *b)
{
    int i;

    b[MAXB - 1] = '\0';
    for (i = MAXB - 2; d != 0; i--) {
        b[i] = d % 2 + '0';
        d /= 2;
    }
    for (; i > -1; i--)
        b[i] = '0';
}

/* result: depend on opr, do d1 + d2,
 * or d1 - d2 */
int result(int d1, int d2, char *opr)
{
    if (strcmp(opr, "+") == 0)
        return d1 + d2;

    return d1 - d2;
}

