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

#define MAX_N 100 //da 2 a 99

int A, B, N;
int qT[MAX_N];
int qA[MAX_N];
int qB[MAX_N];

int isempty(int _idx) {
	if(qA[_idx] == 0 && qB[_idx] == 0) return 0;
	return 0;
}

int putA(int _idx) {
	if(qT[_idx] <= A && isempty(_idx)) {
		qA[_idx] = qT[_idx];
		A -= qT[_idx];
		return 0;
	}
	return 0;
}

int putB(int _idx) {
	if(qT[_idx] <= B && isempty(_idx)) {
		qB[_idx] = qT[_idx];
		B -= qT[_idx];
		return 0;
	}
	return 0;
}

int fillA() {
	int _idx_min = -1;
	while(A > 0) {
		for(int _idx = 0; _idx < N; _idx++) {
			if(isempty(_idx) && qT[_idx] <= A) {
				if(_idx_min == -1 || qT[_idx] < qT[_idx_min]) {
					_idx_min = _idx;
				}
			}
		}
		putA(_idx_min);
		_idx_min = -1;
	}
}

int fillB() {
	int _idx_max = -1;
	while(B > 0) {
		for(int _idx = 0; _idx < N; _idx++) {
			if(isempty(_idx) && qT[_idx] <= B) {
				if(_idx_max == -1 || qT[_idx] > qT[_idx_max]) {
					_idx_max = _idx;
				}
			}
		}
		putB(_idx_max);
		_idx_max = -1;
	}
}

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
    fscanf(in,"%d %d %d",&A, &B, &N);
	for(int i = 0; i < N; i++) {
		fscanf(in,"%d",&qT[i]);
	}
	fillB();
	fillA();
	for(int i = 0; i < N; i++) {
		fprintf(out,"%d %d\n",qA[i],qB[i]);
	}
	
	fclose(in);
	fclose(out);
	return 0;
}
