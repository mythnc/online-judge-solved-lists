/* ACM 10469 To Carry or not to Carry
 * mythnc
 * 2011/11/09 15:34:01   
 * run time: 0.012
 */
#include <stdio.h>

int main(void)
{
    unsigned int a, b;

    while (scanf("%u %u", &a, &b) == 2)
        printf("%u\n", a ^ b);
    return 0;
}

