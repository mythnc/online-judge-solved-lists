/* ACM 490 Rotating Sentences
 * mythnc
 * 2011/11/14 19:22:42   
 * run time: 0.008
 */
#include <stdio.h>
#include <string.h>

#define MAXLINE 100
#define MAXCHAR 105

int maxlen(char (*seq)[MAXCHAR], int n);

int main(void)
{
    char seq[MAXLINE][MAXCHAR];
    int count, i, j;

    count = 0;
    while (fgets(seq[count], MAXCHAR, stdin))
        count++;

    for (i = 0; i < maxlen(seq, count); i++, putchar('\n'))
        for (j = count - 1; j > -1; j--)
            if (i >= strlen(seq[j]) - 1)
                putchar(' ');
            else
                printf("%c", seq[j][i]);

    return 0;
}

/* maxlen: return max string length */
int maxlen(char (*seq)[MAXCHAR], int n)
{
    int i, max;

    for (i = max = 0; i < n; i++)
        if (max < strlen(seq[i]))
            max = strlen(seq[i]);

    return max - 1;  /* we don't need '\n' */
}

