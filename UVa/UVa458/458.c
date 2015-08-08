/* ACM 458 The Decoder
 * mythnc
 * 2011/10/25 08:18:04   
 * run time: 0.02
 */
#include <stdio.h>

int main(void)
{
    int c;

    while ((c = getchar()) != EOF)
        if (c == '\n')
            putchar(c);
        else
            putchar(c - 7);
    return 0;
}

