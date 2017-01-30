 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>

#include <algorithm>
#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	int N,D,M,temp,profitto=0;
	vector<int> costi;
	in>>N>>D;
	costi.resize(N);
	
	for(int i = 0; i < N; i++) {
		in>>costi[i];
	}
	in>>M;
	
	sort(costi.begin(),costi.end());
	
	for(int i = 0; i < (N < M ? N : M); i++) profitto += costi[i];
	if(N < M) profitto -= D*(M-N);
	
	out<<profitto;
	
	in.close();
	out.close();
	return 0;
}
