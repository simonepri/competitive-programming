 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int co_component(vector< vector<int> > &G, int N) {
	int top, cnt = 0;
	queue<int> Q;
	vector<bool> V(N);
	
	for(int start = 0; start < N; start++) {
		if(V[start] == false) {
			Q.push(start);
			V[start] = true;
			while(!Q.empty()) {
				top = Q.front();
				Q.pop();
				for(vector<int>::const_iterator it = G[top].begin(); it != G[top].end(); it++) {
					if(V[*it] == false) {
						V[*it] = true;
						Q.push(*it);
					}
				}
			}
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	ifstream fin(FILE_INPUT);
	ofstream fout(FILE_OUTPUT);

	if(!fin || !fout) return 1;

	int N, M, A, B;
	fin>>N>>M;
	vector< vector<int> > G(N);
	for(int i = 0; i < M; i++) {
		fin>>A>>B;
		G[A].push_back(B);
		G[B].push_back(A);
	}

	fout<<co_component(G, N)-1<<endl;

	fin.close();
	fout.close();
	return 0;
}
