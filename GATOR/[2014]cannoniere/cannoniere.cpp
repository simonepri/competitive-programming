 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <cstdio>
#include <map>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N 51
#define MAX_G 101

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return -1;
	
	int N,G,R;
	map<int,int> giocatori;
		if(fscanf(in,"%d\n",&N)) {
		for(int i = 0; i < N; i++) {
			if(fscanf(in,"%d %d\n",&G, &R)) giocatori[G] += R;
		}
		int maxg = 0, maxr = 0;
		for(map<int, int>::iterator it = giocatori.begin(); it != giocatori.end(); it++) {
			if(maxr < it->second) {
				maxr = it->second;
				maxg = it->first;
			}
		}
		fprintf(out,"%d %d",maxg, maxr);
	}
	
	fclose(in);
	fclose(out);
	return 0;
}
