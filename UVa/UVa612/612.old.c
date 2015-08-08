#include <stdio.h>

int main(int argc, char *argv[])
{
	int n, times = 0;
	scanf("%d", &n);
	getchar();
	while (n--) {
		times++;
		if (times > 1) {
			printf("\n");
		}
		int x, y, i, j, k, c;
		scanf("%d %d", &x, &y);
		char ary[y][x + 1];
		int sorted[y], min = 999;
		for (i = 0; i < y; i++) {
			scanf("%s", ary[i]);
		}
		for (i = 0; i < y; i++) {
			c = 0;
			for (j = 0; j < x - 1; j++) {
				for (k = j + 1; k < x; k++) {
					if (ary[i][j] > ary[i][k]) {
						c++;
					}
				}
			}
			sorted[i] = c;
		}
		while (1) {
			for (i = 0; i < y; i++) {
				if (min > sorted[i]) {
					min = sorted[i];
					j = i;
				}
			}
			if (min == 999) {
				break;
			}
			sorted[j] = 999;
			printf("%s\n", ary[j]);
			min = 999;
		}
	}
	return 0;
}

