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

#define GRAPH_INFINITE numeric_limits<int>::max()

int BSF(const vector< vector<int> > &G, int start, int end) {
	vector<int> d(G.size(),GRAPH_INFINITE); //distanze

	queue<int> Q;
	Q.push(start);
	d[start] = 1;
	int node;
	while(!Q.empty()) {
		node = Q.front();
		Q.pop();
		for(vector<int>::const_iterator it = G[node].begin(); it != G[node].end(); it++) {
			if(d[*it] > d[node]+1) {
				d[*it] = d[node]+1;
				Q.push(*it);
			}
		}
	}
	return d[end];
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 0;
	int N;
	int idx_1, idx_2, node_1, node_2;
	string str[2];
	vector< vector<int> > Graph;
	in>>N;
	Graph.resize(N*N);
	
	for(int i = 0; i < N; i++) {
		idx_1 = (i % 2); idx_2 = ((i-1) % 2);
		
		in>>str[idx_1];
		
		for(int j = 0; j < N; j++) {
			if(str[idx_1][j] == '*') {
				if(j-1 >= 0 && str[idx_1][j-1] == '*') {
					node_1 = (i*N) + j; node_2 = (i*N) + j-1;
					Graph[node_1].push_back(node_2); Graph[node_2].push_back(node_1);
				}
				if(i-1 >= 0 && j-1 >= 0 && str[idx_2][j-1] == '*') {
					node_1 = (i*N) + j; node_2 = ((i-1)*N) + j-1;
					Graph[node_1].push_back(node_2); Graph[node_2].push_back(node_1);
				}
				if(i-1 >= 0 && str[idx_2][j] == '*') {
					node_1 = (i*N) + j; node_2 = ((i-1)*N) + j;
					Graph[node_1].push_back(node_2); Graph[node_2].push_back(node_1);
				}
				if(i-1 >= 0 && j+1 < N && str[idx_2][j+1] == '*') {
					node_1 = (i*N) + j; node_2 = ((i-1)*N) + j+1;
					Graph[node_1].push_back(node_2); Graph[node_2].push_back(node_1);
				}
			}
		}
	}
	
	out<<BSF(Graph,0,N*N-1);
	
	in.close();
	out.close();
	return 0;
}
