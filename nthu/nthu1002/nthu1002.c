#include <stdio.h>
#include <string.h>

#define MAXS 1000010

void output(char *s);


int main(void)
{
    char s[MAXS];
    int c;

    while (scanf("%s", s) != EOF) {
        output(s);
    }
    return 0;
}

void output(char *s)
{
    int i;

    for (i = strlen(s) - 1; i >= 0; i--) {
        putchar(s[i]);
    }
    putchar('\n');
}

