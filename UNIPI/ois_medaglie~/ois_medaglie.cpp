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
	ifstream fin(FILE_INPUT);
	ofstream fout(FILE_OUTPUT);

	if(!fin || !fout) return 1;

	int N, M, A, B;
	fin>>N>>M;
	vector< vector<int> > G(N);
	for(int i = 0; i < M; i++) {
		fin>>A>>B;
		G[A].push_back(B);
		G[B].push_back(A);
	}

	fout<<""<<endl;

	fin.close();
	fout.close();
	return 0;
}
