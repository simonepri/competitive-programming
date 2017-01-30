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
#include <limits>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define INF numeric_limits<int>::max()
#define mp make_pair
typedef pair<int,int> pii;

struct cmp {
	bool operator()(const pii a, const pii b) {
		if (a.first == b.first) return (a.second-a.first > b.second-b.first);
		return (a.first > b.first);
	}
};

int main()
{
	ifstream fin(FILE_INPUT);
	ofstream fout(FILE_OUTPUT);

	if(!fin || !fout) return 1;

	int K, N;
	pii top;
	fin>>K>>N;
	vector<int> sol(K+1,INF);
	priority_queue<pii, vector<pii>, cmp> Q;

	for(int i = 0; i < N; i++) {
		fin>>top.first>>top.second;
		top.second+=1;
		Q.push(top);
	}
	sol[0] = 0;
	while(!Q.empty()) {
		top = Q.top();
		Q.pop();
		int minsol = sol[top.first]+1;
		for(int i = top.first+1; i <= top.second; i++) {
			if(minsol < sol[i]) sol[i] = minsol;
		}
		if(top.second == K) break;
	}
	fout<<sol[K]<<endl;
	fin.close();
	fout.close();
	return 0;
}
