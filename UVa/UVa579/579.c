/* ACM 579 ClockHands
 * mythnc
 * 2011/10/23 10:52:58   
 * run time: 0.032
 */
#include <stdio.h>

int main(void)
{
    int h, m;
    double angle;

    while (scanf("%d:%d", &h, &m) == 2) {
        if (h == 0 && m == 0)
            return 0;
        angle = 30 * h + 0.5 * m - 6 * m;
        if (angle < 0)
            angle = -angle;
        if (angle > 180)
            angle = 360 - angle;
        printf("%.3f\n", angle);
    }
}

