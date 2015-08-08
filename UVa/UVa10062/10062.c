/* ACM 10062 Tell me the frequencies!
 * mythnc
 * 2011/10/13 18:48:47
 * run time: 0.004
 */
#include <stdio.h>

int output(int *);

int main(void)
{
    int c, newline;
    int ary[96] = { 0 };

    newline = 0;
    while ((c = getchar()) != EOF) {
        if (c > 31 && c < 128)
            ary[c - 32]++;
        if (c == '\n') {
            if (++newline > 1)
                printf("\n");
            while (output(ary))
                ;
        }
    }
    return 0;
}

/* output: print out the result from high ascii value to low */
int output(int *s)
{
    int i, j, min;

    for (min = 1001, i = 95; i > -1; i--)
        if (min > s[i] && s[i] > 0) {
            min = s[i];
            j = i;
        }
    if (min == 1001)   /* if no element have to printed */
        return 0;
    printf("%d %d\n", j + 32, min);
    s[j] = 0;
    return 1;
}

