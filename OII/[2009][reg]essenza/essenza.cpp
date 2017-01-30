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

#define MAX_N 1001

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
	int K,N,max = 0,temp;
	int Costo[MAX_N];
	fscanf(in,"%d %d\n",&K,&N);
	for(int i = 0; i < N; i++) {
		fscanf(in,"%d",&Costo[i]);
	}
	for(int i = 0; i < N; i++) {
		for(int j = 1; j <= K; j++) {
			if(i+j < N){
				temp = Costo[i+j]-Costo[i];
				if(max < temp) max = temp;
			}
		}
	}
	fprintf(out,"%d",max);
	
	fclose(in);
	fclose(out);
	return 0;
}
