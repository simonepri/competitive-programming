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

#define MAX_N 10

int tes[MAX_N][2];
int N,lunghezza;
bool usata[MAX_N];

void trova_permutazione(int pos,int num_att = -1)
{
	if (pos > lunghezza) lunghezza = pos;
	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < 2; j++) {
			if (num_att == -1 || (num_att == tes[i][j] && usata[i] == false))
			{
				usata[i] = true;
				trova_permutazione(pos + 1,tes[i][1-j]);
				usata[i] = false;
			}	
		}
	}
}

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
	fscanf(in,"%d\n",&N);
	for(int i = 0; i < N; i++) {
		fscanf(in,"%d %d\n",&tes[i][0],&tes[i][1]);
	}
	trova_permutazione(0);
	fprintf(out,"%d",lunghezza);
	
	fclose(in);
	fclose(out);
	return 0;
}
