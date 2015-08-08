/* Uva 11235 Frequent values
 * mythnc
 * 2013/09/25 17:07:16   
 * run time: 
 */
#include <stdio.h>

#define MAXARY 100000

typedef struct number {
    int name;
    int freq;
} Number;

int count_freq(int *, Number *, int, int);
int find(int, Number *, int);
int max(Number *, int);

int main(void)
{
    int n, q, i, j, k, size;
    int a[MAXARY];
    Number number[MAXARY];

    while (1) {
        scanf("%d", &n);
        if (n == 0)
            break;
        scanf("%d", &q);
        for (i = 0; i < n; i++) {
            scanf("%d", a + i);
        }

        for (i = 0; i < q; i++) {
            scanf("%d %d", &j, &k);
            printf("%d\n", max(number, count_freq(a, number, j - 1, k)));
        }
    }

    return 0;
}

int count_freq(int *a, Number *number, int i, int j)
{
    int k, size, index;

    for (size = 0, k = i; k < j; k++) {
        index = find(a[k], number, size);
        if (index < 0) {
            number[size].name = a[k];
            number[size].freq = 1;
            size++;
        }
        else
            number[index].freq++;
    }

    return size;
}


int find(int num, Number *number, int n)
{
    int i;
    
    for (i = 0; i < n; i++) {
        if (number[i].name == num)
            return i;
    }

    return -1;
}

int max(Number *number, int n)
{
    int i, value, max;

    for (i = 0, max = 1; i < n; i++) {
        value = number[i].freq;
        if (value > max)
            max = value ;
    }

    return max;
}
