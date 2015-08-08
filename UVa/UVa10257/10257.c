/* ACM 10257 Dick and Jane
 * mythnc
 * 2011/10/15 20:11:27   
 * run time: 0.004
 */
#include <stdio.h>

int main(void)
{
    int s, p, y, j, x; /* x: Yertle's age */

    while (scanf("%d %d %d %d", &s, &p, &y, &j) == 4) {
        x = (12 + j - p - y) / 3;
        switch((12 + j - p - y) % 3) {
            case 0:
                printf("%d %d %d\n", x + y, x + p, x);
                break;
            case 1:
                if (s + p == y)
                    printf("%d %d %d\n", x + y + 1, x + p, x);
                else
                    printf("%d %d %d\n", x + y, x + p + 1, x);
                break;
            case 2:
                printf("%d %d %d\n", x + y + 1, x + p + 1, x);
                break;
        }
    }
    return 0;
}

