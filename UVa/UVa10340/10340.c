/* ACM 10340 All in All
 * mythnc
 * 2011/10/31 14:33:05   
 * run time: 0.008
 */
#include <stdio.h>

#define MAXARY 1000000
#define YES    1
#define NO     0

int form(char *, char *);

int main(void)
{
    char s[MAXARY], t[MAXARY];

    while (scanf("%s %s", s, t) == 2)
        if (form(s, t) == YES)
            printf("Yes\n");
        else
            printf("No\n");
    return 0;
}

/* form: judge s is a subsequence of t or not,
 * return the judgement yes or no */
int form(char *s, char *t)
{
    int i, j;

    for (i = j = 0; t[j] != '\0' && s[i] != '\0'; j++)
        if (s[i] == t[j])
            i++;

    if (s[i] == '\0')
        return YES;

    return NO;
}

