 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>
#include <cmath>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"


int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N;
	char bits, count = 0;
	in>>N;
	bits = ceil(log2(N));
	for(int i = 0; i <= bits; i++) {
		if((N & (1 << i)) != 0) count++;
	}
	out<<(int)count;
	in.close();
	out.close();
	return 0;
}
