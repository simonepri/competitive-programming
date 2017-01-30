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


int connected_part(const vector< vector<int> > &G) {
	int N = G.size();
	int node, count = 0;

	vector<bool> v(N);
	queue<int> Q;
	
	for(int i = 0; i < N; i++) {
		if(v[i] == false) {
			Q.push(i);
			v[i] = true;
			while(!Q.empty()) {
				node = Q.front();
				Q.pop();
				for(vector<int>::const_iterator it = G[node].begin(); it != G[node].end(); it++) {
					if(v[*it] == false) {
						Q.push(*it);
						v[*it] = true;
					}
				}
			}
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
	
	int N,M,pi,pj;
	
	in>>N>>M;
	vector< vector<int> > Graph(N);
	
	for(int i = 0; i < M; i++) {
		in>>pi>>pj;
		Graph[pi].push_back(pj);
		Graph[pj].push_back(pi);
	}
	
	out<<connected_part(Graph)-1;
	
	in.close();
	out.close();
	return 0;
}
