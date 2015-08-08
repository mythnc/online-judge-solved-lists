/* ACM 10018 Reverse and Add
 * mythnc
 * 2011/10/12 19:38:26
 * run time = 0.008
 */
#include <stdio.h>

#define MAXARY 15

typedef unsigned int number;

number reverse(number);

int main(void)
{
    int n, count;
    number x, y;

    scanf("%d", &n);
    while (n-- > 0) {
        scanf("%u", &x);
        count = 0;
        while (x != (y = reverse(x))) {
            x += y;
            count++;
        }
        printf("%d %u\n", count, x);
    }
    return 0;
}

/* reverse: reverse the digits of x */
number reverse(number x)
{
    number y;

    y = 0;
    do {
        y *= 10;
        y += x % 10;
        x /= 10;
    } while (x != 0);
    return y;
}

