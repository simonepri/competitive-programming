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

#define MAX_A 4
#define MAX_D 4

struct giocatore {
	float x1,x2,y1,y2,rx,ry;
};

float pos_d_Y(int _d, float _y1, float _y2) {
	return ((_y2 - _y1)*(float(_d)/10))+_y1;
}

float pos_d_X(int _d, float _x1, float _x2) {
	return ((_x2 - _x1)*(float(_d)/10))+_x1;
}

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return -1;
	
	int d,A,D;
	giocatore Attaccanti[MAX_A];
	giocatore Difensori[MAX_D];
    if(!fscanf(in,"%d %d %d\n",&d, &A, &D)) return -1;
	for(int i = 0; i < A; i++) {
		if(!fscanf(in,"%f %f %f %f\n",&Attaccanti[i].x1, &Attaccanti[i].y1, &Attaccanti[i].x2, &Attaccanti[i].y2)) return -1;
		Attaccanti[i].rx = pos_d_X(d, Difensori[i].x1, Difensori[i].x2);
		Attaccanti[i].ry = pos_d_Y(d, Attaccanti[i].y1, Attaccanti[i].y2);
	}
	for(int i = 0; i < D; i++) {
		if(!fscanf(in,"%f %f %f %f\n",&Difensori[i].x1, &Difensori[i].y1, &Difensori[i].x2, &Difensori[i].y2)) return -1;
		Difensori[i].rx = pos_d_X(d, Difensori[i].x1, Difensori[i].x2);
		Difensori[i].ry = pos_d_Y(d, Difensori[i].y1, Difensori[i].y2);
	}
	int flag = 0;
	for(int i = 0; i < A; i++) {
		if(Attaccanti[i].rx >= 0 && Attaccanti[i].rx <= 84 && Attaccanti[i].ry >= 0 && Attaccanti[i].ry <= 40) {
			//for(int j = 0; j < D; j++) {
				if(Difensori[i].rx >= 0 && Difensori[i].rx <= 84 && Difensori[i].ry >= 0 && Difensori[i].ry <= 40) {
					if(Attaccanti[i].ry < Difensori[i].ry) {
						fprintf(out,"F");
						flag = 1;
						break;
					}
				}
		//	}
		}
	}
	if(flag == 0) fprintf(out,"R");
	
	fclose(in);
	fclose(out);
	return 0;
}
