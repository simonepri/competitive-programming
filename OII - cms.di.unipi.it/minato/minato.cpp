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

int BSF(const vector< vector<int> > &G, int start, int end) {
	queue<int> Q;
	int node,count = 0;
	Q.push(start);
	while(!Q.empty()) {
		node = Q.front();
		Q.pop();
		if(node != end) {
			for(vector<int>::const_iterator it = G[node].begin(); it != G[node].end(); it++) {
				Q.push(*it);
			}
		}
		else {
			count++;
		}
	}
	return count;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	int N,M;
	int idx_1, idx_2, node_1, node_2;
	string str[2];
	vector< vector<int> > Graph;
	in>>N>>M;
	Graph.resize(N*M);
	
	for(int i = 0; i < N; i++) {
		idx_1 = (i % 2); idx_2 = ((i-1) % 2);
		
		in>>str[idx_1];
		
		for(int j = 0; j < M; j++) {
			if(str[idx_1][j] == '*') {
				if(j-1 >= 0 && str[idx_1][j-1] == '*') {
					node_1 = (i*M) + j; node_2 = (i*M) + j-1;
					Graph[node_2].push_back(node_1);
				}
				if(i-1 >= 0 && str[idx_2][j] == '*') {
					node_1 = (i*M) + j; node_2 = ((i-1)*M) + j;
					Graph[node_2].push_back(node_1);
				}
			}
		}
	}
		
	out<<BSF(Graph,0,N*M-1);
	
	in.close();
	out.close();
	return 0;
}
