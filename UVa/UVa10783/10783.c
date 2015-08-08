/* ACM 10783 Odd Sum
 * mythnc
 * 2011/10/27 08:42:49   
 * run time: 0.004
 */
#include <stdio.h>

int main(void)
{
    int a, b, set;

    scanf("%*d");
    set = 0;
    while(scanf("%d %d", &a, &b) == 2) {
        a % 2 ? a : a++;  /* if a is even */
        b % 2 ? b : b--;  /* if b is even */
        printf("Case %d: %d\n", ++set, ((b - a) / 2 + 1) * (b + a) / 2);
    }
    return 0;
}

