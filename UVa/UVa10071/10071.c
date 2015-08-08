/* ACM 10071 Back to High School Physics
 * mythnc
 * 2011/10/13 18:58:58   
 * run time: 0.02
 */
#include  <stdio.h>

int main(int argc, char *argv[])
{
    int t, v;

    while (scanf("%d %d", &v, &t) != EOF )
        printf("%d\n", 2 * v * t);
    return 0;
}

