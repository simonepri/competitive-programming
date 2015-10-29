 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>
#include <iostream>

#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define m_p(a,b) make_pair(a,b)

typedef pair<int,int> pii;

vector< vector<pii> > G;

int BFS(int start, int N) {
	vector<int> D(N+1, numeric_limits<int>::max());
	queue<pii> Q;
	D[start] = 0;
	pii top = m_p(start,0);
	Q.push(top);
	while(!Q.empty()) {
		top = Q.front();
		Q.pop();
		for(vector<pii>::iterator it = G[top.first].begin(); it != G[top.first].end(); it++) {
			if(top.second+it->second < D[it->first]) {
				D[it->first] = top.second+it->second;
				Q.push(m_p(it->first, D[it->first]));
			}
		}
	}
	int cnt = 0;
	for(int i = 1; i <= N; i++) {
		if(D[i] <= i*10) cnt++;
	}
	return cnt;
}

int main()
{
	ifstream fin(FILE_INPUT);
	ofstream fout(FILE_OUTPUT);

	if(!fin || !fout) return 1;
	int N, M, n1, n2, ar;
	fin>>N>>M;
	G.resize(N+1);
	for(int i = 0; i < M; i++) {
		fin>>n1>>n2>>ar;
		G[n1].push_back(m_p(n2,ar));
		G[n2].push_back(m_p(n1,ar));
	}
	fout<<BFS(1,N)<<endl;
	fin.close();
	fout.close();
	return 0;
}
