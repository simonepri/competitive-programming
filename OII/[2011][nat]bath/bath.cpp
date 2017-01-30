 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>

#include <algorithm>
#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int P, N;
	in>>P;
	for(int i = 0; i < P; i++) {
		in>>N;
		vector<int> money(N);
		for(int i = 0; i < N; i++) {
			in>>money[i];
		}
		sort(money.begin(), money.end());
		
		int sol = 0, curr = 1;
		for(int i = 0; i < N; i++) {
			if(money[i] <= curr) {
				sol += money[i];
				curr = sol +1;
			}
			else break;
		}
		out<<curr<<endl;
	}
	in.close();
	out.close();
	return 0;
}
