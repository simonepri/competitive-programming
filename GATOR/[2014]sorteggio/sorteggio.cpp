 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_M 64
#define MAX_G 16 //Gironi
#define MAX_S 16 //Sedicesimi
#define MAX_O 8 //Ottavi
#define MAX_Q 4 //Quarti
#define MAX_H 2 //semi-Finali
#define MAX_F 1 //Finali

int Forza[MAX_M];
/*
vector<int> gironi[MAX_G];
vector<int> sedicesimi[MAX_S];
vector<int> ottavi[MAX_O];
vector<int> quarti[MAX_Q];
vector<int> sfinali[MAX_H];
vector<int> finali[MAX_F];

char create_result(int m) {
	switch(m/4) {
		case 16: {
			for(int g = 0; g < 16; g++) {
				sort(gironi[g].begin(), gironi[g].end());
				if(gironi[g].at(2) == 0 || gironi[g].at(3) == 0) return 'G';
				sedicesimi[g].at(0) = gironi[g].at(0);
				sedicesimi[15-g].at(0) = gironi[g].at(1);
			}
			int c1=0,c2=0;
			for(int s = 0; s < 16; s++) {
				if(min(sedicesimi[s].at(0),sedicesimi[s].at(1)) == 0) return 'S';
				ottavi[c1].at(c2) = max(sedicesimi[s].at(0),sedicesimi[s].at(1));
				c2++;
				if(c2 == 2) {
					c2 = 0;
					c1++
				}
			}
			c1=0,c2=0;
			for(int o = 0; o < 8; o++) {
				if(min(ottavi[o].at(0),ottavi[o].at(1)) == 0) return 'O';
				quarti[c1].at(c2) = max(ottavi[o].at(0),ottavi[o].at(1));
				c2++;
				if(c2 == 2) {
					c2 = 0;
					c1++
				}
			}
			c1=0,c2=0;
			for(int q = 0; q < 4; q++) {
				if(min(quarti[q].at(0),quarti[q].at(1)) == 0) return 'Q';
				sfinali[c1].at(c2) = max(quarti[q].at(0),quarti[q].at(1));
				c2++;
				if(c2 == 2) {
					c2 = 0;
					c1++
				}
			}
			c1=0,c2=0;
			for(int sf = 0; sf < 2; sf++) {
				if(min(sfinali[sf].at(0),sfinali[sf].at(1)) == 0) return 'H';
				finali[c1].at(c2) = max(sfinali[sf].at(0),sfinali[sf].at(1));
				c2++;
				if(c2 == 2) {
					c2 = 0;
					c1++
				}
			}
			if(min(finali[0].at(0),sfinali[0].at(1)) == 0) return 'F';
			else return 'V';
			break;
		}
		case 8: {
			for(int g = 0; g < 8; g++) {
				sort(gironi[g].begin(), gironi[g].end());
				if(gironi[g].at(2) == 0 || gironi[g].at(3) == 0) return 'G';
				ottavi[g].at(0) = gironi[g].at(0);
				ottavi[7-g].at(0) = gironi[g].at(1);
			}
			int c1=0,c2=0;
			for(int o = 0; o < 8; o++) {
				if(min(ottavi[o].at(0),ottavi[o].at(1)) == 0) return 'O';
				quarti[c1].at(c2) = max(ottavi[o].at(0),ottavi[o].at(1));
				c2++;
				if(c2 == 2) {
					c2 = 0;
					c1++
				}
			}
			c1=0,c2=0;
			for(int q = 0; q < 4; q++) {
				if(min(quarti[q].at(0),quarti[q].at(1)) == 0) return 'Q';
				sfinali[c1].at(c2) = max(quarti[q].at(0),quarti[q].at(1));
				c2++;
				if(c2 == 2) {
					c2 = 0;
					c1++
				}
			}
			c1=0,c2=0;
			for(int sf = 0; sf < 2; sf++) {
				if(min(sfinali[sf].at(0),sfinali[sf].at(1)) == 0) return 'H';
				finali[c1].at(c2) = max(sfinali[sf].at(0),sfinali[sf].at(1));
				c2++;
				if(c2 == 2) {
					c2 = 0;
					c1++
				}
			}
			if(min(finali[0].at(0),sfinali[0].at(1)) == 0) return 'F';
			else return 'V';
			break;
		}
		case 4: {
			for(int g = 0; g < 4; g++) {
				sort(gironi[g].begin(), gironi[g].end());
				if(gironi[g].at(2) == 0 || gironi[g].at(3) == 0) return 'G';
				quarti[g].at(0) = gironi[g].at(0);
				quarti[3-g].at(0) = gironi[g].at(1);
			}
			int c1=0,c2=0;
			for(int q = 0; q < 4; q++) {
				if(min(quarti[q].at(0),quarti[q].at(1)) == 0) return 'Q';
				sfinali[c1].at(c2) = max(Forza[quarti[q].at(0)],Forza[quarti[q].at(1)]);
				c2++;
				if(c2 == 2) {
					c2 = 0;
					c1++
				}
			}
			c1=0,c2=0;
			for(int sf = 0; sf < 2; sf++) {
				if(min(Forza[sfinali[sf].at(0)],Forza[sfinali[sf].at(1)]) == 0) return 'H';
				finali[c1].at(c2) = max(Forza[sfinali[sf].at(0)],Forza[sfinali[sf].at(1)]);
				c2++;
				if(c2 == 2) {
					c2 = 0;
					c1++
				}
			}
			if(min(finali[0].at(0),sfinali[0].at(1)) == 0) return 'F';
			else return 'V';
		}
		break;
	}
	return '';
}*/


int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	
	if(!in || !out) return -1;
	int m;
    if(fscanf(in,"%d",&m) != 1) return -1;
    int count = 0;
	for(int i = 0; i < m; i++) {
		if(fscanf(in,"%d",&Forza[i]) != 1) return -1;
		if(Forza[0] < Forza[i] && i > 0) count++;
	}
	if(m == 16) {
		if(count == 0) fprintf(out,"V");
		else if(count == 1) fprintf(out,"F");
		else if(count <= 8) fprintf(out,"H");
		else if(count <= 12) fprintf(out,"Q");
		else if(count <= 16) fprintf(out,"G");
	}
	else if(m == 32) {
		if(count == 0) fprintf(out,"V");
		else if(count == 1) fprintf(out,"F");
		else if(count <= 4) fprintf(out,"H");
		else if(count <= 8) fprintf(out,"Q");
		else if(count <= 16) fprintf(out,"O");
		else if(count <= 32) fprintf(out,"G");
	}
	else if(m == 64) {
		if(count == 0) fprintf(out,"V");
		else if(count == 1) fprintf(out,"F");
		else if(count <= 4) fprintf(out,"H");
		else if(count <= 8) fprintf(out,"Q");
		else if(count <= 16) fprintf(out,"O");
		else if(count <= 32) fprintf(out,"S");
		else if(count <= 62) fprintf(out,"G");
	}
	fclose(in);
	fclose(out);
	return 0;
}
