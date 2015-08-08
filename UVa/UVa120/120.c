/* ACM 120 Stacks of Flapjacks
 * mythnc
 * 2011/11/11 19:12:46   
 * run time: 0.008
 */
#include <stdio.h>

#define MAXN 30
#define MAXS 5

void input(int *, int);
void sort(int *, int);
int findmax(int *, int);
void reverse(int *, int, int);

int main(void)
{
    int stack[MAXN];
    int count;
    char str[MAXS];
    char c;

    count = 0;
    while (scanf("%s%c", str, &c) == 2) {
        sscanf(str, "%d", &stack[count++]);
        if (c == '\n') {
            input(stack, count);
            sort(stack, count);
            printf("0\n");
            count = 0;
        }
    }
    return 0;
}

/* input: print input */
void input(int *s, int n)
{
    int i;

    printf("%d", s[0]);
    for (i = 1; i < n; i++)
        printf(" %d", s[i]);
    printf("\n");
}

/* sort: sort s in ascended */
void sort(int *s, int n)
{
    int i, max;

    for (i = n - 1; i > 0; i--) {
        max = findmax(s, i + 1);
        if (max == i)
            continue;
        if (max != 0)
            reverse(s, max, n);
        reverse(s, i, n);
    }
}

/* findmax: return the index of max element */
int findmax(int *s, int n)
{
    int i, max;

    for (i = max = 0; i < n; i++)
        if (s[i] > s[max])
            max = i;

    return max;
}

/* reverse: reverse s from [0] to [index] */
void reverse(int *s, int index, int n)
{
    int i, j, tmp;

    printf("%d ", n - index);

    for (i = 0, j = index; i < j; i++, j--) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

