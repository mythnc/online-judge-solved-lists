#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXLINE  20000
#define MAXPOINT 100
#define MAXDIMEN 1000

typedef struct point {
    int index;
    int value;
    int visited;
} Point;

void init_pt(void);
int get_dimension(char *, Point *);
int find_min_dis(int);
int find_dis(int, int);
int find_value(int, int);

Point pts[MAXPOINT][MAXDIMEN];
int pair[MAXPOINT];

int main(void)
{
    int i, n;
    char *ptr;
    char line[MAXLINE];

    while (1) {
        n = 0;
        init_pt();
        while (1) {
            ptr = fgets(line, MAXLINE, stdin);
            if (ptr == NULL)
                return 0;
            if (strncmp(ptr, "END", 3) == 0)
                break;
            pair[n] = get_dimension(ptr, pts[n]);
            n++;
        }
        printf("%d\n", find_min_dis(n));
    }

    return 0;
}

/* init_pt: initialize value of points to 0 */
void init_pt(void)
{
    int i, j;

    for (i = 0; i < MAXPOINT; i++) {
        for (j = 0; j < MAXDIMEN; j++) {
            pts[i][j].index = -1;
            pts[i][j].value = 0;
            pts[i][j].visited = 0;
        }
    }
}

/* get_dimension: Get all dimension value of this point. */
int get_dimension(char *line, Point *pt)
{
    int n = 0;
    char *ptr;

    ptr = strtok(line, ";");
    while (ptr) {
        sscanf(ptr, "(%d,%d)", &pt[n].index, &pt[n].value);
        n++;
        ptr = strtok(NULL, ";");
    }
    return n;
}

/* find_min_dis: Find minimum distance and return it. */
int find_min_dis(int n)
{
    int i, j, k;
    int min, dis;

    min = 2147483647;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            dis = find_dis(i, j);
            if (dis < min)
                min = dis;
        }
    }
    return min;
}

/* find_dis: Find distance of index a1 and a2, and return distance. */
int find_dis(int a1, int a2)
{
    int i, value;
    int dis = 0;

    for (i = 0; i < pair[a1]; i++) {
        value = find_value(pts[a1][i].index, a2);
        dis += abs(pts[a1][i].value - value);
    }
    for (i = 0; i < pair[a2]; i++) {
        if (pts[a2][i].visited == 1) {
            pts[a2][i].visited = 0;
            continue;
        }
        value = find_value(pts[a2][i].index, a1);
        dis += abs(pts[a2][i].value - value);
    }

    return dis;
}

/* find_value: find value by index in another point if not visited, else return 0 */
int find_value(int index, int point)
{
    int i, temp;

    for (i = 0; i < pair[point]; i++) {
        temp = pts[point][i].index;
        if (temp < 0)
            break;
        if (temp == index) {
            pts[point][i].visited = 1;
            return pts[point][i].value;
        }
    }
    return 0;
}
