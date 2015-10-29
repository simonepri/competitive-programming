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

vector< vector<int> > G;
stack<int> Q;

void DFS(int node) {
	int it_temp;
	vector<int>::iterator it,it2;
	for(it = G[node].begin(); it != G[node].end(); it++) {
		if(*it != -1) {
			it_temp = *it;
			*it = -1;
			it2 = find(G[it_temp].begin(), G[it_temp].end(), node);
			*it2 = -1;
			DFS(it_temp);
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

	int X, Y;
	for(int i = 0; i < M; i++) {
		in>>X>>Y;
		G[X].push_back(Y);
		G[Y].push_back(X);
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
