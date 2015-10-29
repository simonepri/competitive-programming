 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <cstdio>
#include <climits>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N 1000

struct ragazzo {
	int rx,ry,tx,ty;
};

struct palla {
	int px,py;
};

int X,Y,N;
ragazzo Ragazzi[MAX_N];
palla Palla;

int abs(int n) {
	return (n >= 0) ? n : -n;
}

int dist(int x1, int y1, int x2, int y2) {
	return abs(x2-x1) + abs(y2-y1);
}

int find_near() {
	int min_i,min_d = INT_MAX,min_x,min_y;
	int temp;
	for(int i = 0; i < N; i++) {
		temp = dist(Palla.px,Palla.py, Ragazzi[i].rx, Ragazzi[i].ry);
		if(temp < min_d || temp == min_d && Ragazzi[i].rx < min_x || temp == min_d && Ragazzi[i].rx == min_x && Ragazzi[i].ry < min_y) {
			min_i = i;
			min_d = temp;
			min_x = Ragazzi[i].rx;
			min_y = Ragazzi[i].ry;
		}
	}
	return min_i;
}

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 0;
	
    if(fscanf(in,"%d %d\n",&X,&Y) != 2) return 0;
	if(fscanf(in,"%d %d\n",&Palla.px,&Palla.py) != 2) return 0;
	
	if(fscanf(in,"%d\n",&N) != 1) return 0;
	
	for(int i = 0; i < N; i++) {
		if(fscanf(in,"%d %d %d %d\n",&Ragazzi[i].rx,&Ragazzi[i].ry,&Ragazzi[i].tx,&Ragazzi[i].ty) != 4) return 0;
	}
	
	int Giocato[MAX_N] = {0};
	int gi;
	int count = 0;
	while(1) {
		gi = find_near();
		if(Giocato[gi] == 0) {
			Palla.px = Ragazzi[gi].tx;
			Palla.py = Ragazzi[gi].ty;
			Giocato[gi] = 1;
			count++;
		}
		else break;
	}
	fprintf(out,"%d",count);
	
	fclose(in);
	fclose(out);
	return 0;
}
