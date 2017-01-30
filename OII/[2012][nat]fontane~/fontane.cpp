 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>

#include <queue>
#include <limits>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define INFINITE numeric_limits<int>::max()

struct point {
	int x,y;
};

queue<point> P;
vector<point> FX;
vector<point> FY;

struct cmp_x {
	bool operator() (const point &p1, const point &p2) {
		return p1.x < p2.x;
	}
	bool operator() (const point &p1, const int &x) {
		return p1.x < x;
	}
};

struct cmp_y {
	bool operator() (const point &p1, const point &p2) {
		return p1.y < p2.y;
	}
	bool operator() (const point &p1, const int &y) {
		return p1.y < y;
	}
};

int abs(int a) {
	return a >= 0 ? a : -a;
}

int distance_1D(int x1, int x2) {
	return abs(x2-x1);
}

int distance_2D(point p1, point p2) {
	return (p1.x == p2.x) ? (distance_1D(p1.y,p2.y)) : ((p1.y == p2.y) ? (distance_1D(p1.x,p2.x)) : (-1));
}

int nearest(point p1, point p2, point &f1) {
	int min = INFINITE, temp;
	if(p1.y == p2.y) {
		for(vector<point>::iterator it = lower_bound(FY.begin(), FY.end(), p2.y,cmp_y()); it != FY.end() && it->y == p2.y; it++) {
			if(p1.x < it->x && it->x <= p2.x || p2.x <= it->x && it->x < p1.x) {
				temp = distance_1D(p1.x,it->x);
				if(temp < min) {
					min = temp;
					f1 = *it;
				}
			}
		}
	}
	else if(p1.x == p2.x) {
		for(vector<point>::iterator it = lower_bound(FX.begin(), FX.end(), p2.x,cmp_x()); it != FX.end() && it->x == p2.x; it++) {
			if(p1.y < it->y && it->y <= p2.y || p2.y <= it->y && it->y < p1.y) {
				temp = distance_1D(p1.y,it->y);
				if(temp < min) {
					min = temp;
					f1 = *it;
				}
			}
		}
	}
	return min < INFINITE ? min : -1;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N, M;
	point turing,percorso,fontanella;
	in>>N>>M;
	in>>turing.x>>turing.y;
	for(int i = 0; i < N; i++) {
		in>>percorso.x>>percorso.y;
		P.push(percorso);
	}
	FX.reserve(M); FY.reserve(M);
	for(int i = 0; i < M; i++) {
		in>>fontanella.x>>fontanella.y;
		FX.push_back(fontanella);
		FY.push_back(fontanella);
	}
	sort(FX.begin(), FX.end(), cmp_x()); sort(FY.begin(), FY.end(), cmp_y());

	int max = 0, done = 0;
	while(!P.empty()) {
		percorso = P.front();
		P.pop();
		int dist;
		while(1) {
			int dist = nearest(turing,percorso,fontanella);
			if(dist == -1) break;
			turing = fontanella;
			int pay = 100-(done+dist);
			done = 0;
			if(-pay > max) max = -pay;
		}
		done += distance_2D(turing, percorso);
		turing = percorso;
		int pay = 100-(done);
		if(-pay > max) max = -pay;
	}
	out<<max;
	
	in.close();
	out.close();
	return 0;
}
