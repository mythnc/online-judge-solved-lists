/* ACM 10420 List of Conquests
 * mythnc
 * 2012/01/03 10:19:51   
 * run time: 0.016
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINEMAX 80
#define MAXCHAR 20

typedef struct woman {
    char *name;
    struct woman *next;
} Woman;

typedef struct node {
    char country[MAXCHAR];
    int count;
    Woman *list;
    struct node *left, *right;
} Tnode;

void token(char *, char *);
Tnode *addtree(Tnode *, char *, char *);
Woman *addwoman(Woman *, char *, int *);
void printtree(Tnode *);
void freetree(Tnode *);

int main(void)
{
    char name[LINEMAX];
    char country[MAXCHAR];
    Tnode *root;

    root = NULL;
    scanf("%*d");
    getchar();
    while (fgets(name, LINEMAX, stdin)) {
        token(country, name);
        root = addtree(root, country, name);
    }
    printtree(root);
    freetree(root);

    return 0;
}

/* token: split name to country and woman name */
void token(char *country, char *name)
{
    char *pt;

    sscanf(name, "%s", country);
    pt = name + strlen(country);
    while (*pt == ' ')
        pt++;
    strcpy(name, pt);
    pt = name + strlen(name);
    while (*(pt - 1) == '\n' || *(pt - 1) == ' ')
        pt--;
    *pt = '\0';
}

/* addtree: add country and name into bin search tree */
Tnode *addtree(Tnode *pt, char *country, char *name)
{
    int i;

    if (pt == NULL) {
        pt = (Tnode *)malloc(sizeof(Tnode));
        strcpy(pt->country, country);
        pt->left = pt->right = NULL;
        pt->count = 0;
        pt->list = NULL;
        pt->list = addwoman(pt->list, name, &pt->count);
    }
    else if ((i = strcmp(country, pt->country)) == 0)
        pt->list = addwoman(pt->list, name, &pt->count);
    else if (i < 0)
        pt->left = addtree(pt->left, country, name);
    else
        pt->right = addtree(pt->right, country, name);

    return pt;
}

/* addwoman: add woman name into list */
Woman *addwoman(Woman *head, char *name, int *count)
{
    Woman *pt;

    for (pt = head; pt; pt = pt->next)
        if (strcmp(pt->name, name) == 0)
            return head;

    pt = (Woman *)malloc(sizeof(Woman));
    pt->next = NULL;
    pt->name = (char *)malloc(strlen(name) + 1);
    strcpy(pt->name, name);
    ++*count;
    
    return head;
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

/* freetree: free() all nodes */
void freetree(Tnode *pt)
{
    Woman *tmp;

    if (pt == NULL)
        return;

    freetree(pt->left);
    freetree(pt->right);
    while (pt->list) {
        tmp = pt->list;
        pt->list = pt->list->next;
        free(tmp->name);
        free(tmp);
    }
    free(pt);
}

