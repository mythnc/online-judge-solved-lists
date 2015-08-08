/* ACM 483 Word Scramble
 * mythnc
 * 2011/10/30 19:30:39   
 * run time: 0.008
 */
#include <stdio.h>
#include <string.h>

#define MAXARY 1000

int main(void)
{
    char s[MAXARY];
    char c;
    int i;

    while (scanf("%s%c", s, &c) == 2) {
        for (i = strlen(s) - 1; i > -1; i--)
            printf("%c", s[i]);
        putchar(c);
    }
    return 0;
}

