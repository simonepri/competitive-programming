 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>

#include <string>
#include <vector>
#include <map>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N

struct punto {
	short x,y;
};

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	unsigned short N,M;
	unsigned int somma = -1;	//inizializzazione al max
	short somma_x, somma_y;
	short min_x = 100, min_y = 100, max_x = -100, max_y = -100;
	short vect_min_x, vect_min_y, vect_max_x, vect_max_y;
	
	vector<punto> Stemma;
	vector< vector<unsigned short> > Campo;
	
	in>>N>>M;
	Stemma.resize(M);
	Campo.resize(N);
	
	for(unsigned short i = 0; i < M; i++) {
		in>>Stemma[i].x>>Stemma[i].y;
		
		if(Stemma[i].x < min_x) min_x = Stemma[i].x;
		if(Stemma[i].x > max_x) max_x = Stemma[i].x;
		
		if(Stemma[i].y < min_y) min_y = Stemma[i].y;
		if(Stemma[i].y > max_y) max_y = Stemma[i].y;
	}
	for(unsigned short i = 0; i < N; i++) {
		Campo[i].resize(N);
		for(unsigned short j = 0; j < N; j++) {
			in>>Campo[i][j];
		}
	}
	
	vect_min_x = -min_x, vect_min_y = -min_y;
	vect_max_x = vect_min_x+(N-1-(max_x-min_x)), vect_max_y = vect_min_y+(N-1-(max_y-min_y));
	
	for(short dx = vect_min_x; dx <= vect_max_x; dx++) {
		for(short dy = vect_min_y; dy <= vect_max_y; dy++) {
			unsigned int temp = 0;
			for(unsigned short i = 0; i < M; i++) {
				temp += Campo[Stemma[i].x+dx][Stemma[i].y+dy];
			}
			if(temp < somma && temp != 0) {
				somma = temp;
				somma_x = dx;
				somma_y = dy;
			}
		}
	}
	
	out<<somma_x<<" "<<somma_y<<" "<<somma;
	in.close();
	out.close();
	return 0;
}
