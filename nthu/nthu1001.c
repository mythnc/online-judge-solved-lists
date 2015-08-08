#include <stdio.h>
#include <string.h>

#define MAXN 1000

void input(int *a, int *b, int n);
void add(int *a, int *b, int *c, int n);
int get_index(char *o, int i);
void output(int *c, int n);

int main(void)
{
    int test_case;
    int i, j, n;
    int a[MAXN], b[MAXN], c[MAXN];

    scanf("%d", &test_case);
    for (i = 0; i < test_case; i++) {
        scanf("%d", &n);
        input(a, b, n);
        add(a, b, c, n);
        output(c, n);
    }

    return 0;
}

void input(int *a, int *b, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
}

void add(int *a, int *b, int *c, int n)
{
    char o[MAXN];
    int b_i, c_i;
    int i;

    scanf("%s", o);
    b_i = get_index(o, 1);
    c_i = get_index(o, b_i + 2);
    // printf("b: %d, c: %d\n", b_i, c_i);

    for (i = 0; i < n; i++) {
        c[(i + c_i) % n] = a[i] + b[(i + b_i) % n];
    }
}

int get_index(char *o, int i)
{
    int count;

    for (count = 0; i < strlen(o); i++, count++) {
        if (o[i] == '1')
            break;
    }
    return count;
}

void output(int *c, int n)
{
    int i;

    printf("%d", c[0]);
    for (i = 1; i < n; i++) {
        printf(" %d", c[i]);
    }
    putchar('\n');
}

