 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int main(){
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	int N, j, k;
	in>>N;
	string temp;
	vector<unsigned int> M(N);
	for(int i = 0; i < N; i++) in>>M[i];
	for(int r = 0; r < N; r++) {
        bool flag = false;
		vector< unordered_set<char> > S(M[r]*2000);
		for(int s = 0; s < M[r]; s++) {
			in>>j;
			in>>k;
			in>>temp;
			for(int s = 0; s < k; s++) {
                if(temp[s] == '?') continue;
				S[j+s].insert(temp[s]);
				if(S[j+s].size() > 2) {
                    flag = true;
                    break;
				}
			}
			if(flag) break;
		}
		if(flag) out<<1<<endl;
        else out<<0<<endl;
	}
	return 0;
}
