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

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);

	if(!in || !out) return 1;

	int N;
	char c;
	in>>N;
	in.get(c);
	for(int i = 0; i < N; i++) {
		in.get(c);
		if('A' <= c && c <= 'Z') c |= (1<<5);
		else if('a' <= c && c <= 'z') c &= ~(0<<5);
		out<<c;
	}
	out<<endl;

	in.close();
	out.close();
	return 0;
}
