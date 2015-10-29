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

#define MAX_N 1000
#define MAX_C 256
#define MAX_L MAX_N/2

struct striscia {
	int col,alt;
};

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
	int N;
	map<int,int> cache[MAX_L];
	striscia Arcobaleno[MAX_N];
	int colore_i = 0, altezza_i = 0, colore_j = 0, altezza_j = 0;
	int count = 0;
	
    if(fscanf(in,"%d",&N) != 1) return 1;
	for(int i = 0; i < N; i++) {
		if(fscanf(in,"%d",&colore_i) != 1) return 1;
		Arcobaleno[i].col = colore_i;
		Arcobaleno[i].alt = altezza_i;
		
		for(int j = 0; j < (N/2)+1; j++) cache[j][colore_i] = -1;
	}
	
	for(int i = 0; i < N; i++) {
		colore_i = Arcobaleno[i].col;
		altezza_i = Arcobaleno[i].alt;
		
		if(altezza_i > 0 && cache[altezza_i-1][colore_i] != -1) {
			cache[altezza_i-1][colore_i] = i;
			Arcobaleno[i].alt--;
		}
		else {
			for(int j = N-1; j > i; j--) {
				colore_j = Arcobaleno[j].col;
				altezza_j = Arcobaleno[j].alt;
				if(altezza_i == altezza_j && colore_i == colore_j) {
					for(int k = i+1; k < j; k++) {
						Arcobaleno[k].alt++;
					}
					cache[altezza_i][colore_i] = i;
					break;
				}
			}
		}
	}
	
	for(int j = 0; j < (N/2)+1; j++) {
		for(map<int,int>::iterator it = cache[j].begin(); it != cache[j].end(); it++) it->second = -1;
	}
	
	for(int i = 0; i < N; i++) {
		colore_i = Arcobaleno[i].col;
		altezza_i = Arcobaleno[i].alt;
		
		if(cache[altezza_i][colore_i] == -1) {
			count++;
			cache[altezza_i][colore_i] = 1;
		}
	}
	fprintf(out,"%d",count);
	
	fclose(in);
	fclose(out);
	return 0;
}
