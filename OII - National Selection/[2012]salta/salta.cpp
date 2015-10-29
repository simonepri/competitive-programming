 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>
#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N;
	int count = 0;
	in>>N;
	vector<int> V(N+1);
	vector<bool> S(N+1);
	for(int i = 1; i <= N; i++) in>>V[i];
	int pos = 1;
	while(S[pos] == false) {
		S[pos] = true;
		count++;
		pos = ((pos+V[pos])%N)+1;
	}
	out<<N-count<<endl;
	for(int i = 1; i <= N; i++) if(S[i] == false) out<<i<<" ";
	in.close();
	out.close();
	return 0;
}
