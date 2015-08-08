/* ACM 484 The Department of Redundancy Department
 * mythnc
 * 2011/11/20 14:10:46   
 * run time: 0.480
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct number {
    int name;
    int count;
    struct number *next;
} Number;

Number *addnumber(int, Number *);
void print(Number *);
void freenumber(Number *);

int main(void)
{
    Number *root;
    int n;

    root = NULL;
    while (scanf("%d", &n) == 1)
        root = addnumber(n, root);

    print(root);
    freenumber(root);

    return 0;
}

/* addnumber: add number in p */
Number *addnumber(int n, Number *p)
{
    if (p == NULL) {
        p = (Number *)malloc(sizeof(Number));
        p->name = n;
        p->count = 1;
        p->next = NULL;
    }
    else if (p->name == n)
        p->count++;
    else
        p->next = addnumber(n, p->next);

    return p;
}

/* print: print p */
void print(Number *p)
{
    while (p != NULL) {
        printf("%d %d\n", p->name, p->count);
        p = p->next;
    }
}

/* freenumber: free p */
void freenumber(Number *p)
{
    Number *tmp;

    while (p != NULL) {
        tmp = p;
        free(tmp);
        p = p->next;
    }
}

