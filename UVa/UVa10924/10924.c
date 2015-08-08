/* ACM 10924 Prime Words
 * mythnc
 * 2011/11/18 09:56:41   
 * run time: 0.004
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXCHAR 21
#define TRUE    1
#define FALSE   0

int sumw(char *);
int prime(int n);

int main(void)
{
    char str[MAXCHAR];

    while (scanf("%s", str) == 1) {
        if (prime(sumw(str)))
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");
    }
    return 0;
}

/* sumw: sum of the word letters */
int sumw(char *s)
{
    int i, sum;

    for (i = sum = 0; i < strlen(s); i++)
        if (s[i] >= 'a' && s[i] <= 'z')
            sum += s[i] - 'a' + 1;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            sum += s[i] - 'A' + 27;

    return sum;
}

/* prime: return TRUE if n is prime,
 * else return FALSE */
int prime(int n)
{
    int i;

    if (n == 2)
        return TRUE;

    if (n % 2 == 0)
        return FALSE;

    for (i = 3; i <= sqrt(n); i += 2)
        if (n % i == 0)
            return FALSE;

    return TRUE;
}

