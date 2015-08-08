/* ACM 371 Ackermann Functions
 * mythnc
 * 2011/11/30 08:23:02
 * run time: 0.128
 */
#include <stdio.h>

#define SWAP(X, Y, T) T = X, X = Y, Y = T

typedef struct max {
    int index, value;
} Max;

Max cal(int, int);
int count(long long);

int main(void)
{
    int i, j, tmp;
    Max m;

    while (scanf("%d %d", &i, &j) && i != 0) {
        if (i > j)
            SWAP(i, j, tmp);
        m = cal(i, j);
        printf("Between %d and %d, %d generates the longest sequence of %d values.\n",
               i, j, m.index, m.value);
    }

    return 0;
}

/* cal: find the big cycle len, and return it */
Max cal(int small, int big)
{
    int i, tmp;
    Max m;

    m.index = small;
    m.value = count(small);
    for (i = small + 1; i <= big && i > 0; i++) {
        tmp = count(i);
        if (m.value < tmp) {
            m.index = i;
            m.value = tmp;
        }
    }

    return m;
}

/* count: count the numbers of value n to 1 */
int count(long long n)
{
    int c;

    if (n == 1)
        return 3;

    for (c = 0; n != 1; c++)
        if (n % 2 == 0)
            n >>= 1;    /* n /= 2 */
        else 
            n = n * 3 + 1;

    return c;
}

