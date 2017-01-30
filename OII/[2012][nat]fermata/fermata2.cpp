 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

struct trans {
	int state, move;
	int sol;
};

int N, S, C;
vector<int> Nastro;
vector<trans> Tab;

bool dfs(int n, int s) {
	if(n == 0) return true;
	if(Tab[n*S+s].sol == 1) return true;
	else if(Tab[n*S+s].sol == 2) return false;
	Tab[n*S+s].sol = 2;
	if(dfs(n+Tab[Nastro[n]*S+s].move, Tab[Nastro[n]*S+s].state)) {
		Tab[n*S+s].sol = 1;
		return true;
	}
	return false;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	in>>N>>S>>C;
	Nastro.resize(N);
	Tab.resize(1000000);

	
	for(int i = 0; i < S; i++) {
		for(int j = 0; j < C; j++) {
			int s,c;
			in>>s>>c;
			in>>Tab[c*S+s].state>>Tab[c*S+s].move;
		}
	}
	for(int i = 0; i < N; i++) {
		in>>Nastro[i];
	}
	
	queue<int> Q;
	for(int i = 0; i < N; i++) {
		if(dfs(i,0) == true) Q.push(i);
	}
	out<<Q.size();
	while(!Q.empty()) {
		out<<endl<<Q.front();
		Q.pop();
	}
	
	in.close();
	out.close();
	return 0;
}
