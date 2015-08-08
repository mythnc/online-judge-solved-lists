/* ACM 10921 Find the Telephone
 * mythnc
 * 2011/11/21 12:12:59   
 * run time: 0.004
 */
#include <stdio.h>

#define MAXCHAR 31

void trans(char *);

int main(void)
{
    char s[MAXCHAR];

    while (scanf("%s", s) == 1) {
        trans(s);
        printf("%s\n", s);
    }
    return 0;
}

/* trans: translate s into the form of telephone number */
void trans(char *s)
{
    int i;
    char map[] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5',
                  '5', '5', '6', '6', '6', '7', '7', '7', '7', '8',
                  '8', '8', '9', '9', '9', '9'};

    for (i = 0; s[i] != '\0'; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = map[s[i] - 'A'];
}

