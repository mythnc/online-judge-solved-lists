/* ACM 673 Parentheses Balance
 * mythnc
 * 2011/11/04 18:37:08   
 * run time: 0.024
 */
#include <stdio.h>

#define MAXCHAR 130
#define YES     1
#define NO      0

int pair(char *);

int main(void)
{
    int n;
    char s[MAXCHAR];

    scanf("%d\n", &n);
    while (n--) {
        fgets(s, MAXCHAR, stdin);
        if (pair(s) == YES)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}

/* pair: if () or [] is pair return YES,
 * else return NO */
int pair(char *s)
{
    int i, count;
    char stack[MAXCHAR];

    for (count = i = 0; s[i] != '\n'; i++)
        if (s[i] == '(' || s[i] == '[')
            stack[count++] = s[i];
        else if (s[i] == ')') {
            if (count == 0 || stack[--count] != '(')
                return NO;
        }
        else if (s[i] == ']')
            if (count == 0 || stack[--count] != '[')
                return NO;

    if (count == 0)
        return YES;
    else
        return NO;
}

