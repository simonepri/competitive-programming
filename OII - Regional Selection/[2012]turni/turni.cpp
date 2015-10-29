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

#define MAX_N 51

struct persone {
	int start,end;
}

bool persone_compare(persone a, persone b)
{
	if(a.start < b.start) return true;
	return false;
}

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
	int K,N;
	persone DISP[MAX_N];
	fscanf(in,"%d\n",&K);
	fscanf(in,"%d\n",&N);
	
	for(int i = 0; i < N; i++) {
		fscanf(in,"%d %d\n",DISP[i].start,DISP[i].end);
	}
	sort(DISP, DISP + N, persone_compare);
	
	//fprintf(out,"%d",i);
	fclose(in);
	fclose(out);
	return 0;
}
