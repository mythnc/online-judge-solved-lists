#include <stdio.h>

int main(int argc, char *argv[])
{
	int n, x, y;
	int i, sum;
	while (scanf("%d", &n) != EOF) {
		sum = 0;
		i = 1;
		while (sum < n) {
			sum += i++;
		}
		if (i % 2) {
			x = n - (sum - i + 1);
			y = i - x;
		}
		else {
			y = n - (sum - i + 1);
			x = i - y;
		}
		printf("TERM %d IS %d/%d\n", n, x, y);
	}
	return 0;
}

