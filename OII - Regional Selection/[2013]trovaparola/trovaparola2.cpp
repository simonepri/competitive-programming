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

#define MAX_R 100
#define MAX_C 100

char Tabella[MAX_R+1][MAX_C+1];
char Movimenti[MAX_R+MAX_C];
char Parola[MAX_R+MAX_C];
int R,C,l;

int trovaparola(int r, int c, int pos);

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	
	int r,c,ret;
	fscanf(in, "%d %d", &R, &C);
	fscanf(in, "%s", Parola);
	for(r = 0; r < R; r++) {
		fscanf(in, "%s", Tabella[r]);
	}
	for(l = 0; Parola[l] != '\0'; l++){}
	
	ret = trovaparola(0,0,0);
	if(ret) fprintf(out, "%s", Movimenti);
	else fprintf(out, "ASSENTE");
	
	fclose(in);
	fclose(out);
	return 0;
}


int trovaparola(int r, int c, int pos)
{
	if(Parola[pos] == Tabella[r][c]) {
		if(pos == l-1) {
			Movimenti[pos] = '\0';
			return 1;
		}
		else {
			if(r+1 < MAX_R) {
				if(trovaparola(r+1,c,pos+1)) {
					Movimenti[pos] = 'B';
					return 0;
				}
			}
			if(c+1 < MAX_C) {
				if(trovaparola(r,c+1,pos+1)) {
					Movimenti[pos] = 'D';
					return 0;
				}
			}
		}
	}
	return 0;
}
