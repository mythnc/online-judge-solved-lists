#include <stdio.h>

int main(void)
{
    int p, i, j, k, n, c;
    while (scanf("%d %d", &n, &c) != EOF) {
        int prime[n/2];
        k = 0;
        for(i = 1; i <= n; (i > 2) ? (i += 2) : (i++)){
            p = 1;
            for(j = 3; j * j <= i; j++)
                if (!(i % j)) {
                    p = 0;
                    break;
                }
            if(p)
                prime[k++] = i;
        }
        printf("%d %d:", n, c);
        if(k % 2)
            if(2*c - 1 >= k)
                for(i = 0; i < k; i++)
                    printf(" %d", prime[i]);
            else
                for(i = 0; i < 2*c - 1; i++)
                    printf(" %d", prime[(k + 1) / 2 - (c - 1) + i - 1]);
        else
            if(2*c >= k)
                for(i = 0; i < k; i++)
                    printf(" %d", prime[i]);
            else
                for(i = 0; i < 2*c; i++)
                    printf(" %d", prime[k / 2 - (c - 1) + i - 1]);
        printf("\n\n");
    }
    return 0;
}
