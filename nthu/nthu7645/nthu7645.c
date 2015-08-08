#include <stdio.h>
#include <string.h>

#define MAXCHAR 16
#define MAX(X, Y) ((X >= Y) ? (X) : (Y))
#define MIN(X, Y) ((X < Y) ? (X) : (Y))

void output(char *a, char *b);

int main(void)
{
    char a[MAXCHAR], b[MAXCHAR];

    scanf("%*d");
    while (scanf("%s %s", a, b) == 2) {
        /* printf("%s %s\n", a, b); */
        output(a, b);
    }
    return 0;
}

void output(char *a, char *b)
{
    int len_a, len_b, max, min, space;
    int i;

    len_a = strlen(a);
    len_b = strlen(b);
    max = MAX(len_a, len_b);
    min = MIN(len_a, len_b);
    space = (max - min) / 2;

    if (len_a != max)
        for (i = 0; i < space; i++)
            putchar(' ');
    printf("%s\n", a);

    for (i = 0; i < max; i++) {
        putchar('-');
    }
    putchar('\n');

    if (len_b != max)
        for (i = 0; i < space; i++)
            putchar(' ');
    printf("%s\n\n", b);
}

