/* ACM 514 Rails
 * mythnc
 * 2012/01/12 21:22:57   
 * run time: 0.076
 */
#include <stdio.h>

#define MAX 1000

typedef enum {FALSE = 0, TRUE} bool;

void init(int *, int);
bool input(int *, int);
bool simulate(int *, int *, int);
void push(int);
int pop(void);
int top(void);

int stack[MAX];
int count;

int main(void)
{
    int n;
    int list[MAX], cmp[MAX];

    while (scanf("%d", &n) && n != 0) {
        init(list, n);
        while (input(cmp, n))
            if (simulate(list, cmp, n))
                printf("Yes\n");
            else
                printf("No\n");
        putchar('\n');
    }

    return 0;
}

/* init: initialize list */
void init(int *list, int n)
{
    int i;

    for (i = 0; i < n; i++)
        list[i] = i + 1;
}

/* input: receive input data */
bool input(int *cmp, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        scanf("%d", &cmp[i]);
        if (cmp[i] == 0)
            return FALSE;
    }

    return TRUE;
}

/* simulate: simulate coaches state */
bool simulate(int *list, int *cmp, int n)
{
    int i, j;
    
    for (i = j = count = 0; i < n; i++) {
        if (j < n && list[j] == cmp[i])
            j++;
        else if (count != 0 && top() == cmp[i])
            pop();
        else if (j < n && list[j] != cmp[i]) {
            while (j < n && cmp[i] != list[j])
                push(list[j++]);
            if (j == n || list[j] != cmp[i])
                return FALSE;
            j++;
        }
        else
            return FALSE;
    }

    return TRUE;
}

/* push: push x in top */
void push(int x)
{
    stack[count++] = x;
}

/* pop: pop the top value */
int pop(void)
{
    return stack[--count];
}

/* top: return top value */
int top(void)
{
    return stack[count - 1];
}

