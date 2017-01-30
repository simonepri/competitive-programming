 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <cstdio>
using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N 1000
#define MID_C 100000
#define MAX_C 200000

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
	int N,read,act = 0, count[MAX_C] = {0};
	int max_c = -1, max_i = -1;
	fscanf(in,"%d\n",&N);
	count[0] = 1;
	for(int i = 0; i < N; i++) {
		fscanf(in,"%d\n", &read);
		act+=read;
		count[act+MID_C]++;
		if(count[act+MID_C] > max_c) {
			max_c = count[act+MID_C];
			max_i = act;
		}
	}
	fprintf(out,"%d",5000+max_i);
	fclose(in);
	fclose(out);
	return 0;
}
