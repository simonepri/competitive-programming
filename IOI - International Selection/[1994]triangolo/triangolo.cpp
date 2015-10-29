 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
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
	int N, read, idx_old, idx_now,max = 0;
	vector<int> T[2];
	
	in>>N;
	T[0].resize(N);
	T[1].resize(N);
	
	for(int i = 1; i <= N; i++) {
		idx_now = (i % 2);
		idx_old = ((i + 1) % 2);
		for(int j = 0; j < i; j++) {
			in>>read;
			if(j-1 >= 0 && j < i-1) { //si sx e si dx
				T[idx_now][j] = (T[idx_old][j-1] > T[idx_old][j] ? T[idx_old][j-1] : T[idx_old][j]) + read;
			}
			else if(j-1 >= 0) { //si sx
				T[idx_now][j] = T[idx_old][j-1] + read;
			}
			else if(j < i-1) {//si sdx
				T[idx_now][j] = T[idx_old][j] + read;
			}
			else { //no dx e no sx
				T[idx_now][j] = read;
			}
			if(i == N && T[idx_now][j] > max) max = T[idx_now][j];
			//cout<<T[idx_now][j]<<" ";
		}
		//cout<<endl;
	}
	
	out<<max;
	in.close();
	out.close();
	return 0;
}
