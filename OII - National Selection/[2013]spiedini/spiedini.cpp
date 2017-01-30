 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
int solve(int N, int K, int* S) {
	int sol = 0;
	int c_dx = 0, c_sx = 0, f_dx = 0, f_sx = 0, p_sx = 0, p_dx = 0;
	for(int i = 0; i < N; i++) {
		if(S[i] == 0) f_dx++;
		else c_dx += S[i];
	}
	while(p_sx < N) {
		while(p_dx < N && c_sx+c_dx > K) {
			if(S[p_dx] == 0) f_dx--;
			else c_dx -= S[p_dx];
			p_dx++;
		}
		
		if(p_dx == N && c_sx+c_dx > K) break;
		
		if(p_sx <= p_dx && f_sx+f_dx > sol) sol = f_sx+f_dx;
		
		if(S[p_sx] == 0) f_sx++;
		else c_sx += S[p_sx];
		p_sx++;
	}
	return sol;
}
/*
#include <fstream>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N, K;
	int S[100000];
	in>>N>>K;
	for(int i = 0; i < N; i++) {
		in>>S[i];
	}
	
	out<<solve(N, K, S);
	
	in.close();
	out.close();
	return 0;
}
*/