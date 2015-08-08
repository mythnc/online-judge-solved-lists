/* ACM 101 The Blocks Problem
 * mythnc
 * 2011/10/13 19:43:32   
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, a, b, i, j, position_a, position_b, count, tmp, undo;
    char ary1[5], ary2[5];
    int ary3[n][n], move, onto;
    scanf("%d", &n);
    int record[2][n];
    for (i = 0; i < n; i++) {
        ary3[i][0] = i;
        record[0][i] = i;
        record[1][i] = 1;
    }
    while (1) {
        scanf("%s", ary1);
        if (!strcmp(ary1, "quit")) {
            for (i = 0; i < n; i++) {
                printf("%d:", i);
                for (j = 0; j < record[1][i]; j++)
                    printf(" %d", ary3[i][j]);
                printf("\n");
            }
            break;
        }
        if (!strcmp(ary1, "move"))
            move = 1;
        else
            move = 0;
        scanf("%d %s %d", &a, ary2, &b);
        if (a == b)
            continue;
        if (!strcmp(ary2, "onto"))
            onto = 1;
        else
            onto = 0;

        position_a = record[0][a];
        position_b = record[0][b];
        if (position_a == position_b)
            continue;

        if (move && onto) {
            if (record[1][position_a] > 1) {
                count = record[1][position_a];
                for (i = 0; i < count; i++) {
                    if (ary3[position_a][i] == a && i + 1 < count) {
                        for (j = i + 1; j < count; j++) {
                            record[1][position_a]--;
                            undo = ary3[position_a][j];
                            tmp = record[1][undo]++;
                            ary3[undo][tmp] = undo;
                            record[0][undo] = undo;
                        }
                    }
                }
            }
            if (record[1][position_b] > 1) {
                count = record[1][position_b];
                for (i = 0; i < count; i++) {
                    if (ary3[position_b][i] == b && i + 1 < count) {
                        for (j = i + 1; j < count; j++) {
                            record[1][position_b]--;
                            undo = ary3[position_b][j];
                            tmp = record[1][undo]++;
                            ary3[undo][tmp] = undo;
                            record[0][undo] = undo;
                        }
                    }
                }
            }
            record[1][position_a]--;
            tmp = record[1][position_b]++;
            ary3[position_b][tmp] = a;
            record[0][a] = position_b;
        }
        else if (move && !onto) {
            if (record[1][position_a] > 1) {
                count = record[1][position_a];
                for (i = 0; i < count; i++) {
                    if (ary3[position_a][i] == a && i + 1 < count) {
                        for (j = i + 1; j < count; j++) {
                            record[1][position_a]--;
                            undo = ary3[position_a][j];
                            tmp = record[1][undo]++;
                            ary3[undo][tmp] = undo;
                            record[0][undo] = undo;
                        }
                    }
                }
            }
            record[1][position_a]--;
            tmp = record[1][position_b]++;
            ary3[position_b][tmp] = a;
            record[0][a] = position_b;
        }
        else if (!move && onto) {
            if (record[1][position_b] > 1) {
                count = record[1][position_b];
                for (i = 0; i < count; i++) {
                    if (ary3[position_b][i] == b && i + 1 < count) {
                        for (j = i + 1; j < count; j++) {
                            record[1][position_b]--;
                            undo = ary3[position_b][j];
                            tmp = record[1][undo]++;
                            ary3[undo][tmp] = undo;
                            record[0][undo] = undo;
                        }
                    }
                }
            }
            count = record[1][position_a];
            for (i = 0; i < count; i++) {
                if (ary3[position_a][i] == a) {
                    for (j = i; j < count; j++) {
                        record[1][position_a]--;
                        tmp = record[1][position_b]++;
                        ary3[position_b][tmp] = ary3[position_a][j];
                        record[0][ary3[position_a][j]] = position_b;
                    }
                }
            }
        }
        else if (!move && !onto) {
            count = record[1][position_a];
            for (i = 0; i < count; i++) {
                if (ary3[position_a][i] == a) {
                    for (j = i; j < count; j++) {
                        record[1][position_a]--;
                        tmp = record[1][position_b]++;
                        ary3[position_b][tmp] = ary3[position_a][j];
                        record[0][ary3[position_a][j]] = position_b;
                    }
                }
            }
        }
    }
    return 0;
}

