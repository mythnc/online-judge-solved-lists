/* ACM 324 Factorial Frequencies
 * mythnc
 * 2011/11/18 09:13:32   
 * run time: 0.012
 */
#include <stdio.h>

#define MAXD 781

void init(int *, int);
int mul(int *, int);
void countdec(int *, int, int *);
void print(int, int *);

int main(void)
{
    int n, count;
    int seq[MAXD];
    int dec[10];

    while (scanf("%d", &n) && n != 0) {
        init(seq, MAXD);
        init(dec, 10);
        count = mul(seq, n);
        countdec(seq, count, dec);
        print(n, dec);
    }
    return 0;
}

/* init: initialized s to zero */
void init(int *s, int n)
{
    int i;

    for (i = 0; i < n; i++)
        s[i] = 0;
}

/* mul: calculate n!,
 * return its digit number */
int mul(int *s, int n)
{
    int i, j;

    for (s[0] = 1, i = 2; i < n + 1; i++) {
        for (j = 0; j < MAXD; j++)
            s[j] *= i;
            /* carry */
        for (j = 0; j < MAXD; j++)
            if (s[j] > 9) {
                s[j + 1] += s[j] / 10;
                s[j] %= 10;
            }
    }

    for (i = MAXD - 1; s[i] == 0; i--)
        ;

    return i + 1;
}

/* countdec: count 0~9 times */
void countdec(int *s, int n, int *d)
{
    int i;

    for (i = 0; i < n; i++)
        d[s[i]]++;
}

/* print: print out result */
void print(int n, int *d)
{
    int i;

    printf("%d! --\n", n);
    for (i = 0; i < 10; i++) {
        if (i == 5)
            printf("\n");
        if (i != 0 && i != 5)
            printf(" ");
        printf("   (%d)%5d", i, d[i]);
    }
    printf("\n");
}

