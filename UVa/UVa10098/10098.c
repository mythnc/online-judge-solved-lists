/* ACM 10098 Generating Fast
 * mythnc
 * 2012/01/08 22:17:54
 * run time: 0.108
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXCHAR 11
#define TRUE    1
#define FALSE   0

void backtrack(int);
int cmp(const void *a, const void *b);

char input[MAXCHAR], output[MAXCHAR];
int visited[MAXCHAR];

int main(void)
{
    scanf("%*d");
    while (scanf("%s", &input) == 1) {
        qsort(input, strlen(input), sizeof(char), cmp);
        backtrack(0);
        putchar('\n');
    }

    return 0;
}

/* backtrack: do backtrack to producing answer */
void backtrack(int i)
{
    int j;

    /* output */
    if (input[i] == '\0') {
        output[i] = '\0';
        printf("%s\n", output);
        return;
    }
    /* clear the previous content in output[i] */
    output[i] = -1;
    for (j = 0; input[j] != '\0'; j++)
        if (!visited[j] && input[j] != output[i]) {
            visited[j] = TRUE;
            output[i] = input[j];
            backtrack(i + 1);
            visited[j] = FALSE;
        }
}

/* cmp: for qsort() */
int cmp(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}

