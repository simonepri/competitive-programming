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

#define MAX_N 31
#define MAX_M 101

int POS[MAX_N];

int swap(int A, int B) {
	int _temp = POS[A];
	POS[A] = POS[B];
	POS[B] = _temp;
}

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
	int N,M,K,A,B;
	fscanf(in,"%d %d\n",&N, &M);
	for(int i = 1; i < N+1; i++) {
		fscanf(in,"%d\n",&K);
		POS[K] = i;
	}
	for(int i = 0; i < M; i++) {
		fscanf(in,"%d %d\n",&A,&B);
		swap(A,B);
	}
	for(int i = 1; i < N+1; i++) {
		if(POS[i] == 1) {
			fprintf(out,"%d",i);
			break;
		}
	}
	fclose(in);
	fclose(out);
	return 0;
}
