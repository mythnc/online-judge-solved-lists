#include <stdio.h>
#include <stdlib.h>

#define MAXDOG 500000

typedef struct dog {
    char name[11];
    int atk;
} Dog;

void output(Dog *dogs, int n);
void capture(Dog *dogs, int n);

int main(void)
{
    char c;
    Dog dogs[MAXDOG];
    int i;

    i = 0;
    while (scanf("%c%*c", &c) && c != 'e') {
        switch (c) {
            case 'a':
                scanf("%s %d%*c", dogs[i].name, &dogs[i].atk);
                i++;
                break;
            case 's':
                output(dogs, i);
                break;
            case 'c':
                capture(dogs, i);
        }
    }
    return 0;
}

void output(Dog *dogs, int n)
{
    int max_atk, max_i, i;

    max_atk = -1;
    for (i = n - 1; i >= 0; i--) {
        if (dogs[i].atk > max_atk) {
            max_i = i;
            max_atk = dogs[i].atk;
        }
    }

    if (max_atk == -1)
        printf("Null\n");
    else
        printf("%s\n", dogs[max_i].name);
}

void capture(Dog *dogs, int n)
{
    int max_atk, max_i, i;

    max_atk = -1;
    for (i = n - 1; i >= 0; i--) {
        if (dogs[i].atk > max_atk) {
            max_i = i;
            max_atk = dogs[i].atk;
        }
    }

    if (max_atk == -1)
        return;
    else
        dogs[max_i].atk = -1;
}

