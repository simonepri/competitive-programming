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

/*
int collaz(int n, int count = 0) {
	if(n == 1) return count+1;
	else {
		if(n % 2 == 0) return collaz(n/2,count+1);
		else return collaz((n*3)+1,count+1);
	}
}*/

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 0;
	
	int N;
    if(fscanf(in,"%d",&N) != 1) return 0;
	
	int count = 0;
	while(1) {
		if(N <= 1) {
			count+=1;
			break;
		}
		else {
			if(N % 2 == 0) {
				N = N/2;
				count+=1;
			}
			else {
				N = (N*3)+1;
				count+=1;
			}
		}
	}
	fprintf(out,"%d",count);
	
	fclose(in);
	fclose(out);
	return 0;
}
