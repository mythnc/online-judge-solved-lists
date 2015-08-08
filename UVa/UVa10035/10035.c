/* ACM 10035 Primary Arithmetic
 * mythnc
 * 2u11/10/12 20:48:47   
 * run time = 0.02
 */
#include <stdio.h>

int carry(int, int);

int main(void)
{
    int x, y, n;

    while (scanf("%d %d", &x, &y) == 2) {
        if (x == 0 && y == 0)
            break;
        if ((n = carry(x, y)) == 1)
            printf("1 carry operation.\n");
        else if (n == 0)
            printf("No carry operation.\n");
        else
            printf("%d carry operations.\n", n);
    }
    return 0;
}

/* carry: calculate the carry times */
int carry(int x, int y)
{
    int n, c;

    c = n = 0;
    while (x != 0 || y != 0) {   /* same as !(x==0 && y==0) */
        if (x % 10 + y % 10 + c > 9) {
            n++;
            c = 1;
        }
        else
            c = 0;
        x /= 10;
        y /= 10;
    }
    return n;
}

