/* ACM 10260 Soundex
 * mythnc
 * 2011/11/19 21:42:21   
 * run time: 0.004
 */
#include <stdio.h>

#define MAXCHAR 20

void print(char *);

int main(void)
{
    char str[MAXCHAR];
    
    while (scanf("%s", str) == 1)
        print(str);
    return 0;
}

/* print: print out sounedex code */
void print(char *s)
{
    int map[26] = {0, 1, 2, 3, 0,
                   1, 2, 0, 0, 2,
                   2, 4, 5, 5, 0,
                   1, 2, 6, 2, 3,
                   0, 1, 0, 2, 0, 2};

    int stack, i;

    for (stack = -1, i = 0; s[i] != '\0'; i++)
        if (stack != map[s[i] - 'A'])
            if (map[s[i] - 'A'] != 0) {
                printf("%d", map[s[i] - 'A']);
                stack = map[s[i] - 'A'];
            }
            else
                stack = -1;
    putchar('\n');
}

