 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>
#include <queue>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define m_p(a,b) make_pair(a,b)

typedef pair<int,float> pif;

struct cmp {
    bool operator()(pif const& a, pif const& b) const  {
        return a.second < b.second;
    }
};

int main()
{
	ifstream fin(FILE_INPUT);
	ofstream fout(FILE_OUTPUT);

	if(!fin || !fout) return 1;
	int N, K, p, f;
	pif top;
	priority_queue<pif, vector<pif>, cmp> V;
	fin>>N>>K;
	for(int i = 1; i <= N; i++) {
		fin>>f>>p;
		V.push(m_p(i,f-1.5*p));
	}
	for(int i = 0; i < K; i++) {
		top = V.top();
		V.pop();
		fout<<top.first<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}
