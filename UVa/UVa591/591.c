/* ACM 591 Box of Bricks
 * mythnc
 * 2011/10/23 11:22:21   
 * run time: 0.004
 */
#include <stdio.h>

#define MAX 50

int main(void)
{
    int n, set, i, avg, move;
    int ary[MAX];

    set = 0;
    while(scanf("%d", &n) != EOF){
        if(n == 0)
            return 0;
        set++;
        for(avg = i = 0; i < n; i++){
            scanf("%d", ary + i);
            avg += ary[i];
        }
        avg /= n;
        for(move = i = 0; i < n; i++)
            if(ary[i] > avg)
                move += ary[i] - avg;
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",
                set, move);
    }
}

