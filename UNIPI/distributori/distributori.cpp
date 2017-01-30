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
	ifstream fin(FILE_INPUT);
	ofstream fout(FILE_OUTPUT);

	if(!fin || !fout) return 1;

	int N, M, K, p[2], pos = 0, cnt = 0;
	fin>>N>>M>>K;

    fin>>p[0];
    for(int i = 1; i < N; i++) {
        fin>>p[i%2];
        if(p[i%2]-pos < M) continue;
        else if(p[i%2]-pos == M) {
            pos = p[i%2];
            cnt++;
        }
        else {
            pos = p[(i-1)%2];
            cnt++;
        }
    }
    if(pos+M < K) cnt++;

	fout<<cnt<<endl;

	fin.close();
	fout.close();
	return 0;
}
