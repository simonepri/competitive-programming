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

#define MAX_N 100000

int seq[MAX_N],N;

bool IsFreq(int len) {
	if(N % len != 0) return false;
	int _j = 0;
	for(int _i = len; _i < N; _i++) {
		if(seq[_j] != seq[_i]) return false;
		_j++;
		if(_j == len) _j = 0;
	}
	return true;
}

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
	int flag = 0;
	fscanf(in,"%d\n",&N);
	for(int i = 0; i < N; i++) {
		fscanf(in,"%d",&seq[i]);
	}
	for(int i = 1; i < N/2+1; i++) {
		if(IsFreq(i)) {
			for(int j = 0; j < i; j++) {
				fprintf(out,"%d ",seq[j]);
			}
			flag = 1;
			break;
		}
	}
	
	if(flag == 0) fprintf(out,"%d",2);
	fclose(in);
	fclose(out);
	return 0;
}
