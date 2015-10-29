 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>

#include <vector>
#include <queue>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

struct info {
	bool isvis, iscou;
	vector<int> adj;
};

int M, N;
vector<info> G;

int BFS(int start) {
	int count = 0;
	queue<int> Q;
	Q.push(start);
	while(!Q.empty()){
		int actual = Q.front();
		Q.pop();
		if(G[actual].isvis) {
			if(!G[actual].iscou) {
				G[actual].iscou = true;
				count++;
			}
			continue;
		}
		G[actual].isvis = true;
		for(vector<int>::iterator it = G[actual].adj.begin(); it != G[actual].adj.end(); it++) {
			if(G[*it].isvis) continue;
			Q.push(*it);
		}
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
		G[A].adj.push_back(B);
		G[B].adj.push_back(A);
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
