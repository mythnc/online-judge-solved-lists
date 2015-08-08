/* ACM 488 Triangle Wave
 * mythnc
 * 2011/11/02 21:48:29   
 * run time: 0.44
 */
#include <stdio.h>

void triangle(int);

int main(void)
{
    int height, time, set, i;

    scanf("%*d");
    set = 0;
    while (scanf("%d %d", &height, &time) == 2) {
        if (set > 0)
            printf("\n");
        for (i = 0; i < time; i++) {
            if (i > 0)
                printf("\n");
            triangle(height);
        }
        set++;
    }
    return 0;
}

/* triangle: print out triangle */
void triangle(int h)
{
    int i, j;

    for (i = 1; i < h + 1; i++) {
        for (j = 0; j < i; j++)
            printf("%d", i);
        printf("\n");
    }

    for (i = h - 1; i > 0; i--) {
        for (j = i - 1; j > -1; j--)
            printf("%d", i);
        printf("\n");
    }
}

