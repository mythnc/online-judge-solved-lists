/* ACM 10420 List of Conquests
 * mythnc
 * 2012/01/03 10:19:51   
 * run time: 0.008
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINEMAX 80
#define MAXCHAR 20

typedef struct node {
    char country[MAXCHAR];
    int count;
    struct node *left, *right;
} Tnode;

Tnode *addtree(Tnode *, char *);
void printtree(Tnode *);

int main(void)
{
    char name[LINEMAX];
    char country[MAXCHAR];
    Tnode *root;

    root = NULL;
    scanf("%*d");
    getchar();
    while (fgets(name, LINEMAX, stdin)) {
        sscanf(name, "%s", country);
        root = addtree(root, country);
    }
    printtree(root);

    return 0;
}

/* addtree: add country and name into bin search tree */
Tnode *addtree(Tnode *pt, char *country)
{
    int i;

    if (pt == NULL) {
        pt = (Tnode *)malloc(sizeof(Tnode));
        strcpy(pt->country, country);
        pt->left = pt->right = NULL;
        pt->count = 1;
    }
    else if ((i = strcmp(country, pt->country)) == 0)
        pt->count++;
    else if (i < 0)
        pt->left = addtree(pt->left, country);
    else
        pt->right = addtree(pt->right, country);

    return pt;
}

/* printtree: print out bin search tree */
void printtree(Tnode *pt)
{
    if (pt == NULL)
        return;

    printtree(pt->left);
    printf("%s %d\n", pt->country, pt->count);
    printtree(pt->right);
}

