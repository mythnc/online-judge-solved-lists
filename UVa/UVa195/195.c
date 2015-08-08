/* ACM 195 Anagram
 * mythnc
 * 2012/01/08 21:33:59   
 * run time: 0.044
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXCHAR 1000
#define TRUE    1
#define FALSE   0

void sort(char *, int);
void backtrack(int);
int cmp(const void *a, const void *b);

char input[MAXCHAR], output[MAXCHAR];
int visited[MAXCHAR];

int main(void)
{
    scanf("%*d");
    while (scanf("%s", &input) == 1) {
        sort(input, strlen(input));
        backtrack(0);
    }

    return 0;
}

/* sort: sort s in alphabetically order:
 * A > a > B > b > .... > Z > z */
void sort(char *s, int n)
{
    char upper[MAXCHAR], lower[MAXCHAR];
    int i, j, k, up, low;

    for (i = up = low = 0; i < n; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            upper[up++] = s[i];
        else
            lower[low++] = s[i];
    /* sort each array */
    qsort(upper, up, sizeof(char), cmp);
    qsort(lower, low, sizeof(char), cmp);
    i = j = k = 0;
    /* copy back to s (in sorted order) */
    while (k < low && j < up)
        if (lower[k] - 'a' + 'A' < upper[j])
            s[i++] = lower[k++];
        else
            s[i++] = upper[j++];
    while (k < low)
            s[i++] = lower[k++];
    while (j < up)
            s[i++] = upper[j++];
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

