 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
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
#define MAX_CHAR 256

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;

	int M,N,K, I,J, conf = 1;
	char S[MAX_K] = {NULL}, c;
	int comb[MAX_N]['z'-'a'];
	fscanf(in,"%d %d %d\n",&M, &N, &K);
	for(int i = 0; i < K; i++) {
		fscanf(in,"%c ",&S[i]);
	}
	//printf("%s\n",S);
	for(int i = 0; i < M; i++) {
		fscanf(in,"%d %d %c\n",&I,&J,&c);
		comb[I][c-'a'] = J;
	}

	for(int i = 0; i < K; i++) {
		conf = comb[conf][S[i]-'a'];
	}
	fprintf(out,"%d",conf);
	fclose(in);
	fclose(out);
	return 0;
}
