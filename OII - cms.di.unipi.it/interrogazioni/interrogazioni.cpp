 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <limits>
#include <set>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define ui unsigned int

int main()
{
	ifstream fin(FILE_INPUT);
	ofstream fout(FILE_OUTPUT);

	if(!fin || !fout) return 1;

	multiset<ui> Q;
    vector<ui> D;
	ui N, K, read, sum, maxsub = numeric_limits<ui>::max();

	fin>>N>>K;

    D.reserve(N-1);

	if(K == 1) maxsub = 0;
	else {
        for(ui i = 0; i < N; i++) {
            fin>>read;
            Q.insert(read);
        }

        for(multiset<ui>::iterator it = Q.begin(); it != prev(Q.end()); it++) {
            D.push_back(*next(it) - *it);
        }

        sum = 0;
        for(ui j = 0; j < K-1; j++) sum+=D[j];
        maxsub = sum;
        for(ui i = 1; i < N-K; i++) {
            sum+=-D[i-1]+D[i+K-2];
            if(sum < maxsub) maxsub = sum;
        }
	}
	fout<<maxsub<<endl;

	fin.close();
	fout.close();
	return 0;
}
