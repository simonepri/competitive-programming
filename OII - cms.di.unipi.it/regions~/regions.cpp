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

vector< vector<int> > G;

int bfs(int start, int finish) {
	int count = 0;
	vector<bool> V(G.size());
	queue<int> Q;
	Q.push(start);
	while(!Q.empty()) {
		int actual = Q.front();
		V[actual] = true;
		Q.pop();
		for(int i = 0; i < G[actual].size(); i++) {
			if(G[actual][i] == finish) count++;
			else if(!V[G[actual][i]]) Q.push(G[actual][i]);
		}
	}
	return count;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N, R, Q;
	
	in>>N>>R>>Q;
	
	vector<int> H(N+1);
	G.resize(R+1);
	
	in>>H[1];
	for(int i = 2; i <= N; i++) {
		int S;
		in>>S>>H[i];
		G[H[S]].push_back(H[i]);
	}
	
	for(int i = 0; i < Q; i++) {
		int r1, r2;
		in>>r1>>r2;
		out<<bfs(r1, r2)<<endl;
	}
	in.close();
	out.close();
	return 0;
}
