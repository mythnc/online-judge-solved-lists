/* ACM 10929 You can say 11
 * mythnc
 * 2011/11/19 22:51:54   
 * run time: 0.016
 */
#include <stdio.h>

#define MAXCHAR 1001

int mul11(char *);

int main(void)
{
    char s[MAXCHAR];

    while (scanf("%s", s) == 1 && (s[0] != '0' || s[1] != '\0'))
        if (mul11(s))
            printf("%s is a multiple of 11.\n", s);
        else
            printf("%s is not a multiple of 11.\n", s);

    return 0;
}

/* mul11: return 1 if s can be expressed 11n
 * else return 0 */
int mul11(char *s)
{
    int i, odd, even;

    for (i = odd = even = 0; s[i] != '\0'; i++)
        if (i % 2 == 0)
            odd += s[i] - '0';
        else
            even += s[i] - '0';

    return (odd - even)% 11 == 0;
}

