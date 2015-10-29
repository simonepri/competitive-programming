 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <stdio.h>

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int main()
{
	FILE *fin = fopen(FILE_INPUT,"r");
	FILE *fout = fopen(FILE_OUTPUT,"w");

	int N;
	char c;
	fscanf(fin, "%d", &N);
	fscanf(fin, "%c", &c);
	for(int i = 0; i < N; i++) {
		fscanf(fin, "%c", &c);
		if('A' <= c && c <= 'Z') c |= (1<<5);
		else if('a' <= c && c <= 'z') c &= ~(1<<5);
		fprintf(fout, "%c", c);
	}

	fclose(fout);
	return 0;
}
