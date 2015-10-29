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

#define MAX_N 1000

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 0;
	int N;
	int Alchol[MAX_N];
    if(fscanf(in,"%d",&N) != 1) return 0;
	for(int i = 0; i < N; i++) {
		if(fscanf(in,"%d",&Alchol[i]) != 1) return 0;
	}
	
	int Soluzione[MAX_N] = {1,0};
	int max = 0;
	for(int i = 1; i < N; i++) {
		for(int j = i-2; j > -1; j--) {
			if(Alchol[j] <= Alchol[i] && Soluzione[j] > max) max = Soluzione[j];
		}
		Soluzione[i] = max+1;
		max = 0;
	}
	max = 0;
	for(int i = 0; i < N; i++) {
		if(Soluzione[i] > max) max = Soluzione[i];
	}
	
	fprintf(out,"%d",max);
	
	fclose(in);
	fclose(out);
	return 0;
}
