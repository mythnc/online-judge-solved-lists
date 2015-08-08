/* ACM 495 Fibonacci Freeze
 * mythnc
 * 2011/11/07 11:53:16   
 * run time: 0.532
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXARY 1100
#define MAXN   5001

void init(int **);
void fibo(int **);
int bigadd(int *, int *, int *, int);
void printbig(int *);
void freen(int **);

int main(void)
{
    int n;
    int *number[MAXN];

    init(number);
    fibo(number);
    while (scanf("%d", &n) == 1) {
        printf("The Fibonacci number for %d is ", n);
        printbig(number[n]);
    }
    freen(number);
    return 0;
}

/* init: make space to n[i] and 
 * initialize content of n[i] to zero */
void init(int **n)
{
    int i;

    for (i = 0; i < MAXN; i++) {
        n[i] = (int *)malloc(sizeof(int) * MAXARY);
        memset(n[i], 0, sizeof(int) * MAXARY);
    }
}

/* fibo: calculate fibonacci number from 0 to 5000 */
void fibo(int **n)
{
    int i, digit;

    n[0][0] = 0;
    n[1][0] = digit = 1;
    for (i = 2; i < MAXN; i++)
        digit = bigadd(n[i], n[i - 1], n[i - 2], digit);

}

/* bigadd: big number addtion,
 * return it's digits */
int bigadd(int *n, int *pre, int *ppre, int d)
{
    int i;

    for (i = 0; i < d; i++)
        n[i] += pre[i] + ppre[i];

    /* carry */
    for (i = 0; i < d; i++)
        if (n[i] > 9) {
            n[i] %= 10;
            n[i + 1]++;
        }

    if (n[i] != 0)
        return i + 1;
    return i;
}

/* printbig: print out big number */
void printbig(int *n)
{
    int i;

    i = MAXARY - 1;
    while (n[i] == 0 && i > 0)
        i--;
    for (; i > -1; i--)
        printf("%d", n[i]);
    printf("\n");
}

void freen(int **n)
{
    int i;

    for (i = 0; i < MAXN; i++)
        free(n[i]);
}

