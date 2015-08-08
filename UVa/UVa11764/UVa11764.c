#include <stdio.h>

#define MAXWALL 50

typedef struct jump {
    int high;
    int low;
} Jump;

void input(int *wall, int n);
Jump cal(int *wall, int n);
void output(Jump j, int i);

int main(void)
{
    int i, t, n;
    Jump j;
    int wall[MAXWALL];

    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        scanf("%d", &n);
        input(wall, n);
        j = cal(wall, n);
        output(j, i+1);
    }
    return 0;
}

void input(int *wall, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        scanf("%d", &wall[i]);
    }
}

Jump cal(int *wall, int n)
{
    int i;
    Jump j;

    for (i = j.high = j.low = 0; i < n - 1; i++) {
        if (wall[i] < wall[i+1])
            j.high++;
        else if (wall[i] > wall[i+1])
            j.low++;
    }
    return j;
}

void output(Jump j, int i)
{
    printf("Case %d: %d %d\n", i, j.high, j.low);
}

