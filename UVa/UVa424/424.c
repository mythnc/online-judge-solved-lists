/* ACM 424 Integer Inquiry
 * mythnc
 * 2011/10/30 18:43:44   
 * run time: 0.004
 */
#include <stdio.h>
#include <string.h>

#define MAXARY 105

int addbig(int *, char *, int);
void printout(int *, int);

int main(void)
{
    char tmp[MAXARY];
    int big[MAXARY] = { 0 };
    int len, count;

    len = 0;
    while (scanf("%s", tmp)) {
        if (tmp[0] == '0' && tmp[1] == '\0') {
            printout(big, len);
            return 0;
        }
        count = addbig(big, tmp, len);
        if (len < count)
            len = count;
    }
}

/* addbig: add big number, return it's length */
int addbig(int *big, char *tmp, int len)
{
    int i, count;

    for (count = 0, i = strlen(tmp) - 1; i > -1; i--)
        big[count++] += tmp[i] - '0';

    /* carry */
    if (count < len)
        count = len;
    for (i = 0; i < count; i++)
        if (big[i] > 10) {
            big[i + 1] += big[i] / 10;
            big[i] %= 10;
        }

    if (big[i] != 0)
        return count + 1;
    return count;
}

/* printout: print out big number */
void printout(int *big, int n)
{
    int i;

    for (i = n - 1; i > - 1; i--)
        printf("%d", big[i]);
    printf("\n");
}

