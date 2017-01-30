 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <cstdio>
#include <algorithm>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N 1000 //da 2 a 100

struct nimbus {
	int start,finish;
};

bool sortfunc(const nimbus &a, const nimbus &b) {
	if(a.finish < b.finish) return true;
	return false;
}

nimbus Harry[MAX_N] = {0};

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
	int N,act_finish = -1,caramelle=0;
	fscanf(in,"%d\n",&N);
	
	for(int i = 0; i < N; i++) {
		fscanf(in,"%d %d",&Harry[i].start,&Harry[i].finish);
	}
	
	sort(Harry, Harry + N,sortfunc);
	
	for(int i = 0; i < N; i++) {
		printf("%d => %d\n",Harry[i].start,Harry[i].finish);
	}
	
	for(int i = 0; i < N; i++) {
		if(act_finish == -1 || act_finish < Harry[i].start) {	
			act_finish = Harry[i].finish;
			caramelle++;
		}
	}
	
	fprintf(out,"%d",caramelle);
	
	fclose(in);
	fclose(out);
	return 0;
}
