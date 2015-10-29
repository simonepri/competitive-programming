 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <cstdio>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N 100 //da 2 a 100
#define MAX_R 1000 //da 2 a 1000

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	int N,R;
	int TAGLI[MAX_N] = {0};
	int MAT[MAX_N][MAX_R] = {{0},{0}};
	fscanf(in,"%d\n",&N);
	fscanf(in,"%d\n",&R);
	for(int i = 0; i < N; i++) {
		fscanf(in,"%d\n",&TAGLI[i]);
		MAT[i][0] = 1;
	}
	
	for(int j = 1; j < R+1; j++) {
		for(int i = 0; i < N; i++) {
			if(i-1 >= 0) MAT[i][j] = MAT[i-1][j];
			if(j - TAGLI[i] >= 0) MAT[i][j] += MAT[i][j - TAGLI[i]];
		}
	}
	
	fprintf(out,"%d",MAT[N-1][R]);
	
	fclose(in);
	fclose(out);
	return 0;
}
