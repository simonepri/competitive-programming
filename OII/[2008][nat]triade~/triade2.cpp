 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>

#include <vector>
#include <set>
#include <queue>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

struct info {
	bool isvis, iscou;
	set<int> adj;
};

int M, N;
vector<info> G;

int BFS(int node, int from = -1) {
	int count = 0;
	G[node].isvis = true;
	for(set<int>::iterator it = G[node].adj.begin(); it != G[node].adj.end(); it++) {
		if(node > *it || from == *it) continue;
		else if(G[*it].isvis) count++;
		else count += BFS(*it, from);
	}
	return count;
}

int next_component(int node) {
	if(node >= N) return -1;
	while(G[node].isvis) node++;
	if(node >= N) return -1;
	return node;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	in>>M>>N;
	G.resize(N+1);

	int A, B;
	for(int i = 0; i < M; i++) {
		in>>A>>B;
		G[A].adj.insert(B);
		G[B].adj.insert(A);
	}
	
	int start = 1;
	int count = 0;
	while(start != -1) {
		count += BFS(start);
		start = next_component(start);
	}
	out<<count;

	in.close();
	out.close();
	return 0;
}
