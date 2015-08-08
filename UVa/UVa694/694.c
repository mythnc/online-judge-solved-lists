/* ACM 694 The Collatz Sequence
 * mythnc
 * 2011/11/08 10:21:28   
 * run time: 0.056
 */
#include <stdio.h>

int times(long long , int);

int main(void)
{
    int a, limit, set;

    set = 0;
    while (scanf("%d %d", &a, &limit)
           && a > 0
           && limit > 0)
        printf("Case %d: A = %d, limit = %d, number of terms = %d\n",
               ++set, a, limit, times(a, limit));

    return 0;
}

/* times: return the term number of n */
int times(long long n, int limit)
{
    int count;

    count = 1;
    while (n != 1) {
        if (n % 2 == 1) {
            n = 3 * n + 1;
            if (n > limit)
                break;
        }
        else
            n >>= 1;
        count++;
    }

    return count;
}

