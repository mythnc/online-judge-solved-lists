/* ACM 661 Blowing Fuses
 * mythnc
 * 2012/01/03 23:17:33   
 * run time: 0.004
 */
#include <stdio.h>

#define MAXN 20
#define ON   1
#define OFF  0

typedef struct device {
    int state;
    int c;
} Device;

int maxpower(int, int);

int main(void)
{
    int n, m, c, max, set;

    set = 0;
    while (scanf("%d %d %d", &n, &m, &c) && n != 0) {
        max = maxpower(n, m);
        if (max > c)
            printf("Sequence %d\nFuse was blown.\n\n", ++set);
        else {
            printf("Sequence %d\nFuse was not blown.\n", ++set);
            printf("Maximal power consumption was %d amperes.\n\n", max);
        }
    }

    return 0;
}

/* maxpower: return the max consumption power
 * during the sequence*/
int maxpower(int n, int m)
{
    int max, i, number, sum;
    Device dev[MAXN];
    /* init */
    for (i = 0; i < n; i++) {
        scanf("%d", &dev[i].c);
        dev[i].state = OFF;
    }
    /* switch start */
    for (i = max = sum = 0; i < m; i++) {
        scanf("%d", &number);
        if (dev[number - 1].state == ON) {
            dev[number - 1].state = OFF;
            sum -= dev[number - 1].c;
        }
        else {
            dev[number - 1].state = ON;
            sum += dev[number - 1].c;
            if (max < sum)
                max = sum;
        }
    }

    return max;
}

