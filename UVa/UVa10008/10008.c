/* ACM 10008 What's Cryptanalysis?
 * mythnc
 * 2011/10/13 09:10:55   
 * run time = 0.004
 */
#include <stdio.h>
#include <ctype.h>

int printout(int *s);

int main(void)
{
    int c;
    int alpha[26] = {0};

    scanf("%*d");
    while ((c = getchar()) != EOF)
        if (isupper(c))
            alpha[c - 'A']++;
        else if (islower(c))
            alpha[c - 'a']++;
    while (printout(alpha))
        ;
    return 0;
}

/* printout: print array s from high to low sequence */
int printout(int *s)
{
    int i, j, max;

    max = 0;
    for (i = 0; i < 26; i++)
        if (max < s[i]) {
            max = s[i];
            j = i;
        }
    if (max == 0)       /* if no letter have to be outputed */
        return 0;
    printf("%c %d\n", 'A' + j, max);
    s[j] = 0;
    return 1;
}

