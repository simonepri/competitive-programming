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

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
	int N,temp1=0,act=5000;
	int count[200+1] = {0};
	int max_c = -1, max_i = -1;
	fscanf(in,"%d\n",&N);
	for(int i = 0; i < N; i++) {
		fscanf(in,"%d\n", &temp1);
		act += temp1;
		count[act+100-5000]++;
		if(max_c == -1 || max_c < count[act+100-5000]) max_c = count[act+100-5000],max_i = act+100-5000;
	}
	fprintf(out,"%d",5000+max_i-100);
	fclose(in);
	fclose(out);
	return 0;
}
