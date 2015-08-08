/* ACM 146 ID Codes
 * mythnc
 * 2012/01/08 19:16:00   
 * run time: 0.000
 */
#include <stdio.h>
#include <string.h>

#define MAXCHAR 51
#define TRUE    1
#define FALSE   0

void next(char *, int);
void reverse(char *, int, int, char *);

int main(void)
{
    char input[MAXCHAR];

    while (scanf("%s", input) && input[0] != '#')
        next(input, strlen(input));

    return 0;
}

/* next: find next permutation of s */
void next(char *s, int n)
{
    int i, j, last;
    char x, y;
    char wl[MAXCHAR], wr[MAXCHAR];

    for (i = n - 1, last = TRUE; i > 0; i--) {
        for (j = i - 1; j > -1; j--)
            if (s[j] < s[i]) {
                last = FALSE;
                break;
            }
        if (!last)
            break;
    }

    /* s is the last */
    if (last) {
        printf("No Successor\n");
        return;
    }

    wl[0] = wr[0] = '\0';
    if (i - j > 1)
        reverse(s, j, i, wl);
    if (n - i > 1)
        reverse(s, i, n, wr);

    /* output */
    x = s[i];
    y = s[j];
    s[j] = '\0';
    printf("%s%c%s%c%s\n", s, x, wr, y, wl);
}

/* reverse: reverse s from start to end.
 * save result in t */
void reverse(char *s, int start, int end, char *t)
{
    int i, j;

    for (i = end - 1, j = 0; i > start; i--, j++)
        t[j] = s[i];

    t[j] = '\0';
}

