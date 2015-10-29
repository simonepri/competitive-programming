 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>
#include <cmath>

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define TYPE_EMPTY '-'
#define TYPE_FULL 'X'
#define TYPE_VIP 'O'

struct xyd {
	int x, y;
	double d;
	
		bool operator<(const xyd &pos) const {
			return d < pos.d;
		}
};

xyd make_xyd(int x, int y, double d) {
	xyd temp;
	temp.d = d;
	temp.x = x;
	temp.y = y;
	return temp;
}

double d(int x1, int y1, int x2, int y2) {
	int dx = x1-x2;
	int dy = y1-y2;
	return sqrt((dx*dx) + (dy*dy));
}

int main()
{
	for(int i = 0; i < 10; i++) {
		string file = "input_00" + to_string(i) + ".txt";
		ifstream in(file.c_str());
		file = "output_00" + to_string(i) + ".txt";
		ofstream out(file.c_str());
		
		if(!in || !out) return 1;

		unsigned long long N, K;
		in>>N>>K;
		vector< vector<char> > Matrix(N);
		vector<xyd> Q;
		for(int i = 0; i < N; i++) Matrix[i].resize(N);
		
		xyd vip;
		char read;
		bool flag = false;
		for(int x = 0; x < N; x++) {
			for(int y = 0; y < N; y++) {
				in>>Matrix[x][y];
				if(Matrix[x][y] == TYPE_EMPTY) {
					if(flag) Q.push_back(make_xyd(x, y, d(x, y, vip.x, vip.y)));
					else Q.push_back(make_xyd(x, y, 0));
				}
				else if(Matrix[x][y] == TYPE_VIP) {
					vip = make_xyd(x, y, 0);
					flag = true;
					for(int i = 0; i < Q.size(); i++) {
						Q[i].d = d(Q[i].x, Q[i].y, vip.x, vip.y);
					}
				}
			}
		}
		
		sort(Q.begin(), Q.end());
		for(int i = 0; i < K; i++) {
			Matrix[Q[i].x][Q[i].y] = TYPE_FULL;
		}
		for(int x = 0; x < N; x++) {
			for(int y = 0; y < N; y++) {
				out<<Matrix[x][y];
			}
			out<<endl;
		}
		
		in.close();
		out.close();
	}
	return 0;
}
