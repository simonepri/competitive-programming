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

int abs(int x) {
	return x >= 0 ? x : -x;
}

int d(int B, vector<int> &c1, vector<int> &c2) {
	int dist = 0;
	for(int i = 0; i < B; i++) dist += abs(c2[i] - c1[i]);
	return dist;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int B, N, D, M;
	in>>B>>N>>D>>M;
	
	vector< vector<int> > Point(N);
	
	for(int i = 0; i < N; i++) {
		Point[i].resize(B);
		for(int j = 0; j < B; j++) {
			in>>Point[i][j];
		}
	}
	
	int count = 0;
	for(int i = 0; i < N-1; i++) {
		for(int j = i+1; j < N; j++) {
			if(d(B, Point[i], Point[j]) <= D) count++;
		}
	}
	
	out<<count;
	
	in.close();
	out.close();
	return 0;
}
