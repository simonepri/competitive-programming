 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>
#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

typedef unsigned int ui;

int main()
{
	ifstream fin(FILE_INPUT);
	ofstream fout(FILE_OUTPUT);

	if(!fin || !fout) return 1;

	ui N, K;
	fin>>N>>K;
	vector<ui> B(N);
	for(ui i = 0; i < N; i++) fin>>B[i];

	for(ui i = 0; i < N-K; i++) {
        ui best = B[i];
	    if(best > 0 && K > 0) {
            ui index = 0;
            for(ui j = 1; j <= K; j++) {
                if(B[i+j] < best) {
                    best = B[i+j];
                    index = j;
                    if(best == 0) break;
                }
            }
            K -= index;
            i += index;
	    }
	    fout<<best<<" ";
	}
	fin.close();
	fout.close();
	return 0;
}
