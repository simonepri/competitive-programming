 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define ui unsigned int

int main()
{
	ifstream fin(FILE_INPUT);
	ofstream fout(FILE_OUTPUT);

	if(!fin || !fout) return 1;

	vector<ui> D;
	ui N, K, read, sum, maxsub = numeric_limits<ui>::max();

	fin>>N>>K;
    D.reserve(N-1);

	if(K == 1) maxsub = 0;
	else {
        for(ui i = 0; i < N; i++) {
            fin>>read;
            D.push_back(read);
        }
        sort(D.begin(), D.end());
        maxsub = D[K-1]-D[0];
		for(int i = 1; K-1+i < N; i++) {
			sum = D[K-1+i] - D[i];
			if(sum < maxsub) maxsub = sum;
		}
	}
	fout<<maxsub<<endl;

	fin.close();
	fout.close();
	return 0;
}
