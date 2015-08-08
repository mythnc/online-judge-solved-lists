/* ACM 10300 Ecological Premium
 * mythnc
 * 2011/10/25 15:33:42   
 * run time: 0.004
 */
#include <stdio.h>

int main(void)
{
    int n, sum, s, e;

    scanf("%*d");
    while (scanf("%d", &n) != EOF) {
        for (sum = 0; n; n--) {
            scanf("%d %*d %d", &s, &e);
            sum += s * e;
        }
        printf("%d\n", sum);
    }
    return 0;
}

