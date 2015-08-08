/* ACM 594 One Little, Two Little, Three Little Endians
 * mythnc
 * 2012/01/11 14:19:06   
 * version 2
 * http://chchwy.blogspot.com/2011/03/uva-594-one-little-two-little-three.html
 * use pointer casting
 * run time: 0.008
 */
#include <stdio.h>

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
    char *big, *little;
    int y, i;

    big = (char *)&x;
    little = (char *)&y;

    for (i = 0; i < 4; i++)
        little[i] = big[3 - i];

    return y;
}

