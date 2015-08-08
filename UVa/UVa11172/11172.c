/* ACM 11172 Relational Operators
 * mythnc
 * 2011/11/01 18:35:45   
 * run time: 0.008
 */
#include <stdio.h>

int main(void)
{
    int a, b;

	scanf("%*d");
    while (scanf("%d %d", &a, &b) == 2)
        if (a > b)
            printf(">\n");
        else if (a == b)
            printf("=\n");
        else
            printf("<\n");

    return 0;
}

