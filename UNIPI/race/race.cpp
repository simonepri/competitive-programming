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

struct node {
	int n, p;
};

struct maxs {
	int m1, m2;
};

vector< vector<node> > race;
vector<maxs> pmax;

void bfs() {
	queue<int> Q;
	Q.push(1);
	while(!Q.empty()) {
		int actual = Q.front();
		cout<<actual<<endl;
		Q.pop();
		for(vector<node>::iterator it = race[actual].begin(); it != race[actual].end(); it++) {
			int t_m1, t_m2;
			if(pmax[actual].m1 > it->p) {
				t_m1 = pmax[actual].m1;
				t_m2 = (pmax[actual].m2 > it->p) ? pmax[actual].m2 : it->p;
			}
			else {
				t_m1 = it->p;
				t_m2 = pmax[actual].m1;
			}
			if(t_m2 < pmax[it->n].m2 || pmax[it->n].m2 == 0) {
				pmax[it->n].m1 = t_m1;
				pmax[it->n].m2 = t_m2;
				Q.push(it->n);
			}
		}
	}
	return;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	int N, M;
	in>>N>>M;
	pmax.resize(N+1);
	race.resize(N+1);
	for(int i = 0; i < M; i++) {
		int n;
		node temp;
		in>>n>>temp.n>>temp.p;
		race[n].push_back(temp);
	}
	bfs();
	out<<pmax[N].m2;
	in.close();
	out.close();
	return 0;
}
