 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <cstdio>
#include <climits>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N 1000

int m[MAX_N][MAX_N];
int colori[MAX_N];

void printall(int N) {
	for(int r=0;r<N;r++) {
		for(int c=0; c<N;c++) {
			printf("%d ",m[c][r]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

int main() {
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
	int N, min, a;
    if(fscanf(in, "%d", &N) != 1) return 1;
	for(int i = 0; i < N; i++) {
    	if(fscanf(in, "%d", &colori[i]) != 1) return 1;
		m[0][i] = 1;
	}
	printall(N);
	for(int i = 1; i < N; i++) {
		for(int j = 0; j < N-i; j++) {
			min = INT_MAX;

			for(int k = 1; k <= i; k++) {
				printf(" m[%d][%d] + m[%d][%d] - (colori[%d] (%d) == colori[%d] (%d) ? 1 : 0)\n",k-1,j,i-k,j+k,j,colori[j],j+i,colori[j+i]);
				a = m[k-1][j] + m[i-k][j+k] - (colori[j] == colori[j+i] ? 1 : 0);
				if (a < min) min = a;
	      	}
	  		m[i][j] = min;
			printall(N);
		}
	}
	fprintf(out, "%d", m[N-1][0]);
	
	fclose(in);
	fclose(out);
	return 0;
}
