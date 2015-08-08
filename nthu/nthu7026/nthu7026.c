#include <stdio.h>
#include <stdlib.h>

typedef struct dog {
    char name[11];
    int atk;
    struct dog *next;
} Dog;

void insert(Dog **head, Dog *new);
void output(Dog *head);
void capture(Dog **head);

int main(void)
{
    char c;
    char name[11];
    int atk;
    Dog *head = NULL;
    Dog *new;

    while (scanf("%c%*c", &c) && c != 'e') {
        switch (c) {
            case 'a':
                new = (Dog*)malloc(sizeof(Dog));
                new->next = NULL;
                scanf("%s %d%*c", new->name, &new->atk);
                /* printf("%s %d\n", new->name, new->atk); */
                insert(&head, new);
                break;
            case 's':
                output(head);
                break;
            case 'c':
                capture(&head);
        }
    }
    return 0;
}

void insert(Dog **head, Dog *new)
{
    Dog *pt = *head;

    /* No dog */
    if (pt == NULL) {
        *head = new;
        return;
    }
    
    /* one dog */
    if (new->atk >= pt->atk) {
        *head = new;
        new->next = pt;
        return;
    }

    /* middle */
    while (pt->next != NULL) {
        if (new->atk >= pt->next->atk) {
            new->next = pt->next;
            pt->next = new;
            return;
        }
        pt = pt->next;
    }

    /* last */
    pt->next = new;
}

void output(Dog *head)
{
    if (head == NULL)
        printf("Null\n");
    else
        printf("%s\n", head->name);
}

void capture(Dog **head)
{
    if (*head == NULL)
        return;

    *head = (*head)->next;
}

