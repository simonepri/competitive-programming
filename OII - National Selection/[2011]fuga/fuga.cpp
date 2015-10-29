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
#include <stack>
#include <queue>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

struct node {
	bool isvis, instk;
	int ind, low;
	vector<int> adj;
};

int N, M, IDX;
vector<node> G;
vector<int> P;
stack<int> S;

int min(int a, int b) {
	return (a < b) ? a : b;
}

int SCC(int node, int from = -1) {
	vector<int> Q;
    G[node].isvis = true; G[node].instk = true; G[node].ind = IDX; G[node].low = IDX;
	IDX++;
    S.push(node);
    for(vector<int>::iterator it = G[node].adj.begin(); it != G[node].adj.end(); it++){
		if(*it == from) continue;
        if(!G[*it].isvis){
            if(SCC(*it, node)) return 1;
            G[node].low = min(G[node].low, G[*it].low);
        }
        else if(G[*it].instk){
            G[node].low = min(G[node].low, G[*it].ind);
			return 1;
        }
    }
    if(G[node].low != G[node].ind) return 0;
	
    while(S.top() != node ){
        int v = S.top();
        S.pop();
		Q.push_back(v);
        G[v].instk = false;
    }
	Q.push_back(node);
    S.pop();
    G[node].instk = false;
	
	if(Q.size() >= 3) {
		P.swap(Q);
		return 1;
	}
	return 0;
}

int next_component(int node) {
	while(G[node].isvis) node++;
	return node % N;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	in>>N>>M;
	G.resize(N+1);
	
	int I, J, C;
	for(int i = 0; i < M; i++) {
		in>>I>>J>>C;
		if(C) {
			G[I].adj.push_back(J);
			G[J].adj.push_back(I);
		}
	}
	int start = 1;
	while(!SCC(start)) {
		start = next_component(start);
	}
	
	out<<P.size()<<endl;
	for(vector<int>::iterator it = P.begin(); it != P.end(); it++) {
		out<<*it<<" ";
	}
	
	in.close();
	out.close();
	return 0;
}
