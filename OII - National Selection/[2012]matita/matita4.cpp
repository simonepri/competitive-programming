 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>

#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

struct point {
	int node, rapid_search;
};

point make_point(int node, int rapid_search) {
	point temp;
	temp.node = node;
	temp.rapid_search = rapid_search;
	return temp;
}

vector< vector<point> > G;
stack<int> Q;

void DFS(int node) {
	vector<point>::iterator it,it2;
	for(it = G[node].begin(); it != G[node].end(); it++) {
		if(it->rapid_search != -1) {
			it2 = G[it->node].begin() + it->rapid_search;
			it->rapid_search = -1;
			it2->rapid_search = -1;
			DFS(it->node);
		}
	}
	Q.push(node);
	return;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N, M, A, B;
	in>>N>>M>>A>>B;
	G.resize(N+1);

	point temp_x, temp_y;
	int X, Y;
	for(int i = 0; i < M; i++) {
		in>>X>>Y;
		temp_x.node = X;
		temp_x.rapid_search = G[X].size();
		temp_y.node = Y;
		temp_y.rapid_search = G[Y].size();

		G[X].push_back(temp_y);
		G[Y].push_back(temp_x);
	}
	
	DFS(A);

	out<<Q.top()<<" ";
	Q.pop();
	while(Q.size() > 1) {
		out<<Q.top()<<endl;
		out<<Q.top()<<" ";
		Q.pop();
	}
	out<<Q.top()<<endl;
	Q.pop();
	
	in.close();
	out.close();
	return 0;
}
