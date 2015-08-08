/* ACM 612 DNA Sorting
 * mythnc
 * 2011/10/24 19:32:54   
 * run time: 0.092
 */
#include <stdio.h>

#define LEN  50
#define MAX 100

int dna(char *pt);
int sum_unsorted(char *pt);
void sort_dna(char (*pt)[LEN + 1], int *record, int n);

int main(void)
{
    int set, len, n, i, line;
    char ary[MAX][LEN + 1];
    int record[MAX];

    line = 0;
    scanf("%d", &set);
    while (set--) {
        if (line == 1)
            printf("\n");
        scanf("%d %d", &len ,&n);
        for (i = 0; i < n; i++)
            scanf("%s", ary[i]);
        for (i = 0; i < n; i++)
            record[i] = dna(ary[i]);
        sort_dna(ary, record, n);
        line = 1;
    }
    return 0;
}

/* dna: find the sorted degree of each dna
 * return degrees */
int dna(char *pt)
{
    int sum;

    sum = 0;
    while (*pt)
        switch (*pt) {
            case 'C':
            case 'G':
            case 'T':
                sum += sum_unsorted(pt);
            case 'A':
                pt++;
        }
    return sum;
}

/* sum: sum the unsorted number of each dna 
 * and return it */
int sum_unsorted(char *pt)
{
    int sum;
    char *pt_m;

    sum = 0;
    pt_m = pt;
    while (*++pt_m)
        if (*pt_m < *pt)    
            sum++;
    return sum;
}

/* sort_dna: find the tiniest record to largest 
 * then print the mapping pt sequentially */
void sort_dna(char (*pt)[LEN + 1], int *record, int n)
{
    int min, i;

    while (1) {
        for (min = i = 0; i < n; i++)
            if (record[i] < record[min])
                min = i;
        if (record[min] == 2000)
            break;
        printf("%s\n", pt[min]);
        record[min] = 2000;
    }
}

