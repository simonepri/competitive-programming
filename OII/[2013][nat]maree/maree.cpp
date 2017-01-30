 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <vector>
#include <limits>
#include <queue>
#include <functional>

//#include <fstream>

#define DIJKSTRA_INFINITE numeric_limits<int>::max()

//#define FILE_INPUT "input.txt"
//#define FILE_OUTPUT "output.txt"

using namespace std;

struct nodes {
	vector<int> nM;
	vector<int> yM;
	int D;
	nodes() {
		D = DIJKSTRA_INFINITE;
	}
};

vector<nodes> G;

struct queue_comp {
	bool operator() (const int &p1, const int &p2) {
		return G[p1].D > G[p2].D;
	}
};


int dijkstra(int start, int finish, int T) {
	
	priority_queue<int, vector<int>, queue_comp> Q;
	int actual;
	
	Q.push(start);
	G[start].D = 0;
	while(!Q.empty()) {
		actual = Q.top();
		if(actual == finish) break;
		Q.pop();
		
		if(G[actual].D < T) {
			for(vector<int>::iterator it = G[actual].nM.begin(); it != G[actual].nM.end(); it++) {
				if(G[actual].D + 1 < G[*it].D) {
					G[*it].D = G[actual].D + 1;
					Q.push(*it);
				}
			}
			for(vector<int>::iterator it = G[actual].yM.begin(); it != G[actual].yM.end(); it++) {
				if(T + 1 < G[*it].D) {
					G[*it].D = T + 1;
					Q.push(*it);
				}
			}
		}
		else {
			for(vector<int>::iterator it = G[actual].yM.begin(); it != G[actual].yM.end(); it++) {
				if(G[actual].D + 1 < G[*it].D) {
					G[*it].D = G[actual].D + 1;
					Q.push(*it);
				}
			}
		}
	}
	return G[finish].D != DIJKSTRA_INFINITE ? G[finish].D : -1;
}

int solve(int N, int M, int T, int* S, int* E) {
	G.resize(N);
	
	for(int i = 0; i < M; i++) {
		G[S[i]].nM.push_back(E[i]);
		G[E[i]].yM.push_back(S[i]);
	}
	
	return dijkstra(0, N-1, T);
}

/*int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N,M,T,S[3000000],E[3000000];
	in>>N>>M>>T;
	for(int i = 0; i < M; i++) {
		in>>S[i]>>E[i];
	}
	out<<solve(N, M, T, S, E);
	
	in.close();
	out.close();
	return 0;
}*/
