 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <cstdio>
#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_K 10
#define MAX_N 101

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
	int M,N,K, I,J, conf = 1;
	char S[MAX_K] = {NULL}, c;
	vector<char> comb[MAX_N][MAX_N];
	fscanf(in,"%d %d %d\n",&M, &N, &K);
	for(int i = 0; i < K; i++) {
		fscanf(in,"%s",&S[i]);
	}
	printf("%s\n",S);
	for(int i = 0; i < M; i++) {
		fscanf(in,"%d %d %c\n",&I,&J,&c);
		comb[I][J].push_back(c);
	}
	
	int flag = 0;
	for(int i = 0; i < K; i++) {
		for(int j = 1; j < N+1; j++) {
			for(int k = 0; k < comb[conf][j].size(); k++) {
				if(comb[conf][j].at(k) == NULL) continue;
				if(S[i] == comb[conf][j].at(k)) {
					flag = 1;
					conf = j;
					break;
				}
			}
		}
		if(flag == 0) break;
		flag = 0;
	}
	fprintf(out,"%d",conf);
	fclose(in);
	fclose(out);
	return 0;
}
