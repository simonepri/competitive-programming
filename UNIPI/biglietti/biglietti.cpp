 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>
#include <iostream>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N

int main()
{
	ifstream fin(FILE_INPUT);
	ofstream fout(FILE_OUTPUT);

	if(!fin || !fout) return 1;

	int N, A, M, B, ans;
	fin>>N>>M>>A>>B;

	if(A*M < B || A*N < B) {
		ans = A*N;
	}
	else {
		ans = (N/M)*B;
		int rest = (N%M)*A;
		ans += rest < B ? rest : B;
	}

	fout<<ans<<endl;
	fin.close();
	fout.close();
	return 0;
}
