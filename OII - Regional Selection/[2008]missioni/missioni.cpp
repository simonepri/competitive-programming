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

#define MAX_N 101 //da 1 a 100
#define MAX_G 366 //da 1 a 365

struct missioni {
	int start,finish,days;
};

int maxi(int a, int b) {
	return a > b ? a : b;
}

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
	int N,max = 0,fine, MaxMis[MAX_G] = {0};
	missioni MIS[MAX_N];
	fscanf(in,"%d\n",&N);
	for(int  i = 1 ; i < MAX_G ; i++) MaxMis[i] = -1;
	
	for(int i = 0; i < N; i++) {
		fscanf(in,"%d %d\n",&MIS[i].days,&MIS[i].finish);
		MIS[i].start = MIS[i].finish - MIS[i].days;
	}
	for(int  i = 0; i < N; i++)  {
		for(int j = MIS[i].start; j >= 0; j--) {
			if (MaxMis[j] != -1) { // j è giorno usato
				fine = j + MIS[i].days; // fine viene usato
				MaxMis[fine] = maxi( MaxMis[fine], MaxMis[j]+1);
				max = maxi(max,  MaxMis[fine]);
	        }
		}
   }
	fprintf(out,"%d",max);
	
	fclose(in);
	fclose(out);
	return 0;
}
