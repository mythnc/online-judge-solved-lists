/* ACM 344 Roman Digititis
 * mythnc
 * 2011/10/19 11:09:01   
 * run time: 0.02
 */
#include <stdio.h>

#define ARYMAX 5

void sum(int *, int);
void init(int *);

int main(void)
{
    int n;
    /* num element: 0:i, 1:v, 2:x, 3:l, 4:c */
    int num[ARYMAX];

    while (scanf("%d", &n) != EOF) {
        if (n > 0) {
            init(num);
            sum(num, n);
            printf("%d: %d i, %d v, %d x, %d l, %d c\n",
                   n, num[0], num[1], num[2], num[3], num[4]);
        }
        else
            break;
    }
    return 0;
}

/* init: initialize num elements to 0 */
void init(int *num)
{
    int i;

    for (i = 0; i < ARYMAX; i++)
        num[i] = 0;
}

/* sum: summation the digits from 1 to n */
void sum(int *num, int n)
{
    int i;

    for (i = 1; i < n + 1; i++) {
        switch (i % 10) {
            case 1:
                num[0]++;
                break;
            case 2:
                num[0] += 2;
                break;
            case 3:
                num[0] += 3;
                break;
            case 4:
                num[0]++;
                num[1]++;
                break;
            case 5:
                num[1]++;
                break;
            case 6:
                num[1]++;
                num[0]++;
                break;
            case 7:
                num[1]++;
                num[0] += 2;
                break;
            case 8:
                num[1]++;
                num[0] += 3;
                break;
            case 9:
                num[2]++;
                num[0]++;
                break;
            case 0:
            default:
                break;
        }
        switch (i / 10) {
            case 1:
                num[2]++;
                break;
            case 2:
                num[2] += 2;
                break;
            case 3:
                num[2] += 3;
                break;
            case 4:
                num[2]++;
                num[3]++;
                break;
            case 5:
                num[3]++;
                break;
            case 6:
                num[3]++;
                num[2]++;
                break;
            case 7:
                num[3]++;
                num[2] += 2;
                break;
            case 8:
                num[3]++;
                num[2] += 3;
                break;
            case 9:
                num[4]++;
                num[2]++;
                break;
            case 10:
                num[4]++;
                break;
            case 0:
            default:
                break;
        }
    }
}

