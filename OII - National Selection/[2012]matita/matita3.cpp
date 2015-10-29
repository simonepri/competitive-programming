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

ifstream in;
ofstream out;
vector< vector<int> > G;

void DFS(int node, int from) {
	int next;
	vector<int>::iterator it,it2;
	for(it = G[node].begin(); it != G[node].end(); it++) {
		if(*it != -1) {
			next = *it;
			*it = -1;
			it2 = find(G[next].begin(), G[next].end(), node);
			*it2 = -1;
			DFS(next, node);
		}
	}
	if(from != -1) out<<node<<" "<<from<<endl;
	return;
}

int main()
{
	in.open(FILE_INPUT);
	out.open(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N, M, A, B;
	in>>N>>M>>A>>B;
	G.resize(N+1);

	int X, Y;
	for(int i = 0; i < M; i++) {
		in>>X>>Y;
		G[X].push_back(Y);
		G[Y].push_back(X);
	}
	
	DFS(B,-1);
	
	in.close();
	out.close();
	return 0;
}
