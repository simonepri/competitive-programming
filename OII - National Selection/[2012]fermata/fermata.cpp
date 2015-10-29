 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
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
	int used;
};

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	int N, S, C;
	in>>N>>S>>C;
	queue<int> Q;
	vector<int> A(N);
	vector<bool> Sol(N);
	vector< vector<trans> > T(S);
	
	for(int i = 0; i < S; i++) {
		T[i].resize(C);
		for(int j = 0; j < C; j++) {
			int s,c;
			in>>s>>c;
			in>>T[s][c].state>>T[s][c].move;
		}
	}
	
	for(int i = 0; i < N; i++) {
		in>>A[i];
	}
	
	for(int i = 0; i < N; i++) {
		int pos = i;
		int s = 0;
		while(1) {
			if(pos == 0) {
				Sol[i] = true;
				Q.push(i);
				break;
			}
			
			if(T[s][A[pos]].used != 0) {
				Sol[i] = Sol[T[s][A[pos]].used];
				if(Sol[i] == true) Q.push(i);
				break;
			}
			T[s][A[pos]].used = i;
			
			int temp = pos + T[s][A[pos]].move;
			s = T[s][A[pos]].state;
			pos = temp;
		}
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
