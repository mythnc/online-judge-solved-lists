/* ACM 112 Tree Summing
 * mythnc
 * 2011/12/18 19:06:31   
 * run time: 0.064
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXCHAR 11
#define MAXN    1000
#define TRUE    1
#define FALSE   0

typedef struct node {
    char value[MAXCHAR];
    struct node *left, *right;
} Node;

Node *addtree(void);
void traversal(Node *, int *, int *);
int contain(int, int *, int);
void freet(Node *);

int stack[MAXN];
int stc;

int main(void)
{
    Node *root;
    int n, c, count;
    int sumall[MAXN];

    while (scanf("%d", &n) == 1) {
        /* find the 1st '(' */
        while ((c = getchar()) != '(')
            ;
        root = addtree();
        count = 0;
        traversal(root, sumall, &count);
        if (contain(n, sumall, count)) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
        freet(root);
    }

    return 0;
}

/* addtree: add node to root */
Node *addtree(void)
{
    Node *tmp;
    int c, left, vcount;

    tmp = (Node *)malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    left = FALSE;
    vcount = 0;
    while ((c = getchar()) != ')') {
        /* left node */
        if (c == '(' && !left) {
            tmp->left = addtree();
            left = TRUE;
        }
        /* right node */
        else if (c == '(' && left) {
            tmp->right = addtree();
        }
        /* integer */
        else if (isdigit(c) || c == '-') {
            tmp->value[vcount] = c;
            tmp->value[++vcount] = '\0';
        }
    }
    if (vcount == 0) {
        free(tmp);
        return NULL;
    }
    return tmp;
}

/* traversal: traversal the tree */
void traversal(Node *pt, int *sumall, int *count)
{
    int i, sum;
    /* empty tree */
    if (pt == NULL) {
        return;
    }
    /* leaf node: left and right are NULL */
    if (pt->left == pt->right) {
        for (sum = i = 0; i < stc; i++) {
            sum += stack[i];
        }
        sumall[(*count)++] = sum + atoi(pt->value);
        return;
    }
    /* push */
    stack[stc++] = atoi(pt->value);
    traversal(pt->left, sumall, count);
    traversal(pt->right, sumall, count);
    /* pop */
    stc--;
}

/* contain: if n contain in sumall,
 * return TRUE, else return FALSE */
int contain(int n, int *sumall, int count)
{
    int i;
    /* negative */
    if (count == 0 && n < 0) {
        return FALSE;
    }

    for (i = 0; i < count; i++) {
        if (sumall[i] == n) {
            return TRUE;
        }
    }
    return FALSE;
}

/* freet: free all node */
void freet(Node *pt)
{
    if (pt == NULL) {
        return;
    }
    freet(pt->left);
    freet(pt->right);
    free(pt);
}

