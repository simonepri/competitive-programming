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

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

typedef pair<int,int> pii;

struct cmp {
	bool operator()(const pii a, const pii b) {
		return a.first > b.first;
	}
};

int abs(int a) {
	return (a > 0 ? a : -a);
}

int dist(int x1, int y1, int x2, int y2) {
	return abs(x2-x1)+abs(y2-y1);
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);

	if(!in || !out) return 1;

	int N, X = 1, Y, minm = 0;
	pii read;
	priority_queue<pii,vector<pii>, cmp> Q;
	in>>N>>Y;
	for(int i = 0; i < N; i++) {
		in>>read.second>>read.first; //Y e X
		Q.push(read);
	}
	while(!Q.empty()) {
		read = Q.top();
		Q.pop();
		minm += dist(read.first, read.second,X,Y);
		X++;
	}
	out<<minm<<endl;
	in.close();
	out.close();
	return 0;
}
