/* ACM 10346 Peter’s Smokes
 * mythnc
 * 2011/11/02 20:18:09   
 * run time: 0.008
 */
#include <stdio.h>

int rollcig(int, int);

int main(void)
{
    int n, k;

    while (scanf("%d %d", &n, &k) == 2)
        printf("%d\n", rollcig(n, k));

    return 0;
}

/* rollcig: return the cigarette peter have */
int rollcig(int n, int k)
{
    int count, r;
    
    for (count = n; n >= k; n += r) {
        r = n % k;
        n /= k;
        count += n;
    }

    return count;
}

