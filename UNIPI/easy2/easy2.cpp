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

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N,t1,t2,max = -1,temp;
	
	in>>N;
	
	for(int i = 0; i < N; i++) {
		in>>t1;
		in>>t2;
		temp = t1 + t2;
		if(temp % 2 != 0) continue;
		if(temp > max) max = temp;
	}
	
	out<<max;
	
	in.close();
	out.close();
	return 0;
}
