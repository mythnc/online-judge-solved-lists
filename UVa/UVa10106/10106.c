/* ACM 10106 Product */
/* mythnc
 * 2011/11/13 13:12:16   
 * run time: 0.008
 */
#include <stdio.h>
#include <string.h>

#define MAXCHAR 251
#define MAXD    500

void init(int *);
void reverse(char *);
void mul(char *, char *, int *);
int ctoi(char);
void print(int *);

int main(void)
{
    char x[MAXCHAR], y[MAXCHAR];
    int product[MAXD];

    while (scanf("%s\n%s", x, y) == 2) {
        init(product);
        reverse(x);
        reverse(y);
        mul(x, y, product);
        print(product);
    }
    return 0;
}

/* init: initialize product */
void init(int *p)
{
    memset(p, 0, MAXD * sizeof(int));
}

/* reverse: reverse char arrry s */
void reverse(char *s)
{
    int i, j;
    char tmp;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

/* mul: do x * y save result in p */
void mul(char *x, char *y, int *p)
{
    int i, j, lenx, leny;

    lenx = strlen(x);
    leny = strlen(y);
    for (i = 0; i < lenx; i++)
        for (j = 0; j < leny; j++)
            p[i + j] += ctoi(x[i]) * ctoi(y[j]);

    /* carry */
    for (i = 0; i < lenx + leny - 1; i++)
        if (p[i] > 9) {
            p[i + 1] += p[i] / 10;
            p[i] %= 10;
        }
}

/* ctoi: return char to int */
int ctoi(char c)
{
    return c - '0';
}

/* print: print p from high to low */
void print(int *p)
{
    int i;

    for (i = MAXD - 1; p[i] == 0 && i > 0; i--)
        ;

    for (i; i > -1; i--)
        printf("%d", p[i]);
    putchar('\n');
}

