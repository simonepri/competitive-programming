 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <algorithm>
#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

long long solve(int N, int* M, int* P) {
	long long somma = 0;
	vector<int> D(N);
	for(int i = 0; i < N; i++) {
		D[i] = M[i] - P[i];
		somma += M[i] + P[i];
	}
	nth_element(D.begin(), D.begin()+N/2, D.end());
	for(int i = 0; i < N/2; i++) somma += -D[i] + D[N/2+i];
	return somma/2;
}
/*
#include <fstream>

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N,M[5000],P[5000];
	in>>N;
	for(int i = 0; i < N; i++) {
		in>>M[i]>>P[i];
	}
	out<<solve(N, M, P);
	
	in.close();
	out.close();
	return 0;
}*/
