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

typedef unsigned int ui;
typedef pair<ui, ui> puiui;

struct comp {
	bool operator() (const puiui &p1, const puiui &p2) {
	    if(p1.first == p2.first) return p1.second>p2.second;
		return p1.first>p2.first;
	}
};

int main()
{
	ifstream fin(FILE_INPUT);
	ofstream fout(FILE_OUTPUT);

	if(!fin || !fout) return 1;

	ui N, K, read, pos = 0, unuseful = 0;
	priority_queue<puiui, vector<puiui>, comp > Q;
	fin>>N>>K;
	for(ui i = 0; i < N; i++) {
		fin>>read;
		if(K > 0) {
            Q.push(make_pair(read,i));
            while(Q.size() > K+unuseful) {
                puiui top = Q.top();
                Q.pop();
                if(top.second < pos) {
                    unuseful--;
                    continue;
                }
                fout<<top.first<<" ";
                K -= top.second-pos;
                unuseful += top.second-pos;
                pos = top.second+1;
            }
		}
		else fout<<read<<" ";
	}
	fin.close();
	fout.close();
	return 0;
}
