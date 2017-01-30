 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int main() {
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);

	if(!in || !out) return 1;

	unsigned int N, M;
	in>>N>>M;
	
	
	
	out<<M;
	in.close();
	out.close();
	return 0;
}
