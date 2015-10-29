 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

struct last {
	int val,len;
	bool sign;
	bool undef;
};

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	int N, read;
	last solution;
	in>>N;
	
	in>>solution.val;
	solution.undef = true;
	solution.len = 1;
	
	for(int i = 1; i < N; i++) {
		in>>read;
		if(solution.val != read) {
			bool sign = (solution.val - read > 0);
			if(solution.sign != sign || solution.undef) {
				solution.sign = sign;
				solution.undef = false;
				solution.len++;
			}
		}
		solution.val = read;
	}
	out<<solution.len;
	
	in.close();
	out.close();
	return 0;
}
