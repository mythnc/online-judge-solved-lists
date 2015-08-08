#include <stdio.h>

int main(void)
{
    int n = 100;
    int i, j, rec, c;

    printf("  2");
    for (c = 1, i = 3; i < n; i += 2) {
        for (rec = 1, j = 3; j * j <= i; j += 2)
            if (i % j == 0) {
                rec = 0;
                break;
            }

        if (rec == 1) {
            printf("%3d", i);
            c++;
            if (c % 10 == 0)
                printf("\n");
        }
    }
    return 0;
}

