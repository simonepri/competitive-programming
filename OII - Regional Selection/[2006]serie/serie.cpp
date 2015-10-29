 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <cstdio>
#include <algorithm>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N 100 //da 2 a 100
#define MAX_K 100 //da 2 a 100

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	int TesteSerie[MAX_N] = {0};
	int Squadre[MAX_N*MAX_K] = {0};
	int temp,K,N;
    fscanf(in,"%d %d\n",&K, &N);
	for(int i = 0; i < K; i++) {
		for(int j = 0; j < N; j++) {
			fscanf(in,"%d",&temp);
			if(TesteSerie[i] < temp) TesteSerie[i] = temp;
			Squadre[N*i-1 + j] = temp;
		}
	}
	sort(TesteSerie, TesteSerie+MAX_N);
	sort(Squadre, Squadre+MAX_N*MAX_K);
	
	int corretto = 1;
	for(int i = 0; i < K; i++) {
		if(TesteSerie[MAX_N-i-1] != Squadre[MAX_N*MAX_K-i-1]) {
			corretto = 0;
			break;
		}
	}
	fprintf(out,"%d",corretto);
	
	fclose(in);
	fclose(out);
	return 0;
}
