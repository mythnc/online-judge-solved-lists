/* ACM 156 Ananagrams
 * mythnc
 * 2011/12/25 20:30:50   
 * run time: 0.008
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXL  21
#define FALSE 0
#define TRUE  1

typedef struct token {
    int tag, len;
    char word[MAXL];
    struct token *next;
} Token;

Token *input(void);
int ananagrams(Token *, char *);
int sameletter(char *, char *);
void *deletetag(Token **);
void *sort(Token **);
void output(Token *);
void freel(Token *);

int main(void)
{
    Token *head;

    head = input();
    deletetag(&head);
    sort(&head);
    output(head);
    freel(head);

    return 0;
}

/* input: eat input token */
Token *input(void)
{
    char word[MAXL];
    Token *tmp, *head, *current;

    head = current = NULL;
    while (scanf("%s", word) && word[0] != '#') {
        if (head && !ananagrams(head, word))
            continue;
        tmp = (Token *)malloc(sizeof(Token));
        if (!head)
            head = tmp;
        strcpy(tmp->word, word);
        tmp->len = strlen(word);
        tmp->tag = FALSE;
        tmp->next = NULL;
        if (current)
            current->next = tmp;
        current = tmp;
    }

    return head;
}

/* ananagrams: compare word in ll vs w,
 * if they are anagrams return FALSE
 * else return TRUE */
int ananagrams(Token *pt, char *w)
{
    while (pt) {
        if (pt->len == strlen(w) && sameletter(pt->word, w)) {
            pt->tag = TRUE;
            return FALSE;
        }
        pt = pt->next;
    }

    return TRUE;
}

/* sameletter: if s and t have same letter
 * return TRUE else return FALSE */
int sameletter(char *s, char *t)
{
    int letters[26] = { 0 };
    int i;

    for (i = 0; i < strlen(s); i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            letters[s[i] - 'A']++;
        /* lowercase */
        else
            letters[s[i] - 'a']++;

    for (i = 0; i < strlen(t); i++)
        if (t[i] >= 'A' && t[i] <= 'Z') {
            if (letters[t[i] - 'A'] == 0)
                return FALSE;
            letters[t[i] - 'A']--;
        }
        /* lowercase */
        else {
            if (letters[t[i] - 'a'] == 0)
                return FALSE;
            letters[t[i] - 'a']--;
        }

    return TRUE;
}

/* deletetag: if tag == TRUE, delete it */
void *deletetag(Token **head)
{
    Token *pre, *pt, *tmp;

    pre = NULL;
    pt = *head;
    while (pt) {
        if (pt->tag) {
            if (!pre) {
                tmp = *head;
                *head = (*head)->next;
            }
            else {
                tmp = pt;
                pre->next = pt->next;
            }
            free(tmp);
            pt = pt->next;
            continue;
        }
        pre = pt;
        pt = pt->next;
    }
}

/* sort: insertion sort linked list */
void *sort(Token **head)
{
    Token *i, *j, *pre, *tmpi, *tmpj;

    for (i = (*head)->next; i; i = i->next) {
        tmpi = i;
        for (j = *head, pre = NULL; j != tmpi; pre = j, j = j->next)
            if (strcmp(tmpi->word, j->word) < 0) {
                if (pre)
                    pre->next = tmpi;
                else
                    *head = tmpi;
                tmpj = j;
                while (tmpj->next != tmpi)
                    tmpj = tmpj->next;
                tmpj->next = tmpi->next;
                tmpi->next = j;
                break;
            }
    }
}

/* output: output result */
void output(Token *pt)
{
    for (; pt; pt = pt->next)
        printf("%s\n", pt->word);
}

/* free: free linked list */
void freel(Token *pt)
{
    Token *tmp;

    while (pt) {
        tmp = pt;
        free(tmp);
        pt = pt->next;
    }
}

