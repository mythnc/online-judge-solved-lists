/* ACM 305 Joseph
 * mythnc
 * 2011/12/01 14:00:19   
 * answer for upload
 * run time: 0.004
 */
#include <stdio.h>

int main(void)
{
    int answer[] = {2, 7, 5, 30, 169,
                    441, 1872, 7632, 1740, 93313,
                    459901, 1358657, 2504881};
    int k;
    while (scanf("%d", &k) && k != 0)
        printf("%d\n", answer[k - 1]);

    return 0;
}

