/* ACM 573 The Snail
 * mythnc
 * 2011/12/14 13:48:31   
 * run time: 0.020
 */
#include <stdio.h>

void snail(int, int, double, double);

int main(void)
{
    double fatigue, up;
    int wall, down;

    while (scanf("%d %lf %d %lf", &wall, &up, &down, &fatigue)
           && wall != 0) {
           snail(wall, down, up, fatigue);
    }

    return 0;
}

void snail(int wall, int down, double up, double fa)
{
    int day;
    double climb;
    /* init */
    day = 1;
    climb = 0.0;
    fa = up * fa / 100;
    while (1) {
        /* day climb */
        climb += up;
        if (climb > wall) {
            printf("success on day %d\n", day);
            return;
        }
        /* night fall */
        climb -= down;
        if (climb < 0.0) {
            printf("failure on day %d\n", day);
            return;
        }
        up -= fa;
        /* if up come to non-positive */
        if (up <= 0.0) {
            while (climb >= 0.0) {
                climb -= down;
                day++;
            }
            printf("failure on day %d\n", day);
            return;
        }
        /* another day */
        day++;
    }
}

