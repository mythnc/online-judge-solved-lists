/* ACM 941 Permutations
 * mythnc
 * 2012/01/04 12:29:00   
 * run time:
 */
#include <stdio.h>
#include <string.h>

#define MAXCHAR 21
#define SWAP(X, Y, T) T = X, X = Y, Y = T

void per(char *, int, int);

int times;

int main(void)
{
    char c[MAXCHAR];

    scanf("%*d");
    while (scanf("%s", c) == 1) {
        scanf("%d", &times);
        per(c, 0, strlen(c));
    }

    return 0;
}

/* per: count the permutation times */
void per(char *c, int i, int n)
{
    int j, tmp;

    if (i == n) {
        if (times == 0)
            printf("%s\n", c);
        times--;
    }

    for (j = i; j < n && times >= 0; j++) {
        SWAP(c[i], c[j], tmp);
        per(c, i + 1, n);
        SWAP(c[i], c[j], tmp);
    }
}

