/* ACM 727 Equation
 * mythnc
 * 2012/01/13 09:44:34
 * run time: 0.136
 */
#include <stdio.h>
#include <string.h>

#define LINEMAX  10
#define MAXSTACK 50

void postfix(void);
void pop(void);
void push(char *);

char stack[LINEMAX][MAXSTACK];
int count;

int main(void)
{
    scanf("%*d");
    getchar();
    getchar();
    postfix();

    return 0;
}

/* postfix: infix to postfix */
void postfix(void)
{
    char line[LINEMAX];

    count = 0;
    while (fgets(line, LINEMAX, stdin)) {
        line[strlen(line) - 1] = '\0';
        /* operator */
        if (line[0] == '+' || line[0] == '-' && strlen(line) == 1) {
            while (count > 0 && stack[count - 1][0] != '(')
                pop();
            push(line);
        }
        else if (line[0] == '*' || line[0] == '/') {
            while (count > 0 && stack[count - 1][0] != '('
                   && stack[count - 1][0] != '+' && stack[count - 1][0] != '-')
                pop();
            push(line);
        }
        else if (line[0] == '(')
            push(line);
        else if (line[0] == ')') {
            while (stack[count - 1][0] != '(')
                pop();
            count--;
        }
        /* terminal condition */
        else if (line[0] == '\0') {
            while (count != 0)
                pop();
            printf("\n\n");
        }
        /* operand */
        else
            printf("%s", line);
    }
    while (count != 0)
        pop();
    putchar('\n');
}

/* pop: print out the top element */
void pop(void)
{
    printf("%s", stack[--count]);
}

/* push: push line to stack */
void push(char *line)
{
    strcpy(stack[count++], line);
}

