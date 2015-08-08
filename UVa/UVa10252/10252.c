/* ACM 10252 Common Permutation
 * mythnc
 * 2011/12/09 08:57:30   
 * run time: 0.012
 */
#include <stdio.h>
#include <string.h>

#define MAXCHAR  1002
#define ALPHABET 26

void countl(char *, int *);
void output(int *, int *);

int main(void)
{
    char line[MAXCHAR];
    int p1[ALPHABET], p2[ALPHABET];

    while (fgets(line, MAXCHAR, stdin)) {
        memset(p1, 0, sizeof(p1));
        countl(line, p1);
        fgets(line, MAXCHAR, stdin);
        memset(p2, 0, sizeof(p2));
        countl(line, p2);
        output(p1, p2);
    }

    return 0;
}

/* countl: count letter numbers */
void countl(char *line, int *p)
{
    int i;

    for (i = 0; i < strlen(line) - 1; i++)
        if (line[i] >= 'a' && line[i] <= 'z')
            p[line[i] - 'a']++;
}

/* output: output result in alphabetical order */
void output(int *p1, int *p2)
{
    int i;

    for (i = 0; i < ALPHABET; i++)
        for (; p1[i] > 0 && p2[i] > 0; p1[i]--, p2[i]--)
                printf("%c", 'a' + i);
    putchar('\n');
}

