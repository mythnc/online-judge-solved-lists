/* ACM 482 Permutation Array
 * mythnc
 * 2012/01/11 12:37:57   
 * run time: 0.008
 */
#include <stdio.h>

#define MAX  1000
#define MAXC 30

int input1(int *);
void input2(int *, char (*)[], int);
void output(char (*)[], int);

int main(void)
{
    int set, n, i;
    int index[MAX];
    char list[MAX][30];

    scanf("%d", &set);
    for (i = 0; i < set; i++) {
        getchar();
        getchar();
        if (i > 0)
            putchar('\n');
        n = input1(index);
        input2(index, list, n);
        output(list, n);
    }

    return 0;
}

/* input1: eat list and return n */
int input1(int *index)
{
    int i;
    char line[MAX];
    char c;

    i = 0;
    while (scanf("%s%c", line, &c) == 2) {
        sscanf(line, "%d", &index[i]);
        i++;
        if (c == '\n')
            return i;
    }
}

/* input2: eat string */
void input2(int *index, char (*list)[MAXC], int n)
{
    int i;

    for (i = 0; i < n; i++)
        scanf("%s", list[index[i] - 1]);
}

/* output: output results */
void output(char (*list)[MAXC], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%s\n", list[i]);
}

