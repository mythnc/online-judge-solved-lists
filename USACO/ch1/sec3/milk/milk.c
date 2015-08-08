/*
ID: mythnc2
LANG: C
TASK: milk
Mixing Milk
2011/11/14 21:57:02
*/
#include <stdio.h>

#define MAXF 5000

typedef struct provider {
    int price;
    int amount;
} Provider;

int findmin(Provider *, int);
int checkamount(Provider, int);

int main (void)
{
    FILE *fin, *fout;
    int amount, farmer, i, sum, min, quan;
    Provider milk[MAXF];

    fin = fopen("milk.in", "r");
    fout = fopen("milk.out", "w");

    fscanf(fin, "%d %d", &amount, &farmer);
    for (i = 0; i < farmer; i++)
        fscanf(fin, "%d %d", &milk[i].price, &milk[i].amount);

    for (sum = 0; amount; milk[min].price = 1001) {
        min = findmin(milk, farmer);
        quan = checkamount(milk[min], amount);
        sum += quan * milk[min].price;
        amount -= quan;
    }

    fprintf(fout, "%d\n", sum);

    return 0;
}

/* findmin: return the minimum milk.price element */
int findmin(Provider *milk, int n)
{
    int i, min;

    for (i = 1, min = 0; i < n; i++)
        if (milk[i].price < milk[min].price)
            min = i;

    return min;
}

/* checkamount: return the milk.amount provide
 * actually */
int checkamount(Provider milk, int amount)
{
    if (milk.amount > amount)
        return amount;

    return milk.amount;
}
