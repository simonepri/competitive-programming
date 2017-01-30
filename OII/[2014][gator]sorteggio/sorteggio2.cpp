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

#define MAX_N

char sol16[] = "VFFHHHHHHHQQQQGG";
char sol32[] = "VFFFFHHHHHHHHHHHHHHQQQQQQQOOOOGG";
char sol64[] = "VFFFFFFFHHHHHHHHHHHHHHHHHHHHHHHHHHHHQQQQQQQQQQQQQQOOOOOOOOSSSSGG";

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	int M,S,temp,count = 0;
	in>>M;
	in>>S;
	for(int i = 0; i < M-1; i++) {
		in>>temp;
		if(temp > S) count++;
	}
	
	if(M == 16) out<<sol16[count];
	else if(M == 32) out<<sol32[count];
	else if(M == 64) out<<sol64[count];
	
	in.close();
	out.close();
	return 0;
}
