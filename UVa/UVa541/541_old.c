#include <stdio.h>

int main(int argc, char *argv[]){
	int n, sumr, sumc, i, j, c1, c2;
	while((scanf("%d", &n) != EOF)){
		if(n == 0)
			break;
		int m[n][n], r[n], c[n]; 
		for(i = 0; i < n; i++){
			sumr = 0;
			for(j = 0; j < n; j++){
				scanf("%d", &m[i][j]);
				if(m[i][j] == 1)
					sumr += m[i][j];
				if(j == n - 1)
					r[i] = sumr % 2;
			}
		}
		sumr = 0, c1 = 0;
		for(i = 0; i < n; i++){
			if(r[i]){
				sumr++;
				if(c1 == 0)
					c1 = i + 1;
			}
			if(sumr > 1)
				break;
		}
		if(sumr > 1){
			printf("Corrupt\n");
			continue;
		}

		for(i = 0; i < n; i++){
			sumc = 0;
			for(j = 0; j < n; j++){
				if(m[j][i] == 1){
					sumc += m[j][i];
				}
				if(j == n - 1)
					c[i]  = sumc % 2;
			}
		}
		sumc = 0, c2 = 0;
		for(i = 0; i < n; i++){
			if(c[i]){
				sumc++;
				if(c2 == 0)
					c2 = i + 1;
			}
			if(sumc > 1)
				break;
		}
		if(sumc > 1){
			printf("Corrupt\n");
			continue;
		}
		if(sumc == 0 && sumr == 0){
			printf("OK\n");
			continue;
		}
		if(sumc == 1 && sumr == 1){
			printf("Change bit (%d,%d)\n", c1, c2);
			continue;
		}
	}
	return 0;
}

