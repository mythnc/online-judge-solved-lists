/* ACM 412 Pi
 * mythnc
 * 2011/11/24 10:50:36   
 * run time: 0.124
 */
#include <stdio.h>
#include <math.h>

#define MAXN 49

void input(int *, int);
int comfactor(int *, int);
int gcd(int, int);

int main(void)
{
    int n, pair;
    int list[MAXN];

    while (scanf("%d", &n) == 1 && n != 0) {
        input(list, n);
        pair = comfactor(list, n);
        if (pair == 0) {
            printf("No estimate for this data set.\n");
            continue;
        }
        printf("%.6f\n", sqrt(3.0 / pair * n * (n - 1)));
    }

    return 0;
}

/* input: receive input data */
void input(int *list, int n)
{
    int i;

    for (i = 0; i < n; i++)
        scanf("%d", list + i);
}

/* comfactor: return no common factors pair numbers */
int comfactor(int *list, int n)
{
    int i, j, count;

    for (count = i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (gcd(list[i], list[j]) == 1)
                count++;

    return count;
}

/* gcd: calculate gcd of a and b */
int gcd(int a, int b)
{
    while ((a %= b) && (b %= a))
        ;

    return a + b;
}

