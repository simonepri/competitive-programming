 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>

#include <string>
#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	int N,M;
	int idx_now, idx_next;
	string row;
	vector<int> soluzione;
	
	in>>N>>M;
	
	soluzione.resize(M);
	soluzione[0] = 1;
	for(int i = 0; i < N; i++) {
		in>>row;
		
		for(int j = 0; j < M; j++) {
			if(row[j] == '*') {
				if(j+1 < M) soluzione[j+1] += soluzione[j];
			}
			else soluzione[j] = 0;
		}
	}
	
	out<<soluzione[M-1];
	
	in.close();
	out.close();
	return 0;
}
