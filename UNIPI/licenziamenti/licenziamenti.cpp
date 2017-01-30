 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
#include <queue>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int bfs(vector< vector<int> > &G, vector<int> &B) {
    unsigned int cnt = 0;
    pair<int,int> top;
    queue< pair<int,int> > Q;
    Q.push(make_pair(0,numeric_limits<int>::max()));
    while(!Q.empty()) {
        top = Q.front();
        Q.pop();
        if(B[top.first] > top.second) {
            B[top.first] = top.second;
            cnt++;
        }
        for(vector<int>::iterator it = G[top.first].begin(); it != G[top.first].end(); it++) {
            Q.push(make_pair(*it,B[top.first]));
        }
    }
    return cnt;
}

int main()
{
	ifstream fin(FILE_INPUT);
	ofstream fout(FILE_OUTPUT);

	if(!fin || !fout) return 1;

	int N, C, cnt = 0;
	fin>>N;
	vector<int> B(N);
	vector< vector<int> > G(N);

    fin>>B[0]>>C;
	for(int i = 1; i < N; i++) {
		fin>>B[i]>>C;
		G[C].push_back(i);
	}

	fout<<bfs(G,B)<<endl;

	fin.close();
	fout.close();
	return 0;
}
