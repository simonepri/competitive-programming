 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>

#include <queue>
#include <limits>
#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define INFINITE numeric_limits<int>::max()

vector< vector< pair<int, int> > > G;

int BFS(int start) {
	vector<int> D(G.size, INFINITE);
	vector<int> P(G.size);
	priority_queue<int, vector<int>, greater<int> > Q;
	
	Q.push(start);
	D[start] = 0;
	P[start] = 1;
	while(!Q.empty()) {
		actual = Q.front();
		Q.pop();
		for(vector< pair<int, int> >::iterator it = G[actual].begin(); it != G[actual].end(); it++) {
			if(D[it->first] != INFINITE) continue;
			
		}
	}
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N, M;
	in>>N>>M;
	
	G.resize(N+1);
	for(int i = 0; i < M; i++) {
		int a, b, c;
		in>>a>>b>>c;
		G[a].push_back(make_pair(b, c));
		G[b].push_back(make_pair(a, c));
	}
	
	out<<BFS(1);
	
	in.close();
	out.close();
	return 0;
}
