#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN   10
#define UNUSED  0
#define USED    1

void input(int *seq, int *record, int n);
void com(int n, int m, int i, int *record, int *seq, int *output);
void print(int *output, int m);
int cmp(const void *a, const void *b);

int main(void)
{
    int test_case;
    int seq[MAXN], record[MAXN], output[MAXN];
    int m, n, i;

    scanf("%d", &test_case);
    for (i = 0; i < test_case; i++) {
        scanf("%d %d", &n, &m);
        input(seq, record, n);

        qsort(seq, n, sizeof(int), cmp);

        // output
        printf("Case %d:\n", i + 1);
        com(n, m, 0, record, seq, output);
    }

    return 0;
}

void input(int *seq, int *record, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        scanf("%d", seq + i);
        record[i] = UNUSED;
    }
}

int cmp(const void *a, const void *b)
{
    return (*(int *)a) - (*(int *)b);
}


void com(int n, int m, int i, int *record, int *seq, int *output)
{
    if (i == m) {
        print(output, m);
        return;
    }
    int j;
    for (j = 0; j < n; j++) {
        if (record[j] == UNUSED && i < m) {
            record[j] = USED;
            output[i] = seq[j];
            com(n, m, i + 1, record, seq, output);
            record[j] = UNUSED;
        }
    }
}

void print(int *output, int m)
{
    int i;

    for (i = 0; i < m; i++) {
        printf("%d", output[i]);
    }
    putchar('\n');
}
