 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>

#include <vector>
#include <queue>

using namespace std;

#define TYPE_EMPTY '-'
#define TYPE_FULL 'X'
#define TYPE_VIP 'O'

struct pii {
	int r, c;
};

pii make_pii(int c, int r) {
	pii temp;
	temp.r = r;
	temp.c = c;
	return temp;
}

int N, K;
vector< vector<char> > Matrix;

void BFS(pii start) {
	int k = K;
	bool flag = 0;
	queue<pii> Q;
	queue<pii> Q2;
	Q.push(start);
	while(!Q.empty()) {
		pii Pos = Q.front();
		Q.pop();
		if(Pos.c-1 >= 0 && Matrix[Pos.c-1][Pos.r] == TYPE_EMPTY) {
			Matrix[Pos.c-1][Pos.r] = TYPE_FULL;
			k--;
			if(k == 0) return;
			Q.push(make_pii(Pos.c-1, Pos.r));
		}
		if(Pos.c+1 < N && Matrix[Pos.c+1][Pos.r] == TYPE_EMPTY) {
			Matrix[Pos.c+1][Pos.r] = TYPE_FULL;
			k--;
			if(k == 0) return;
			Q.push(make_pii(Pos.c+1, Pos.r));
		}
		if(Pos.r-1 >= 0 && Matrix[Pos.c][Pos.r-1] == TYPE_EMPTY) {
			Matrix[Pos.c][Pos.r-1] = TYPE_FULL;
			k--;
			if(k == 0) return;
			Q.push(make_pii(Pos.c, Pos.r-1));
		}
		if(Pos.r+1 < N && Matrix[Pos.c][Pos.r+1] == TYPE_EMPTY) {
			Matrix[Pos.c][Pos.r+1] = TYPE_FULL;
			k--;
			if(k == 0) return;
			Q.push(make_pii(Pos.c, Pos.r+1));
		}
		if(flag == 0) Q2.push(Pos);
		while(!Q2.empty()) {
			pii Pos2 = Q2.front();
			Q2.pop();
			if((Pos2.c-1 >= 0 && Pos2.r-1 >= 0) && Matrix[Pos2.c-1][Pos2.r-1] == TYPE_EMPTY) {
				Matrix[Pos2.c-1][Pos2.r-1] = TYPE_FULL;
				k--;
				if(k == 0) return;
				Q.push(make_pii(Pos2.c-1, Pos2.r-1));
			}
			if((Pos2.c+1 < N && Pos2.r+1 < N) && Matrix[Pos2.c+1][Pos2.r+1] == TYPE_EMPTY) {
				Matrix[Pos2.c+1][Pos2.r+1] = TYPE_FULL;
				k--;
				if(k == 0) return;
				Q.push(make_pii(Pos2.c+1, Pos2.r+1));
			}
			if((Pos2.c+1 < N && Pos2.r-1 >= 0) && Matrix[Pos2.c+1][Pos2.r-1] == TYPE_EMPTY) {
				Matrix[Pos2.c+1][Pos2.r-1] = TYPE_FULL;
				k--;
				if(k == 0) return;
				Q.push(make_pii(Pos2.c+1, Pos2.r-1));
			}
			if((Pos2.c-1 >=0 && Pos2.r+1 < N) && Matrix[Pos2.c-1][Pos2.r+1] == TYPE_EMPTY) {
				Matrix[Pos2.c-1][Pos2.r+1] = TYPE_FULL;
				k--;
				if(k == 0) return;
				Q.push(make_pii(Pos2.c-1, Pos2.r+1));
			}
			break;
		}
		if(flag == 1) Q2.push(Pos);
		flag = 1;
	}
	return;
}

int main()
{
	for(int i = 0; i < 10; i++) {
		string file = "input_00" + to_string(i) + ".txt";
		ifstream in(file.c_str());
		file = "output_00" + to_string(i) + ".txt";
		ofstream out(file.c_str());
		
		if(!in || !out) return 1;

		in>>N>>K;
		
		Matrix.resize(N);
		for(int i = 0; i < N; i++) Matrix[i].resize(N);
		
		pii start;
		char read;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				in>>Matrix[i][j];
				if(Matrix[i][j] == TYPE_VIP) start = make_pii(i, j);
			}
		}
		
		BFS(start);
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				out<<Matrix[i][j];
			}
			out<<endl;
		}
		
		in.close();
		out.close();
	}
	return 0;
}
