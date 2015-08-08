/* ACM 386 Perfect Cubes
 * mythnc
 * 2011/12/18 12:17:31   
 * run time: 0.132
 */
#include <stdio.h>

#define CUBIC(X) (X * X * X)

void cal(int);

int main(void)
{
    int i;

    for (i = 6; i <= 200; i++)
        cal(i);

    return 0;
}

/* cal: calculate answer */
void cal(int n)
{
    int i, j, k, value;

    for (i = 2; i < n; i++)
        for (j = i; CUBIC(i) + CUBIC(j) < CUBIC(n); j++)
            for (k = j; ; k++) {
                value = CUBIC(i) + CUBIC(j) + CUBIC(k);
                if (value < CUBIC(n))
                    continue;
                else if (value == CUBIC(n))
                    printf("Cube = %d, Triple = (%d,%d,%d)\n", n, i, j, k);
                else
                    break;
            }
}

