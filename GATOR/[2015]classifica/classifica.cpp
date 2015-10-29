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

int main()
{
	ifstream fin(FILE_INPUT);
	ofstream fout(FILE_OUTPUT);

	if(!fin || !fout) return 1;

	int N , g1, g2, s1, s2, max_g = 0, max_s = 0;
	fin>>N;
	vector<int> S(N+1);
	while(!fin.eof()) {
		for(int i = 0; i < N; i++) {
			if(fin>>s1>>s2>>g1>>g2) {
                if(g1 > g2) S[s1]+=3;
                else if(g2 > g1) S[s2]+=3;
                else {S[s1]++;S[s2]++;}
			}
		}
	}
	for(int s = 1; s <= N; s++) {
        if(S[s] > max_g || S[s] == max_g && s < max_s) {
            max_s = s;
            max_g = S[s];
        }
    }
	fout<<max_s<<" "<<max_g<<endl;
	fin.close();
	fout.close();
	return 0;
}
