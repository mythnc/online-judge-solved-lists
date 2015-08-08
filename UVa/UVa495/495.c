/* ACM 495 Fibonacci Freeze
 * mythnc
 * 2011/11/07 11:53:16   
 * run time: 0.372
 */
#include <stdio.h>

#define MAXARY 1100
#define MAXN   5001

void fibo(void);
int bigadd(int, int, int, int);
void printbig(int);

int number[MAXN][MAXARY];

int main(void)
{
    int n;

    fibo();
    while (scanf("%d", &n) == 1) {
        printf("The Fibonacci number for %d is ", n);
        printbig(n);
    }
    return 0;
}

/* fibo: calculate fibonacci number from 0 to 5000 */
void fibo(void)
{
    int i, digit;

    number[0][0] = 0;
    number[1][0] = digit = 1;
    for (i = 2; i < MAXN; i++)
        digit = bigadd(i, i - 1, i - 2, digit);
}

/* bigadd: big number addtion,
 * return it's digits */
int bigadd(int n, int pre, int ppre, int d)
{
    int i;

    for (i = 0; i < d; i++)
        number[n][i] += number[pre][i] + number[ppre][i];

    /* carry */
    for (i = 0; i < d; i++)
        if (number[n][i] > 9) {
            number[n][i] -= 10;
            number[n][i + 1]++;
        }

    if (number[n][i] != 0)
        return i + 1;
    return i;
}

/* printbig: print out big number */
void printbig(int n)
{
    int i;

    if (n == 0) {
        printf("0\n");
        return;
    }

    i = MAXARY - 1;
    while (number[n][i] == 0)
        i--;
    for (; i > -1; i--)
        printf("%d", number[n][i]);
    printf("\n");
}

