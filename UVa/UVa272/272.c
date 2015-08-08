/* ACM 272 TEX Quotes
 * mythnc
 * 2011/10/19 10:26:34   
 * run time: 0.004
 */
#include <stdio.h>

#define FIRST  1
#define SECOND 2

int main(void)
{
    int c, n;

    n = FIRST;
    while ((c = getchar()) != EOF)
        if (c == '"')
            if(n % 2 == 1) {
                printf("``");
                n = SECOND;
            }
            else {
                printf("''");
                n = FIRST;
            }
        else
            putchar(c);
    return 0;
}

