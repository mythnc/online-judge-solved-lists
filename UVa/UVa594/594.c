/* ACM 594 One Little, Two Little, Three Little Endians
 * mythnc
 * 2012/01/11 14:19:06   
 * run time: 0.008
 */
#include <stdio.h>
#include <string.h>

#define MAX 32

int convert(int);

int main(void)
{
    int x;

    while (scanf("%d", &x) == 1)
        printf("%d converts to %d\n", x, convert(x));

    return 0;
}

/* convert: convert x to different endian system */
int convert(int x)
{
    int endian[MAX];
    int i, mul;
    
    memset(endian, 0, sizeof(endian));
    if (x < 0) {
        endian[7] = 1;
        x += 2147483647;
        x++;
    }
    i = 24;
    while (x) {
        endian[i++] = x % 2;
        x /= 2;
        if (i % 8 == 0)
            i -= 16;
    }
    for (i = x = 0, mul = 1; i < MAX - 1; i++, mul *= 2)
        x += mul * endian[i];
    if (endian[i] == 1) {
        x -= 2147483647;
        x--;
    }

    return x;
}

