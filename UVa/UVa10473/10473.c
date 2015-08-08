/* ACM 10473 Simple Base Conversion
 * mythnc
 * 2011/12/20 10:18:59   
 * run time: 0.016
 */
#include <stdio.h>

#define MAXCHAR 11

int main(void)
{
    char s[MAXCHAR];
    int n;

    while (scanf("%s", s) == 1) {
        /* hex to dec */
        if (s[1] == 'x') {
            sscanf(s, "%x", &n);
            printf("%d\n", n);
            continue;
        }
        /* dec to hex */
        sscanf(s, "%d", &n);
        if (n < 0)
            break;
        printf("0x%X\n", n);
    }

    return 0;
}

