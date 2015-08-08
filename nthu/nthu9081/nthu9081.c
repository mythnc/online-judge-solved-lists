#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10100

int main(void)
{
    int n;
    int val, i;

    int *count = (int *)malloc(sizeof(int) * MAX);

    while (scanf("%d", &n) == 1) {
        // init
        memset(count, 0, sizeof(int) * MAX);
        
        // input
        for (i = 0; i < n; i++) {
            scanf("%d", &val);
            count[val]++;
        }

        // output
        for (i = 0; i < MAX; i++) {
            if (count[i] != 0) {
                printf("%d %d", count[i], i);
                break;
            }
        }
        for (i++; i < MAX; i++) {
            if (count[i] != 0) {
                printf(" %d %d", count[i], i);
            }
        }
        putchar('\n');
    }

    return 0;
}

