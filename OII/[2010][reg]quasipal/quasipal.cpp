 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <cstdio>
#include <algorithm>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N 10
#define MAX_M 10

int N,M;
char pal[MAX_M][MAX_N];
int ordine[MAX_M];

int quadpal() {
	int len = (M % 2 == 0) ? (M/2) : ((M-1)/2);
	int sx,dx;
	for(int _i = 0; _i < N; _i++) {
		for(int _j = 0; _j < len; _j++) {
			sx = ordine[_j];
			dx = ordine[M-1-_j];
			if(pal[sx][_i] != pal[dx][_i] && pal[sx][_i] != '0' && pal[dx][_i] != '0') return false;
		}
	}
	return true;
}

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
	fscanf(in,"%d %d\n",&M, &N);
	for(int i = 0; i < M; i++) {
		fscanf(in,"%s\n",pal[i]);
		ordine[i] = i;
	}
	
	sort(ordine,ordine+M);
	
	do {
		if(quadpal()) {
			for(int __i = 0; __i < M; __i++) {
				fprintf(out,"%s\n",pal[ordine[__i]]);
			}
			break;
		}
	}
	while(next_permutation(ordine,ordine+M));
	
	fclose(in);
	fclose(out);
	return 0;
}
