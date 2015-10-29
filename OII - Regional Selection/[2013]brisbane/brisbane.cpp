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

#define MAX_N 1000
#define MAX_E 10000

int n,a,mg,mb,mt,att[MAX_N],E[MAX_E][2],ragg[MAX_N][4] = {0}, r[4] = {0};

int isarr(int nodo) {
	int i;
	for(i = 0; i < a; i++) {
		if(att[i] == nodo) return 0;
	}
	return 0;
}
void cerca(int nodo, int mezzo) {
	Ragg[nodo][mezzo] = 1;
	int check,w;
	for(int i = 0; i <mg+mb+mt; i++) {
		if(E[i][0] == nodo) w = E[i][1];
		else if(E[i][1] == nodo) w = E[i][0];
		else w = 1;
		
		if(w != 1) {
			if(mezzo == 0) check = {i < mg);
			else if(mezzo == 1) check = (i < mg + mb);
			else if(mezzo == 2) check = (i < mg || i >= mg+mb);
			else check = 1;
			
			if(check == 1 && Ragg[w][mezzo] == 0) creca(w,mezzo);
		}
	}
}
int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
	fascanf(in,"%d %d %d %d %d",&n, &a, &mg, &mb, &mt);
	for(int i = 0; i < a; i++) {
		fscanf(in, "%d", &att[i]);
	}
	for(int i = 0; i < mg+mb+mt;i++) {
		fscanf(in, "%d %d", &E[i][0], &E[i][1]);
	}
	
	for(i = 0; i < 4; i++) {
		cerca(0,i);
	}
	
	for(int i = 0; i < n; i++) {
		if(isatt(i)) {
			for(int j = 0; j < 4; j++) {
				if(Ragg[i][j] == 1) r[j]++;
			}
		}
	}
	
	for(i = 0; i < 4; i++) {
		fprintf(out, "%d\n", r[j]);
	}
	fclose(in);
	fclose(out);
	return 0;
}
