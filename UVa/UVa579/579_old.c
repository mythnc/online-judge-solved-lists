#include <stdio.h>

int main(int argc, char *argv[])
{
	int h, m;
	double d;
	while (1) {
		scanf("%d%*[:]%d", &h, &m);
		if (h == 0 && m == 0) {
			break;
		}
		d = 30.0 * h + 1.0 / 2.0 * m - 6.0 * m;
		if (d < 0) {
			d = -d;
		}
		if (d > 180) {
			d = 360.0 - d;
		}

		printf("%.3f\n", d);
	}
	return 0;
}

