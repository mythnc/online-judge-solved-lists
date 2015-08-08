/* ACM 10055 Hashmat the Brave Warrior
 * mythnc
 * 2011/10/13 09:47:17   
 * run time: 0.06
 */
#include  <stdio.h>
#include  <stdlib.h>

int main(void)
{
    long long int x, y;

    while (scanf("%lld %lld",&x,&y) != EOF)
        if (x > y)
            printf("%lld\n", x - y);
        else
            printf("%lld\n", y - x);
    return 0;
}

