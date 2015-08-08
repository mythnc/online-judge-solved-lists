/* ACM Dick and Jane
 */
#include <stdio.h>

int main(void)
{
    int s, p, y, j;
    int Puff, Yertle;

    while (scanf("%d %d %d %d", &s, &p, &y, &j) == 4) {
        j += 12;
        Yertle = (j - p - y) % 3;
        Puff = (j - Yertle - s) / 2;
        printf("%d %d %d\n", j - Yertle - Puff, Puff, Yertle);
    }
    return 0;
}

