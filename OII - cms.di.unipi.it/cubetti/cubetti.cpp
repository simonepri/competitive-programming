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
	
	int N,read,count = 0;
	in>>N;
	vector<bool> check(N+1);
	for(int i = 0; i < N; i++) {
		in>>read;
		if(!check[read]) check[read] = true;
		else count++;
	}
	
	out<<count;
	
	in.close();
	out.close();
	return 0;
}
