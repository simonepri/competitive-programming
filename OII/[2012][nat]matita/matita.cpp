 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>

#include <vector>
#include <stack>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

vector< vector<int> > G;
stack<int> Q;

void DFS(int node) {
	int N = G[node].size();
	for(int it = 0; it < N; it++) {
		if(G[node][it] != -1) {
			int actual = G[node][it];
			G[node][it] = -1;
			int N2 = G[actual].size();
			for(int it2 = 0; it2 < N2; it2++) {
				if(node == G[actual][it2]) {
					G[actual][it2] = -1;
					break;
				}
			}
			DFS(actual);
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
	out<<Q.top();
	Q.pop();
	
	in.close();
	out.close();
	return 0;
}
