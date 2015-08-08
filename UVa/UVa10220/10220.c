/* ACM 10220 I Love Big Numbers !
 * mythnc
 * 2011/12/08 09:38:23   
 * run time: 0.020
 */
#include <stdio.h>

#define MAXD 2570
#define MAXN 1000

int bigmul(int *, int, int);
int sumdigit(int *, int);

int main(void)
{
    int n, i, digit;
    int answer[MAXN];
    int big[MAXD] = { 1 };
    /* pre calculate */
    for (i = digit = 1; i <= 1000; i++) {
        digit = bigmul(big, i, digit);
        answer[i - 1] = sumdigit(big, digit);
    }

    while (scanf("%d", &n) == 1)
        printf("%d\n", answer[n - 1]);

    return 0;
}

/* bigmul: do big * n, return its digit */
int bigmul(int *big, int n, int digit)
{
    int i;

    for (i = 0; i < digit; i++)
        big[i] *= n;
    /* find new digit */
    if (n < 10)
        digit++;
    else if (n < 100)
        digit += 2;
    else if (n < 1000)
        digit += 3;
    else
        digit += 4;
    /* carry */
    for (i = 0; i < digit; i++)
        if (big[i] > 9) {
            big[i + 1] += big[i] / 10;
            big[i] %= 10;
        }

    while (big[digit] == 0)
        digit--;
    return digit + 1;
}

/* sumdigit: return the sum of digits */
int sumdigit(int *big, int n)
{
    int i, sum;

    for (i = sum = 0; i < n; i++)
        sum += big[i];

    return sum;
}

