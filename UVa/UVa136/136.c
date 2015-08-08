/* ACM 136 Ugly Numbers
 * mythnc
 * 2011/10/25 08:44:33   
 * run time: TE
 */
#include <stdio.h>

#define NTH 1500

int main(void)
{
    int count, n, i;

    count = 0;
    n = 0;
    while (count < NTH) {
        n++;
        i = n;
        while (1) {
            if (i == 1) {
                count++;
                break;
            }
            if (i % 2 == 0)
                i /= 2;
            else if (i % 3 == 0)
                i /= 3;
            else if (i % 5 == 0)
                i /= 5;
            else
                break;
        }
    }
    printf("The %d'th ugly number is %d.\n", NTH, n);
    return 0;
}

