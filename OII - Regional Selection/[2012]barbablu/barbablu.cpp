 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>
#include <limits>

#include <queue>
#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define pb push_back
#define mp make_pair

#define INF numeric_limits<int>::max()

typedef pair<int, int> pii;

vector<bool> AIR;
vector< vector<pii> > G;

struct cmp {
    bool operator()(const pii &a, const pii &b) {
        return a.second > b.second;
    }
};

int Dijkstra(int start, int finish, int N) {
	pii top;
	vector<int> D(N,INF);
	vector<int> A(N);
	priority_queue<pii, vector<pii>, cmp> Q;
	D[start] = 0;
	A[start] = 20;
	Q.push(mp(start,D[start]));
	while(!Q.empty()) {
		top = Q.top();
		Q.pop();
		if(top.first == finish) break;
		for(vector<pii>::iterator it = G[top.first].begin(); it != G[top.first].end(); it++) {
			if(top.second+it->second < D[it->first] && A[top.first]-it->second >= 0) {
				D[it->first] = top.second+it->second;
				if(!AIR[it->first])A[it->first] = A[top.first]-it->second;
				else A[it->first] = 20;
				Q.push(mp(it->first,D[it->first]));
			}
		}
	}
	if(D[finish] < INF) return D[finish];
	return -1;
}

int main()
{
	ifstream fin(FILE_INPUT);
	ofstream fout(FILE_OUTPUT);

	if(!fin || !fout) return 1;

	int M,N,C,K, read, I, J, L;
	fin>>N>>M>>C>>K;
	AIR.resize(N+1);
	G.resize(N+1);
	for(int i = 0; i < K; i++) {
		fin>>read;
		AIR[read] = true;
	}
	for(int i = 0; i < M; i++) {
		fin>>I>>J>>L;
		G[I].pb(mp(J,L));
		G[J].pb(mp(I,L));
	}
	fout<<Dijkstra(1,C,N+1);
	fin.close();
	fout.close();
	return 0;
}
