 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>

#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

struct node {
	bool isvis;
	vector<int> adj;
};

int N, M;
vector<node> G;
vector<int> P;

int min(int a, int b) {
	return (a < b) ? a : b;
}

int SCC(int node, int from = -1) {
	vector<int> Q;
    G[node].isvis = true;
    for(vector<int>::iterator it = G[node].adj.begin(); it != G[node].adj.end(); it++){
		if(*it == from) continue;
        if(!G[*it].isvis) {
            int ret = SCC(*it, node);
			if(ret != -1) {
				if(ret != 0) {
					P.push_back(node);
					if(ret == node) return 0;
				}
				return ret;
			}
        }
		else {
			P.push_back(node);
			return *it;
		}
    }
	return -1;
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
	while(SCC(start) == -1) {
		start = next_component(start);
		if(start == -1) break;
	}
	
	out<<P.size()<<endl;
	for(vector<int>::iterator it = P.begin(); it != P.end(); it++) {
		out<<*it<<" ";
	}
	
	in.close();
	out.close();
	return 0;
}
