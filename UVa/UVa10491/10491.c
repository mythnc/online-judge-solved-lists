/* ACM 10491 Cows and Cars
 * mythnc
 * 2011/10/17 11:08:44   
 * run time: 0.012
 */
#include <stdio.h>

int main(void)
{
    int cow, car, show;
    int total, left;

    while (scanf("%d %d %d", &cow, &car, &show) != EOF) {
        total = cow + car;
        left = total - show - 1;
        printf("%.5f\n", (double)cow / total * car / left +
                         (double)car / total * (car - 1) / left);
    }
    return 0;
}

