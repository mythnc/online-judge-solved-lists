/* ACM 10281 Average Speed
 * mythnc
 * 2011/12/31 08:12:03   
 * run time: 0.008
 */
#include <stdio.h>

#define LINEMAX 20

int main(void)
{
    char line[LINEMAX];
    int h, m, s, t1, t2;
    int newv, v;
    double dis;

    h = m = s = t1 = v = 0;
    dis = 0.0;
    while (fgets(line, LINEMAX, stdin))
        if (sscanf(line, "%d:%d:%d %d", &h, &m, &s, &newv) == 4) {
            t2 = h * 3600 + m * 60 + s;
            dis += (double)((t2 - t1) * v) / 3600.0;
            t1 = t2;
            v = newv;
        }
        else if (sscanf(line, "%d:%d:%d", &h, &m, &s) == 3) {
            t2 = h * 3600 + m * 60 + s;
            dis += (double)((t2 - t1) * v) / 3600.0;
            t1 = t2;
            /* output */
            printf("%02d:%02d:%02d %.2f km\n", h, m, s, dis);
        }

    return 0;
}

