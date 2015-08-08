#include <stdio.h>
#include <string.h>

#define MAXATK 100
#define MAXDOG 5000
#define MAXNAME 11

void push(int atk, char *name);
void show(void);
void capture(void);

char stack[MAXATK][MAXDOG][MAXNAME];
int top[MAXATK];

int main(void)
{
    char c;
    char name[11];
    int atk;

    while (scanf("%c%*c", &c) && c != 'e') {
        switch (c) {
            case 'a':
                scanf("%s %d%*c", name, &atk);
                push(atk, name);
                break;
            case 's':
                show();
                break;
            case 'c':
                capture();
        }
    }
    return 0;
}

void push(int atk, char *name)
{
    strcpy(stack[atk][top[atk]++], name);
}

void show(void)
{
    int i;

    for (i = MAXATK - 1; i >= 0; i--) {
        if (top[i] > 0) {
            printf("%s\n", stack[i][top[i] - 1]);
            return;
        }
    }
    printf("Null\n");
}

void capture(void)
{
    int i;

    for (i = MAXATK - 1; i >= 0; i--) {
        if (top[i] > 0) {
            top[i]--;
            return;
        }
    }
}

