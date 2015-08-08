/* ACM 10019 Funny Encryption Method
 * mythnc
 * 2011/11/07 11:36:18   
 * run time: 0.004
 */
#include <stdio.h>

int dectobin(int);
int hextodec(int);

int main(void)
{
    int m;

    scanf("%*d");
    while (scanf("%d", &m) == 1)
        printf("%d %d\n", dectobin(m),
                dectobin(hextodec(m)));
    return 0;
}

/* dectobin: dec number to binary number,
 * return 1's times */
int dectobin(int m)
{
    int r, count;

    count = 0;
    while (m) {
        r = m % 2;
        if (r)
            count++;
        m /= 2;
    }

    return count;
}

/* hextodec: return the number in hex */
int hextodec(int m)
{
    int h, r, times, i;

    h = times = 0;
    while (m) {
        r = m % 10;
        for (i = 0; i < times; i++)
            r *= 16;
        h += r;
        times++;
        m /= 10;
    }

    return h;
}

