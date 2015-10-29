 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <cstdio>

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N 50010 //da 2 a 50000
#define MAX_M 50010 //da 1 a 50000
#define MAX_L MAX_M //da 1 a M

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	int N,M,H,S,a,b,l;
	int lums[MAX_M],cons[MAX_M];
	fscanf(in,"%d %d %d %d\n",&N, &M, &H, &S);
	if(H == S) {
		fprintf(out,"0");
		return 0;
	}
	
	for(int i = 0; i < MAX_M; i++) lums[i] = -1,cons[i] = -1;

	for(int i = 0; i < M; i++) {
		fscanf(in,"%d %d %d\n",&a, &b, &l);
		if(lums[a] > l || lums[a] == -1) {
			lums[a] = l;
			cons[a] = b;
		}
		if(lums[b] > l || lums[b] == -1) {
			lums[b] = l;
			cons[b] = a;
		}
	}
	
	int oldnode = -1,actualnode = H,finishnode = S,countnode=0;
	while(1) {
		if(cons[actualnode] == -1 || cons[actualnode] == oldnode) {
			fprintf(out,"-1");
			break;
		}
		else {
			oldnode = actualnode;
			actualnode = cons[actualnode];
			countnode++;
			if(actualnode == finishnode) {
				fprintf(out,"%d",countnode);
				break;
			}
		}
	}
	
	fclose(in);
	fclose(out);
	return 0;
}
