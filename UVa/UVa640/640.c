/* ACM 640 Self Numbers
 * mythnc
 * 2011/12/10 20:41:52   
 * version 1.1
 * run time: 0.068
 */
#include <stdio.h>

#define MAXN   1000001
#define ANSWER 97786
#define TRUE   1
#define FALSE  0

int sumd(int);

int mark[MAXN];
int output[ANSWER];
int count;

int main(void)
{
    int i, sum;

    for (i = 1; i < MAXN; i++)
        if (!mark[i]) {
            output[count++] = i;
            sum = sumd(i);
            while (sum < MAXN && !mark[sum]) {
                mark[sum] = TRUE;
                sum = sumd(sum);
            }
        }
    /* output */
    for (i = 0; i < count; i++)
        printf("%d\n", output[i]);

    return 0;
}

/* sumd: do d(n) and return the value */
int sumd(int n)
{
    int sum;

    for (sum = n; n; n /= 10)
        sum += n % 10;

    return sum;
}

