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
#include <queue>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

bool U[2001];
vector< vector<int> > G(2001);

int BFS(int start) {
	int count = 1, top;
	queue<int> Q;
	Q.push(start);
	while(!Q.empty()) {
		top = Q.front();
		Q.pop();
		if(G[top].size() == 0) return -1;
		for(vector<int>::iterator it = G[top].begin(); it != G[top].end(); it++) {
			if(!U[*it]) {
				count++;
				U[*it] = true;
				Q.push(*it);
			}
		}
	}
	return count;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);

	if(!in || !out) return 1;

	int K, R, A, N, read;
	in>>K>>R;
	for(int i = 0; i < K; i++) {
		in>>read;
		if(read == 1) {
            out<<0;
            in.close();
            out.close();
            return 0;
		}
		U[read] = true;
	}
	for(int i = 0; i < R; i++) {
		in>>A>>N;
		for(int j = 0; j < N; j++) {
			in>>read;
			G[A].push_back(read);
		}
	}
	out<<BFS(1);
	in.close();
	out.close();
	return 0;
}
