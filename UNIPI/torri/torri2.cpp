 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
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
	
	int N, tot = 0, max = 0;
	vector<int> H,C;
	vector<int> solution;
	
	in>>N;
	H.resize(N+1);
	C.resize(N+1);
	solution.resize(N+1);
	
	H[0]=2000;
	C[0]=0;
	solution[0]=0;
	
	for(int i = 1; i <= N; i++) {
		in>>H[i]>>C[i];
		tot += C[i];
		for(int j = i-1; j >= 0; j--) {
			if(H[i] < H[j] && solution[i] < solution[j] + C[i]) solution[i] = solution[j] + C[i];
		}
		if(max < solution[i]) max = solution[i];
	}
	
	out<<tot-max;
	in.close();
	out.close();
	return 0;
}
