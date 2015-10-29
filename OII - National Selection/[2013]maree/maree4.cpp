 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <vector> 
#include <queue> 
#include <limits>

#define INFINITE numeric_limits<int>::max()

using namespace std; 

int N, M, T; 

vector< vector<int> > G;

void bfs(int start, vector<int> &d, int T) {
	queue<int> Q; 
	Q.push(start);
	d[start] = 0;
	while (!Q.empty()) {
		int actual = Q.front();
		Q.pop();
		for (vector<int>::iterator it = G[actual].begin(); it != G[actual].end(); it++) {
			if(d[*it] == INFINITE) {
				d[*it] = d[actual] + 1;
				if(d[*it] < T) Q.push(*it);
			}
		}
	}
}

void rbfs(int start, vector<int> &d) {
	queue<int> Q; 
	Q.push(start);
	d[start] = 0;
	while (!Q.empty()) {
		int actual = Q.front();
		Q.pop();
		for (vector<int>::iterator it = G[actual].begin(); it != G[actual].end(); it++) {
			if(d[*it] == INFINITE) {
				d[*it] = d[actual] + 1;
				Q.push(*it);
			}
		}
	}
} 

int solve(int N, int M, int T, int S[], int E[]) {
	G.resize(N);
	vector<int> rdist(N,INFINITE), dist(N,INFINITE);
	
	for (int i = 0; i < M; i++) {
		G[S[i]].push_back(E[i]);
	}
	
	bfs(0, dist, T);
	
	if (dist[N-1] <= T) return dist[N-1];
	
	rbfs(N-1, rdist);

	int best = INFINITE;

	for(int i = 0; i < N; i++) {
		if(dist[i] <= T && rdist[i] < INFINITE) {
			int temp = T + rdist[i]; 
			if (temp < best) best = temp;
		}
	}
	if (best == INFINITE) return -1; 
	
	return best; 
} 
/*
#include <fstream>

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N,M,T,S[300],E[300];
	in>>N>>M>>T;
	for(int i = 0; i < M; i++) {
		in>>S[i]>>E[i];
	}
	out<<solve(N, M, T, S, E);
	
	in.close();
	out.close();
	return 0;
}*/
