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

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 0;
	int N, max = 0, smax = 0;
	vector<int> panini;
	vector<int> soluzione;
	
	in>>N;
	panini.resize(N);
	soluzione.resize(N);
	
	for(int i = 0; i < N; i++) {
		in>>panini[i];
		
		for(int j = 0; j < i; j++) {
			if(panini[j] > panini[i] && soluzione[j] > max) max = soluzione[j];
		}
		soluzione[i] = max+1;
		if(soluzione[i] > smax) smax = soluzione[i];
		max = 0;
	}
	
	out<<smax;
	in.close();
	out.close();
	return 0;
}
