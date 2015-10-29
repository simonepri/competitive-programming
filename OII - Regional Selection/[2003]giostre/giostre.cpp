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

#define MIN_GIOSTRA 21

int solution_1(unsigned short a, unsigned short b) {
	vector<bool> V(a);
	int inc = 0;
	while(!V[inc % a]) {
		V[inc % a] = true;
		inc += b;
	}
	return inc/b;
}

int solution_2(unsigned short a) {
	unsigned short start = 20;
	while(solution_1(a,start) != a) start++;
	return start;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 0;
	
	unsigned short A, B;
	in>>A>>B;
	out<<solution_1(A,B)<<" "<<solution_2(A);
	
	in.close();
	out.close();
	return 0;
}
