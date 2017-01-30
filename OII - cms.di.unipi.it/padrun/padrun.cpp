 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>

#include <string>
#include <vector>
#include <map>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	int N;
	in>>N;
	
	for(int i = 0; i < N; i++) {
		int a, b;
		in>>a>>b;
	}
	in.close();
	out.close();
	return 0;
}
