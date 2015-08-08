/* ACM 494 Kindergarten Counting Game
 * mythnc
 * 2011/10/25 08:35:53   
 * run time: 0.004
 */
#include <stdio.h>
#include <stdlib.h>

#define IN  1
#define OUT 0

int main(void)
{
    int c, s, count;

    s = OUT;
    count = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n') {
            printf("%d\n", count);
            s = OUT;
            count = 0;
        }
        else if (isalpha(c) && s == OUT) {
            count++;
            s = IN;
        }
        else if (!isalpha(c))
            s = OUT;
    return 0;
}

