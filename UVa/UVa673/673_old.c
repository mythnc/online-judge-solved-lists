/* ACM 673 Parentheses Balance
 * mythnc
 * 2011/11/04 16:23:03   
 * run time: 0.224
 */
#include <stdio.h>

#define MAXCHAR 130
#define YES     1
#define NO      0

int pairs(char *);

int main(void)
{
    char s[MAXCHAR];
    int n;

    scanf("%d\n", &n);
    while (n--) {
        fgets(s, MAXCHAR, stdin);
        if (pairs(s) == YES)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}

/* pairs: find () or [] is pair or not,
 * if it is pair, return YES,
 * else return NO */
int pairs(char *s)
{
    char *pt;

    pt = s;
    /* blank string */
    while (*pt == ' ' && *pt != '\n')
        pt++;
    if (*pt == '\n')
        return YES;

    /* find the first ']' or ')' */
    while ((*pt == '(' || *pt == '[' || *pt == ' ') && *pt != '\n')
        pt++;
    if (*pt == '\n')
        return NO;

    /* () string */
    if (*pt == ')') {
        while (*pt != '(' && pt != s && *pt !='[')
            pt--;
        /* have no pair */
        if (*pt != '(' && pt == s || *pt == '[')
            return NO;
        if (*pt == '(')
            for (; *pt != ')'; pt++)
                *pt = ' ';
        *pt = ' ';
    }

    /* [] string */
    if (*pt == ']') {
        while (*pt != '[' && pt != s && *pt !='(')
            pt--;
        /* have no pair */
        if (*pt != '[' && pt == s || *pt == '(')
            return NO;
        if (*pt == '[')
            for (; *pt != ']'; pt++)
                *pt = ' ';
        *pt = ' ';
    }

    pairs(s);
}

