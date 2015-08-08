/* ACM 10424 Love Calculator
 * mythnc
 * 2011/12/03 09:29:34   
 * run time: 0.004
 */
#include <stdio.h>

#define MAXCHAR 27 /* 25 + '\n' + '\0' */

double value(char *);
int onedigit(int);

int main(void)
{
    char name[2][MAXCHAR];
    double v[2];
    int i;

    while (fgets(name[0], MAXCHAR, stdin)) {
        fgets(name[1], MAXCHAR, stdin);
        for (i = 0; i < 2; i++)
            v[i] = value(name[i]);
        if (v[0] >= v[1])
            printf("%.2f %%\n", 100 * v[1] / v[0]);
        else
            printf("%.2f %%\n", 100 * v[0] / v[1]);
    }

    return 0;
}

/* value: return the value of name */
double value(char *s)
{
    int i, sum;

    for (i = sum = 0; s[i] != '\n'; i++)
        if (s[i] >= 'a' && s[i] <= 'z')
            sum += s[i] - 'a' + 1;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            sum += s[i] - 'A' + 1;

    while (sum > 9)
        sum = onedigit(sum);

    return (double)sum;
}

/* onedigit: make sure n is one digit */
int onedigit(int n)
{
    int sum;

    for (sum = 0; n != 0;) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

